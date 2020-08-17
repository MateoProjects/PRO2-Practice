#include "Cjt_individus.hh"

Cjt_individus::Cjt_individus() {}


Cjt_individus::Cjt_individus(int n){
    cjt = vector <Individu> (n);
}


bool Cjt_individus::consultar_individus(const string & a , int n){ 
    return cjt[n - 1].consultar_tret(a);
    
}

Individu Cjt_individus::agafar_individu(int n) {
    return cjt[n -1];
}

void Cjt_individus::afegir_tret (const string & a , int n) {
    cjt[n - 1].afegir_tret(a);
    
}

void Cjt_individus::esborrar_tret(const string & a , int n) {
    cjt[n - 1].esborrar_tret(a);
    
}

BinTree <int> Cjt_individus::arbre_nou(const BinTree <int> & a , const string & tret ) {
    BinTree <int> Tree;
    if(a.left().empty() and a.right().empty()) {
        if(consultar_individus(tret , a.value())) Tree = BinTree <int> (a.value());
        else Tree = BinTree<int> ();
    }
    else {
        BinTree <int> ae;
        BinTree <int> ad;
        ae = arbre_nou(a.left(), tret);
        ad = arbre_nou(a.right(),tret);
        if(ae.empty() and ad.empty()) {
            // dos fills buits 
            if(consultar_individus(tret, a.value())) Tree = BinTree<int> (a.value()); // retorno el node
            else Tree = ae; // retorno arbre buit
        }
        else if(consultar_individus(tret, a.value())) Tree = BinTree<int> (a.value(),ae , ad);
        else {
            // arbre amb fills no buits i no te el tret
            Tree = BinTree <int> (-1*a.value(), ae ,ad);
        }
    }
    return Tree;
}

void Cjt_individus::escriure_individu(int n) {
    cjt[n -1].escriure_individu();
    
}

void Cjt_individus::llegir_individus(int n ,int m){
    read_bintree_int(arbre,0);
    for(int i = 0; i < n; ++i) {
        Individu ind;
        ind.llegir_individu(m);
        cjt[i] = ind;
    }
}

void Cjt_individus:: read_bintree_int(BinTree<int>& a,int marca){
    int x;
    cin >> x;
    if (x!=marca){
        BinTree<int> l;
        read_bintree_int(l,marca);
        BinTree<int> r;
        read_bintree_int(r,marca);
        a=BinTree<int>(x,l,r);
    }
}

void Cjt_individus::write_bintree_int(const BinTree<int> &a){
	if (not a.empty()) {
		int x = a.value();
		write_bintree_int(a.left()); 
		cout << " " << x;
		write_bintree_int(a.right());
  }
}

void Cjt_individus::distribucio (const string & s ) {
    BinTree<int> alpha;
    alpha = arbre_nou(arbre, s);
    cout << " "; 
    write_bintree_int(alpha);
}


    
 



