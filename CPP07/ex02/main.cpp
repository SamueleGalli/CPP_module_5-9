#include "Array.hpp"

int main() {
    // Costruzione di un array vuoto
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Costruzione di un array con 5 elementi inizializzati a 0
    Array<int> arrayWithSize(5);
    std::cout << "Array with size 5 size: " << arrayWithSize.size() << std::endl;

    // Accesso agli elementi dell'array e verifica del lancio di un'eccezione per un indice fuori dai limiti
    try {
        arrayWithSize[5];
        //arrayWithSize[6];
        //arrayWithSize[-1]; // Provoca un'eccezione per un indice fuori dai limiti
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
