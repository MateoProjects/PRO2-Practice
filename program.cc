#include "Cjt_individus.hh"
#include "Cjt_trets.hh"


/** @file program.cc
    @brief Programa principal para el ejercicio <em>Aplicació per un laboratori de biologia</em>.
*/



int main (){
    Cjt_trets trets;
    Cjt_individus inv;
    string instruccio;
    cin >> instruccio;
    int n , m;
    while(instruccio != "fi") {
        
        
        if(instruccio == "experiment") {
            trets.trets_inici();
            cin >> n >> m;
            inv = Cjt_individus(n);
            cout << instruccio << " " << n << " " << m << endl;
            inv.llegir_individus(n , m);

        }
        
        
        else if(instruccio == "afegir") {
            /* entra nom tret i enter 1 <= id <= n */
            /* si ja te aquest tret s'escriu error si no se li afageix */
            string a;
            cin >> a >> n;
            cout << instruccio << " " << a << " " << n << endl;
            if(inv.consultar_individus(a,n)) cout << "  error" << endl;
            else {
                inv.afegir_tret(a , n);
                Individu i = inv.agafar_individu(n);
                trets.afegir_tret(a, i , n);
            }
        }


        else if(instruccio == "treure") {
            /* entra nom tret i enter 1 <= id <= n */
            string a;
            cin >> a >> n;
            cout << instruccio << " " << a << " " << n << endl;
            if(not inv.consultar_individus(a,n)) cout << "  error" << endl;
            else {
                inv.esborrar_tret(a,n);
                trets.esborrar_tret(n,a, inv);
            }
        }

        else if(instruccio == "consulta_tret") {
            string a;
            cin >> a;
            cout << instruccio << " " << a << endl;
            if(not trets.consultar_tret(a)) cout <<"  error" << endl;
            else {
                cout << "  " << a << endl;
                trets.escriure(a);
            }
        }

        else if(instruccio == "consulta_individu") {
            int num;
            cin >> num;
            cout <<instruccio << " " << num << endl;
            inv.escriure_individu(num);
        }


        else if(instruccio == "distribucio_tret") {
            string a;
            cin >> a;
            cout << instruccio << " " << a << endl;
            if(not trets.consultar_tret(a)) cout << "  error" << endl;
            else {
                inv.distribucio(a);
                cout << endl;
            }
        }

        cin >> instruccio;
    }
    
    cout <<instruccio << endl;

}
