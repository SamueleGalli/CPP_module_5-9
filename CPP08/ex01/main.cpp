#include "Span.hpp"
#include <ctime>
int main()
{
    //a big test wit 10000 numbers
    srand(time(NULL));
    Span sp(10000);
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(std::rand() % 1000000);
    }
    std::cout << "\n------------------------------------\n\n\n\n\n" << std::endl;
    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    /*Span sp = Span(5);
    std::cout << "creazione span" << std::endl;
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(199);
    std::cout << "adding numbers" << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << "shortest span" << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "longest span" << std::endl;*/
    return 0;
}