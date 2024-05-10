#include "Intern.hpp"

//constructor
Intern::Intern()
{
}

//copy constructor
Intern::Intern(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
}

//copy assignment operator
Intern  &Intern::operator=(Intern const &I)
{
    (void)I;
    return (*this);
}

//Making Form
AForm   Intern::makeForm(std::string name_form, std::string target)
{
    AForm   *f = 0;
    if (name_form = "robotomy request")
    {
        
    }
}


//destructor
Intern::~Intern()
{
}