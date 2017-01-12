/*
 *  Classe pila: fornisce l'interfaccia standard per usare
 *               una pila 
 *
 *      Autore:  Riccardo Monterisi  http://riccardomonterisi.tk/
 */


 
#include <iostream>
#include "box.h"

using namespace std;
 
class pila
{
    public:
      
    	//--metodi pubblici
    	pila();
    	~pila();
    
    	bool pilaVuota();
    	int leggiPila();
    	void inPila(int);
    	void fuoriPila() ;
    	void stampaPila();
    
    private:	
          
    	Box* TESTA;  // puntatore al primo elemento della pila
   
};

//-----------------realizzazione metodi nel file pila.cpp
 
