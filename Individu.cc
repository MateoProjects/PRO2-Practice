#include "Individu.hh"



Individu::Individu(){}

bool Individu::consultar_tret (const string & a ) const{
    
    set<string>::const_iterator it = trets.find(a);
    if(it != trets.end()) return true;
    else return false;
}


void Individu::afegir_tret (const string & a){
    trets.insert(a);
    
}


void Individu::esborrar_tret(const string & a){
    set<string>::iterator it = trets.find(a);
    trets.erase(it);
    
}

Parcrom Individu:: cromosomes () const {
    return p;
}


void Individu::llegir_individu(int m){
    p.llegir_crom(m);
    
} 


void Individu::escriure_individu() const {
    p.escriure_parcrom();
    set<string>::const_iterator it = trets.begin();
    while(it != trets.end()) {
        cout << "  "<< *it << endl;
        ++it;
    }
}


