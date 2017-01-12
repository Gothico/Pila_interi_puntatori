/*
 * Classe Box: contiene l'unità essenziale della pila con puntatori
 *               ossia l'elemento di tipo int e il puntatore al 
 *               prossimo elemento della pila.
 *
 * Autore:   Riccardo Monterisi  http://riccardomonterisi.tk/
 */

class Box
{
	public:
		int elemento;
		//succ è un puntatore di tipo Box e il suo compito è quello di
		//indicare l'elemento  inserito successivamente nella pila 
		// se non ci sono elementi impilati successivamente varrà NULL
		Box* succ;
};


 
