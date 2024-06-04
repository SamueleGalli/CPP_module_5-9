#include "PmergeMe.hpp"
//constructor
Pmergeme::Pmergeme()
{
}

Pmergeme::Pmergeme(const Pmergeme &pmg)
{
    if (this != &pmg)
        *this = pmg;
}

//assignment operetor
Pmergeme    &Pmergeme::operator=(const Pmergeme &pmg)
{
    if (this != &pmg)
        *this = pmg;
    return (*this);
}

//methods

int check_error(char **v, int c)
{
    if (c > 2)
    {
        for (int i = 1; i < c; i++)
        {
            if (std::atoi(v[i]) < 0)
            {
                std::cout << "Error not positive number" << std::endl;
                return (1);
            }
            for (int j = i + 1; j < c; j++)
            {
                if (std::strcmp(v[i], v[j]) == 0)
                {
                    std::cout << "Error: duplicate number" << std::endl;
                    return (1);
                }
            }
            for (int j = 0; v[i][j] != '\0' && v[j] != 0; j++)
            {
                if (std::isdigit(v[i][j]) == 0)
                {
                    std::cout << "Error: invalid number" << std::endl;
                    return (1);
                }
            }
        }
        return (0);
    }
    return (1);
}

// valori disapri tipo 3 5 9 7 4 ma anche pari duplica valore e cancella altri
template <typename T>
void    insertionsort(T &vectoring, int start, int end)
{
    // Itero dall'inizio (start + 1) fino alla fine (end)
    for (int i = start + 1; i <= end; ++i)
    {
        // Ottengo l'elemento corrente
        char *key = vectoring[i];
        int j = i - 1;

        // Ciclo finché non raggiungo l'inizio dell'array o trovo un elemento minore di key
        while (j >= start && std::atoi(vectoring[j]) > std::atoi(key))
        {
            // Sposto gli elementi maggiori di key a destra
            vectoring[j + 1] = vectoring[j];
            --j;
        }
        // Inserisco key nella sua posizione corretta
        vectoring[j + 1] = key;
    }
}

//indice inizio vettore (start)
//indice fine vettore (end)
//indice del mezzo della porzione (middle)
template <typename T>
void    merge(T &vectoring, int start, int middle, int end)
{

    int num1 = middle - start + 1;
    int num2 = end - middle;

    //inizializzo due sottovettori L e R
    T L(num1), R(num2);
    //copio gli elementi del sottovettore in L verso la meta
    for (int i = 0; i < num1; i++)
        L[i] = vectoring[start + i];
    //copio gli elementi del sottovettore in R verso la fine
    for (int j = 0; j < num2; j++)
        R[j] = vectoring[middle + 1 + j];
    int i = 0, j = 0, k = start;
    while (i < num1 && j < num2)
    {
        if (R[0] == 0)
            break ;
        //se il primo elemento di L è minore o uguale al primo elemento di R
        if (std::atoi(L[i]) <= std::atoi(R[j]))
        {
            //copio l'elemento di sinistra nel vettore che sto creando
            vectoring[k++] = L[i++];
        }
        else
        {
            //copio l'elemento di destra nel vettore che sto creando
            vectoring[k++] = R[j++];
        }
    }
    //copio i valori residui
    while (i < num1)
        vectoring[k++] = L[i++];
    while (j < num2)
        vectoring[k++] = R[j++];
}

//indice inizio sottovettore (start)
//indice fine sottovettore (end)
template <typename T>
void    mergesortinsert(T &vectoring, int start, int end)
{
    //se sono a 2 elementi li ordino
    if ((end - start) + 1 <= 10)
        insertionsort(vectoring, start, end);
    else
    {
        //se inizio e diverso da fine
        if (start < end)
        {
            int middle = start + (end - start) / 2;
            //eseguo algoritmo tra inizio e meta vettore
            mergesortinsert(vectoring, start, middle);
            //eseguo algoritmo tra meta + 1 e fine vettore
            mergesortinsert(vectoring, middle + 1, end);
            //fondo
            merge(vectoring, start, middle, end);
        }
    }
}

void resize_vector(std::vector<char *> &vectoring, int c)
{
    std::vector<char *> temp(c - 1);
    for (int i = 1; i < c; ++i)
        temp[i - 1] = vectoring[i];
    for (int i = 0; i < c - 1; ++i)
        vectoring[i] = temp[i];
    vectoring.resize(c - 1);
}

void resize_deque(std::deque<char *> &dequeing, int c)
{
    std::deque<char *> temp(c - 1);
    for (int i = 1; i < c; ++i)
        temp[i - 1] = dequeing[i];
    for (int i = 0; i < c - 1; ++i)
        dequeing[i] = temp[i];
    dequeing.resize(c - 1);
}

void    sorting(char **v, int c)
{
    std::vector<char *> vectoring(v, v + c);
    std::deque<char *> dequeing(v, v + c);
    resize_vector(vectoring, c);
    resize_deque(dequeing, c);

    //prendo il tempo di ora
    std::clock_t start_vector = std::clock();
    mergesortinsert(vectoring, 0, vectoring.size() - 1);
    double end_vector = std::clock();
    //converto in double per la precisione e ottengo la differenza tra tempo di ora con quello di inizo e lo divido per i clock della CPU a deque e vector 
    double elapsed_vector = (end_vector - start_vector) / CLOCKS_PER_SEC * 100.0;
  
    std::clock_t start_deque = std::clock();
    mergesortinsert(dequeing, 0, dequeing.size() - 1);
    double end_deque = std::clock();
    double elapsed_deque = (end_deque- start_deque) / CLOCKS_PER_SEC * 100.0;
    
    std::cout << "After:  ";
    for (std::vector<char *>::iterator it = vectoring.begin(); it != vectoring.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
  
    std::cout << "Time to process a range of " << c - 1 << " elements with std::vector : " << elapsed_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << c - 1 << " elements with std::deque : " << elapsed_deque << " us" << std::endl;
}

void    Pmergeme::shorter(char **v, int c)
{
    if (check_error(v, c) == 1)
        return ;
    std::cout << "Before: ";
    for (int i = 1; i < c; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    sorting(v, c);
}

//destructor
Pmergeme::~Pmergeme()
{
}