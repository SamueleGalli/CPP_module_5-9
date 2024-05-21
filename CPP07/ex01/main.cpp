#include "iter.hpp"

void printSomething(int const &a) {
    std::cout << "mi piace questa funzione con " << a << std::endl;
}

int main()
{
    //creamo un array di interi
    int arr[] = {1, 2, 3, 4, 5};
    //calcolamo la lunghezza dell'array
    size_t length = sizeof(arr) / sizeof(arr[0]);;
    //chiamiamo la funzione iter che prende come argomenti l'array, la lunghezza dell'array e la funzione printSomething
    iter(arr, length, printSomething);
    return 0;
}
