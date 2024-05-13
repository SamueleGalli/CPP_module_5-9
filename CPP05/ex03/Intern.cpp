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
AForm   *Intern::makeForm(std::string name_form, char const *target)
{
    std::string FormB[] = {std::string("shrubbery creation"), std::string("robotomy request"), std::string("presidential pardon")}; 
    AForm   *Form[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    for (int i = 0; i < 3; i++)
    {
        if (name_form == FormB[i])
        {
            AForm *singleForm = Form[i];
            std::cout << "Intern creates " << FormB[i] << std::endl;
            for (int i = 0; i < 3; i++)
                delete Form[i];
            return (singleForm);
        }
    }
    std::cout << "Error: Intern cannot create " << name_form << std::endl;
    for (int i = 0; i < 3; i++)
        delete Form[i];
    return (NULL);
}

void    Intern::execute(Bureaucrat const & executor) const
{
    (void)executor;
}

//destructor
Intern::~Intern()
{
}