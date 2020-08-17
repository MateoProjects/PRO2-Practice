#include "Parcrom.hh"


Parcrom::Parcrom() {}

Parcrom::Parcrom(const Parcrom & p) {
    crom = p.crom;
}

void Parcrom::llegir_crom(int m) {
    vector <char> v1(m*2);
    for(int i = 0; i < v1.size(); ++i) cin >> v1[i];
    crom = v1;
}


void Parcrom::escriure_parcrom () const{
    cout << "  " ;
    for(int i = 0; i < crom.size() / 2; ++i) cout << crom[i];
    cout << endl;
    cout << "  " ;
    for(int i = crom.size()/2; i < crom.size(); ++i) cout <<crom[i];
    cout << endl;
    
}

void Parcrom::interseccio_tret(Parcrom & p1 , const Parcrom & p2) {
    int tam = p1.crom.size() / 2;
    crom = p1.crom;
    for(int i = 0; i < tam; ++i) {
        if(p1.crom[i] != p2.crom[i] or p1.crom[i + tam] != p2.crom[i + tam]) {
            crom[i] = '-';
            crom[i + tam] = '-';
        }
    }
}

