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

template <typename T>
void    insertionsort(T &vectoring, int left, int right)
{
   for (int i = left + 1; i <= right; ++i) {
        char *key = vectoring[i];
        int j = i - 1;

        while (j >= left && strcmp(vectoring[j], key) > 0) {
            vectoring[j + 1] = vectoring[j];
            --j;
        }
        vectoring[j + 1] = key;
    }
}

//indice inizio vettore (left)
//indice fine vettore (right)
//indice del mezzo della porzione (middle)
template <typename T>
void    merge(T &vectoring, int left, int middle, int right)
{

    int num1 = middle - left + 1;
    int num2 = right - middle;
    //inizializzo due sottovettori L e R
    std::vector<char *> L(num1), R(num2);

    //copio gli elementi del sottovettore in L verso la meta
    for (int i = 0; i < num1; i++)
        L[i] = vectoring[left + i];
    //copio gli elementi del sottovettore in R verso la fine
    for (int j = 0; j < num2; j++)
        R[j] = vectoring[middle + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < num1 && j < num2)
    {
        //se il primo elemento di L è minore o uguale al primo elemento di R
        if (strcmp(L[i], R[j]) <= 0)
        {
            //copio l'elemento di sinistra nel vettore che sto creando
            vectoring[k] = L[i];
            i++;
        }
        else
        {
            //copio l'elemento di destra nel vettore che sto creando
            vectoring[k] = R[j];
            j++;
        }
        k++;
    }
    //copio i valori residui
    while (i < num1)
        vectoring[k++] = L[i++];
    while (j < num2)
        vectoring[k++] = R[j++];
}

//indice inizio sottovettore (left)
//indice fine sottovettore (right)
template <typename T>
void    mergesortinsert(T &vectoring, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        //eseguo algoritmo tra inizio e meta vettore
        mergesortinsert(vectoring, left, middle);
        //eseguo algoritmo tra meta + 1 e fine vettore
        mergesortinsert(vectoring, middle + 1, right);
        //fondo
        merge(vectoring, left, middle, right);
    }
    else
        insertionsort(vectoring, left, right);
}

long long    get_time(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (static_cast<long long>(ts.tv_sec) * 1000LL + static_cast<long long>(ts.tv_nsec) / 1000000LL);
}

long long getCurrentTimeMillis() {
    time_t currentTime;
    struct tm *timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    return (timeInfo->tm_hour * 3600000) + (timeInfo->tm_min * 60000) + (timeInfo->tm_sec * 1000);
}

void    sorting(char **v, int c)
{
    //parto da 1 cosi da evitare il programma
    //evito la fine dell'array con v[c - 1]
    std::vector<char *> vectoring(v, v + c);
    std::deque<char *> dequeing(v, v + c);


    long long startTime = getCurrentTimeMillis();
    mergesortinsert(vectoring, 0, vectoring.size() - 1);
    long long endTime = getCurrentTimeMillis();
    long long duration_vectoring = endTime - startTime;
    std::cout << "Time to process a range of " << c - 1<< " elements with std::vector :[..] : " << duration_vectoring << " us" << std::endl;

    startTime = getCurrentTimeMillis();
    mergesortinsert(dequeing, 0, dequeing.size() - 1);
    endTime = getCurrentTimeMillis();
    long long duration_dequeing = endTime - startTime;
    std::cout << "Time to process a range of " << c - 1<< " elements with std::deque :[..] : " << duration_dequeing << " us" << std::endl;
    
    
    std::cout << "After:  ";
    int i = 0;
    for (std::vector<char *>::iterator it = vectoring.begin(); it != vectoring.end(); it++)
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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