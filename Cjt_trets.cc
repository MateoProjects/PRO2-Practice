#include "Cjt_trets.hh"

Cjt_trets::Cjt_trets() {}

void Cjt_trets::trets_inici() {
    trets.clear();
}


void Cjt_trets::afegir_tret(const string & a, const Individu & in, int n) {
    
    map <string,tretstr>::iterator it =  trets.find(a);
    if(it != trets.end()) {
        // ja te el map per tant s'ha de recalcular el parcrom i afegir el n al set;
        (*it).second.individus.insert(n);
        (*it).second.p.interseccio_tret((*it).second.p , in.cromosomes());
    }
    else {
        // element no es troba en el map;
        tretstr elem;
        elem.individus.insert(n);
        elem.p = in.cromosomes(); // parcrom de trets = parcrom d'individu
        trets.insert(make_pair(a , elem));
    }
        
    
}


void Cjt_trets::esborrar_tret(int n, string p, Cjt_individus & cjt){
    map<string,tretstr>::iterator it = trets.find(p); // it
    (*it).second.individus.erase(n); // s'ha esborrat l'individu
    if(it->second.individus.empty()) trets.erase(p); // borro la clau
    else {
        //el set no esta buit 
        //toca recalcular tot el parcrom
        set<int>::iterator it2 = (*it).second.individus.begin(); // primera pos del set individus;
        Individu i = cjt.agafar_individu(*it2);
        Parcrom inter = i.cromosomes();
        ++it2;
        while(it2 != (*it).second.individus.end()) {
            inter.interseccio_tret( inter , cjt.agafar_individu(*it2).cromosomes());
            ++it2;
        }
        it->second.p = inter;
    }
    
}


bool Cjt_trets::consultar_tret(const string & p) const  {
    map <string,tretstr>::const_iterator it = trets.find(p);
    if(it != trets.end()) return true;
    else return false;
}



void Cjt_trets::escriure(const string & s) const {
    map <string,tretstr>::const_iterator it = trets.find(s);
    it->second.p.escriure_parcrom();
    set <int>::const_iterator it2 = (*it).second.individus.begin();
    while(it2 != (*it).second.individus.end()) {
        cout << "  " << *it2 << endl;
        ++it2;
    }
}
// funcion consulta_tret


