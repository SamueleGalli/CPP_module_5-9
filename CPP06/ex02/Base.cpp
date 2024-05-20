#include "Base.hpp"

//virtual destructor
Base::~Base()
{
}

//genera una classe casuale tra a b e c
Base *generate(void)
{
    srand(time(NULL));
    int randomNum = rand() % 3; // generate a number between 0 and 2
    if (randomNum == 0)
    {
        std::cout << "generazione classe A" << std::endl;
        return (new A);
    }
    else if (randomNum == 1)
    {
        std::cout << "generazione classe B" << std::endl;
        return (new B);
    }
    else if (randomNum == 2)
    {
        std::cout << "generazione classe C" << std::endl;
        return (new C);
    }
    return (NULL);
}

//identifica la classe di passata
void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "NULL type" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "type A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "type B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "type C" << std::endl;
    else
        std::cout << "invalid type" << std::endl;
}

void identify(Base& p)
{
    try
    {   
        identify(&p);
    }
    catch(const std::exception& e)
    {
        std::cerr << "invalid type" << e.what() << '\n';
    }
}
