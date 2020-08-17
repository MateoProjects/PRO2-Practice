/** @file Cjt_individus.hh
    @brief Especificación de la clase Cjt_individus
*/

#ifndef _CJT_INDIVIDUS_HH_
#define _CJT_INDIVIDUS_HH_
#include "Individu.hh"
#ifndef NO_DIAGRAM 
#include "BinTree.hh"
#endif

/** @class Cjt_individus
    @brief Representa una un conjunt d'individus

*/
class Cjt_individus
  {
      
private:
      
    vector<Individu> cjt;
    BinTree<int> arbre;
    
    /** @brief Operació de lectura de l'arbre genealògic
        \pre <em>Esta prepatat pel canal estandard d'entrada una seqüència d'enters que representan l'arbre genealògic dels n individus del conjunt</em>
        \post El conjunt ara conté l'arbre genealògic dels n individus que conté
    */
    
    static void read_bintree_int(BinTree<int>& a, int marca);
    
    /** @brief Operació d'escriptura d'un arbre
        \pre <em>cert</em>
        \post S'ha escrit pel canal standard de sortida el paràmetra implicit. 
    */
    
    static void write_bintree_int(const BinTree<int> &a);
     /** @brief Modificadora de l'arbre
        \pre <em>cert</em>
        \post Retorna un arbre a partir del tret a. 
    */
    
    BinTree <int> arbre_nou(const BinTree <int> & a , const string & tret );


public:

    //Constructoras

    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un conjunt d'individus buit
    */

    Cjt_individus();
    
    

    /** @brief Crea un conjunt de n individus
        \pre <em>cert</em>
        \post El resultat és un conjunt amb n individus buits 
    */


    Cjt_individus(int n);



    // Consultoras

    /** @brief Consultora de trets de l'individu
        \pre <em>cert</em>
        \post El resultat indica si l'individu n té el tret a
    */

   bool consultar_individus(const string & a , int n); // consulta el tret de l'idividu

   
   //Copiadora

    /** @brief Copiadora d'individus
        \pre <em>cert</em>
        \post Retorna l'individu n
    */

    Individu agafar_individu(int n);
    
    //Modificadoras
    
     /** @brief Afageix un tret a l'individu n
        \pre <em>L'individu no te el tret a </em>
        \post S'ha afegit el tret a l'individu n
    */
    
    void afegir_tret (const string & a , int n);
    
    
    /** @brief Esborra el tret de l'individu n
        \pre <em>L'individu te el tret </em>
        \post S'ha esborrat el tret a l'individu n
    */
    
    void esborrar_tret(const string & a , int n);
    
   
    
    
    //lectura i escriptura
    
    /** @brief Operació d'escriptura
        \pre <em>cert</em>
        \post S'ha escrit pel canal estandard l'individu n. 
    */

    void escriure_individu(int n);
    
    /** @brief Operació de lectura
        \pre <em>Estan prepatats pel canal estandard d'entrada un conjunt de n individus de parells de cromosomes de mida m</em>
        \post El conjunt conté ara els individus amb parells de cromosomes llegits pel canal estandard d'entrada
    */
    
    
    void llegir_individus(int n ,int m);
    
    
   

    /** @brief Operació calculadora de l'arbre genealògic que fan que es manifesti el tret
        \pre <em>cert</em>
        \post S'ha calculat i escrit pel canal standard de sortida l'arbre resultant dels individus que contenen aquell tret 
    */

    void distribucio (const string & s);


  };

#endif
