template <typename T>
//indica che stiamo creando un array template Array<T>
Array<T>::Array()
{
    data = 0;
    dimension = 0;
}

//create an array with 'n' elements
template <typename T>
Array<T>::Array(unsigned int n)
{
    data = new T[n];
    dimension = n;
}

//copy constructor that mustn't affect other array than that specified
template <typename T>
Array<T>::Array(Array const &copy)
{
    //copio lunghezza array
    dimension = copy.dimension;
    //se la lunghezza e maggiore di 0 ovvero valida copio l'array
    if (dimension > 0)
    {
        //creo una arrray con la dimensione dell'array da copiare utilizzando il tipo dell'utente al posto di T
        data = new T[dimension];
        //copio l'array 
        for (unsigned int i = 0; i < dimension; i++)
            data[i] = copy.data[i];
    }
    else
    {
        //altrimenti l'array e vuoto
        data = 0;
    }
}

//copy assignment operator that mustn't affect other array than that specified
template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
    if (this != &copy)
    {
        //distruggo l'array precedente
        delete[] data;
        //copio lunghezza altro array
        dimension = copy.dimension;
        //se la lunghezza e maggiore di 0 ovvero valida copio l'array
        if (dimension > 0)
        {
            //creo una arrray con la dimensione dell'array da copiare
            data = new T[dimension];
            //copio l'array 
            for (unsigned int i = 0; i < dimension; i++)
                data[i] = copy.data[i];
        }
        else
        {
            //altrimenti l'array e vuoto
            data = 0;
        }
    }
    return *this;
}

//accedere agli elementi con [] non const(modificabile)
template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= dimension) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

//accedere agli elementi con [] const(non modificabile)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= dimension) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return dimension;
}

//distruttore(cancello array)
template <typename T>
Array<T>::~Array()
{
    delete[] data;
}