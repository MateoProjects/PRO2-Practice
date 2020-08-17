/** @file Parcrom.hh
    @brief Especificación de la clase Parcrom
*/

#ifndef _PARCROM_HH_
#define _PARCROM_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;


/** @class Parcrom
    @brief Representa un conjunt de parell de cromosomes.

*/

class Parcrom
{

private:

	vector <char> crom; // vector amb valors de cromosoma 

public:
	//Constructoras

    /** @brief Creadora por defecte.
        \pre <em>cert</em>
        \post El resultat és un conjunt de parells de cromosomes
    */

    Parcrom();


    /** @brief Creadora .
        \pre <em>cert</em>
        \post Crea un parell de cromosomes amb una copia de a
    */


    Parcrom(const Parcrom & a );

    //Modificadora
    
    /** @brief Modificadora del paràmetra implicit
        \pre <em>cert</em>
        \post El resultat es la intersecció de p1 i p2 i el resultat el guarda a p1
    */


    void interseccio_tret( Parcrom & p1 , const Parcrom & p2);


    //lectora / escriptora
    
    /** @brief Operació de lectura
        \pre <em>Estan prepatats pel canal estandard d'entrada m parells de cromosomes</em>
        \post El conjunt de cromosomes ara conté els m parells de cromosomes llegits
    */
    
    
    void llegir_crom(int m);
    
     /** @brief Operació d'escriptura
        \pre <em>cert</em>
        \post S'ha escrit pel canal estandard el conjunt de parells de cromosomes. 
    */
    

    void escriure_parcrom()const;




    

};
    



#endif