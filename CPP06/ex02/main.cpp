#include "Base.hpp"

//testing invalid class only
//class Invalid : public Base
//{};

int main() {
    std::cout << "generatoire classe casuale..." << std::endl;
    Base* generatedObject = generate();
    if (generatedObject != 0) {
        identify(generatedObject);
        delete generatedObject;
    }

    std::cout << "identification by pointer" << std::endl;
    A a;
    B b;
    C c;
    //Invalid invalid;
    identify(&a);
    identify(&b);
    identify(&c);
    //identify(&invalid);
    std::cout << "identification by adress" << std::endl;
    identify(c);
    identify(b);
    identify(a);
    identify(NULL);
    //identify(invalid);
    return 0;
}