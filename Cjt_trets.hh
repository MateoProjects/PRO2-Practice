/** @file Cjt_trets.hh
    @brief Especificación de la clase Cjt_trets
*/

#ifndef _CJT_TRETS_HH_
#define _CJT_TRETS_HH_
#include "Parcrom.hh"
#include "Cjt_individus.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <set>

#endif


/** @class Cjt_trets
    @brief Conté tota l'informació dels trets.

*/

class Cjt_trets
{

private:

    struct tretstr {
            Parcrom p;
            set <int> individus; //numero de individuos que tienen dicho rasgo
    };
/** @brief Representa un Conjunt de trets
 
*/
    map <string, tretstr> trets;


public:
        
    //Constructora
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un conjunt de trets buit
    */
    Cjt_trets();
    
    //Destructora de trets
    
    /** @brief Destructora de trets
        \pre <em>Cert</em>
        \post Conjunt de trets buit. 
    */

    void trets_inici();
    
    //Modificadoras
    
    /** @brief Afageix el tret 'a' a l'individu in
        \pre <em>cert</em>
        \post S'ha afegit al tret el individu in. Si el tret no existia s'ha generat el tret amb el parell de cromosomes de l'individu in del parametre 
    */

    void afegir_tret(const string & a, const Individu & in, int n);
    
     /** @brief Esborra tret
        \pre <em>cert</em>
        \post S'ha esborrat l'individu del tret. Si el tret ja no conté més individus s'ha esborrat del conjunt. 
    */

    void esborrar_tret(int n, string p, Cjt_individus & cjt);
    
    //Consultoras
    
     /** @brief Consultora del conjunt de trets
        \pre <em>cert</em>
        \post Indica si el tret es troba en el conjunt. 
    */
    
    bool consultar_tret(const string & p)const;
    
    //Escritura
    
    /** @brief Operació d'escriptura
        \pre <em>cert</em>
        \post S'ha escrit pel canal estandard el parcrom del tret s i els individus que el tenen. 
    */

    void escriure(const string & s) const;
    
	
};
#endif
