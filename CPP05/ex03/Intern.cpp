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
AForm   *Intern::makeForm(std::string name_form, std::string target)
{
    std::string FormB[] = {std::string("shrubbery sreation"), std::string("robotomy request"), std::string("presidential pardon")}; 
    AForm   *Form[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), PresidentialPardonForm(target)};
    for (int i = 0; i < 3; i++)
    {
        if (name_form == FormB[i])
        {
            std::cout << "Intern creates " << FormB[i] << std::endl;
            return (Form[i]);
        }
    }
    std::cout << "Error :Intern cannot create " << name_form << std::endl;
}


//destructor
Intern::~Intern()
{
}