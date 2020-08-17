/** @file Individu.hh
    @brief Especificació de la clase Individu
*/

#ifndef _INDIVIDU_HH_
#define _INDIVIDU_HH_
#include "Parcrom.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <set>
#endif


/** @class Individu
    @brief Representa un Individu. 

*/
class Individu
{
    
private:    

    Parcrom p;
    set <string> trets;


public:
    
    //Constructora
    
    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un individu
    */

    Individu();
    
    //Consultora
    
    /** @brief Consultora de la clase individu.
        \pre <em>cert</em>
        \post El resultat indica si el parametre implícit conté el tret
    */

    bool consultar_tret (const string & a ) const;
    
    //Modificadores
    
    /** @brief Afegidora de trets
        \pre <em>cert</em>
        \post S'ha afegit el tret al paràmetre implícit
    */

    void afegir_tret (const string & a);
    
    
    /** @brief Esborradora de trets
        \pre <em>cert</em>
        \post S'ha esborrat el tret del paràmetre implícit
    */

    void esborrar_tret(const string & a);
    
    //Copiadora
    
    /** @brief Copiadora del parell de cromosomes.
        \pre <em>cert</em>
        \post Retorna el parell de cromosomes del paràmetre implícit
    */
    
    Parcrom cromosomes() const; // retorna un parell de cromosomes
    

    
    //lectura i escriptura
    
    /** @brief Operació de lectura de l'individu
        \pre <em>Esta prepatat pel canal estandard d'entrada dues seqüències de m gens</em>
        \post L'individu ara conté el parell de cromosomes llegit
    */


    void llegir_individu(int m); 
    
    /** @brief Operació d'escriptura
        \pre <em>cert</em>
        \post S'ha escrit pel canal estandard l'individu n. 
    */

    void escriure_individu() const;
    
    


};
#endif
