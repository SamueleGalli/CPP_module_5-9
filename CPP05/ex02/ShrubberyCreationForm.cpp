#include "ShrubberyCreationForm.hpp"

//constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 137, 72)
{
}

//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
    *this = copy;
}

//copy assignment operator
ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &scf)
{
    (void)scf;
    return (*this);
}

//create file tree ascii
void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename);
    if (file.is_open())
    {
        std::cout << "    *" << std::endl;
        std::cout << "   ***" << std::endl;
        std::cout << "  *****" << std::endl;
        std::cout << " *******" << std::endl;
        std::cout << "   ***" << std::endl;
        std::cout << std::endl;
        std::cout << "   |" << std::endl;
        std::cout << "  /|\\" << std::endl;
        std::cout << " / | \\" << std::endl;
        std::cout << "   |" << std::endl;
        file.close();
        std::cout << "File created succesfully" << std::endl;
    }
    else
        std::cout << "Error problem rescountered when creating file" << std::endl;
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}