/*
 * Classe Box: contiene l'unit� essenziale della pila con puntatori
 *               ossia l'elemento di tipo int e il puntatore al 
 *               prossimo elemento della pila.
 *
 * Autore:   Riccardo Monterisi  http://riccardomonterisi.tk/
 */

class Box
{
	public:
		int elemento;
		//succ � un puntatore di tipo Box e il suo compito � quello di
		//indicare l'elemento  inserito successivamente nella pila 
		// se non ci sono elementi impilati successivamente varr� NULL
		Box* succ;
};


 
