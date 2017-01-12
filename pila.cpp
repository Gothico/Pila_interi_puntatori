/*
 *  Implementazione dei metodi della classe pila
 *      Autore: Riccardo Monterisi  http://riccardomonterisi.tk/
 */


#include "pila.h"
#include <iostream>

pila::pila()
/*
 * FUNZIONAMENTO: viene inizializzato TESTA, puntatore al primo
 * 				  elemento della pila
 */
{
   TESTA = (Box*) malloc(sizeof(Box*));
   TESTA->succ = TESTA;	 
}

pila::~pila()
/*
 * FUNZIONAMENTO: distruttore della classe che "elimina" dapprima
 * 				  tutti gli elementi presenti nella pila e poi
 * 				  libera il puntatore TESTA in modo da liberare
 * 				  la memoria e perdere completamente la struttura
 * 				  al termine del suo utilizzo
 */
{
	while (TESTA->succ != TESTA) {
		Box* temp;

	    temp = TESTA->succ;
        if (temp->succ == NULL)
    	   TESTA->succ = TESTA;
        else
        	TESTA->succ = temp->succ;
        
        free(temp);
    }	
 
	free(TESTA);// distruzione del "cursore"
}
 

bool pila::pilaVuota()
/*
* FUNZIONAMENTO: se l'attributo TESTA->succ è proprio uguale a TESTA allora
*                non ci sono elementi all'interno della pila
*/
{
   bool out = false;
   if (TESTA->succ == TESTA)
		out = true;

	return out;    
}

int pila::leggiPila() 
/* 
 * FUNZIONAMENTO: se la pila non è vuota viene restituito
 * 				  l'elemento di testa, altrimenti un basso valore 
 */
{
	int output = -32000;
	if (!(pilaVuota()))
		output =  TESTA->succ->elemento;
    
    return output;
}

 
void pila::inPila(int a)
/*
 * PARAMETRI: a  elemento di tipo intero che rappresenta
 * 			     il valore del nuovo elemento della pila
 * FUNZIONAMENTO: si inserisce una nuova Box che viene puntata
 * 				  da TESTA (testa della pila) e il cui successivo è il
 * 				  precedente elemento puntato da TESTA
 */
{
 // viene creato un Box* che rappresenta il nuovo elemento della pila     
	Box* temp;

	temp = (Box*) malloc(sizeof(Box*)); // istanzio l'elemento
	temp->elemento = a; // gli attribuisco a
	
	//se la pila è vuota allora il  nuovo elemento
	//diverrà la testa della pila
	if (pilaVuota()) {
		temp->succ = NULL;
		TESTA->succ = temp;
	}
	//altrimenti
	else {
         //creo un puntatore Box*
		Box* prov;
		prov = (Box*) malloc(sizeof(Box*)); // lo istanzio

        // gli attribuisco il precedente primo elemento della pila
		prov = TESTA->succ;
 	    
        // il nuovo primo elemento prende come successivo prov 
        // mettendosi in testa alla pila 
		
        temp->succ = prov;
        
        // il puntatore al primo elemento della pila viene aggiornato
	    TESTA->succ = temp;
    }
}
 
void pila::fuoriPila() 
/*
 * FUNZIONAMENTO: se la pila non è vuota si collega TESTA con l'elemento 
 *                successivo alla testa della pila che così ha un elemento in 
 *                meno 
 */
{
	if (!(pilaVuota())) {
        Box* temp;
        //elemento in testa alla pila
	    temp = TESTA->succ;
        if (temp->succ == NULL)
    	   TESTA->succ = TESTA;
        else
       	   TESTA->succ = temp->succ;
        
        free(temp);                    
    }
}

 
void pila::stampaPila()
/*
 * FUNZIONAMENTO: se la pila non è vuota, viene letto, stampato
 * 				  a video e poi rimosso l'elemento di testa, quindi
 * 				  si richiama ricorsivamente l'intero metodo
 */
{
	int elemento;

	if (!(pilaVuota())) {
		elemento = leggiPila();
		fuoriPila();

		cout << " Elemento: " << elemento;
		cout << "\n";
		stampaPila();
		inPila(elemento);
	}
}
