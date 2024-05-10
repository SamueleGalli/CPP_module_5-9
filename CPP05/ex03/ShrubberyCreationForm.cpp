#include "ShrubberyCreationForm.hpp"

//constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("ShrubberyCreationForm")
{
}

//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), target(copy.target)
{
}

//target for ShrubberyCreationForm
ShrubberyCreationForm::ShrubberyCreationForm(char const *target) : AForm(target, 137, 72), target(target)
{
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
    if (executor.getGrade() > AForm::getGradeToSign())
    {
        std::cout << "Error: invalid grade to sign" << std::endl;
        return ;
    }
    else if (executor.getGrade() > AForm::getGradeToExecute())
    {
        std::cout << "Error: invalid grade to execute" << std::endl;
        return ;
    }
    std::string filename = (std::string)this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << "    *" << std::endl;
        file << "   ***" << std::endl;
        file << "  *****" << std::endl;
        file << " *******" << std::endl;
        file << "   ***" << std::endl;
        file << std::endl;
        file << "   |" << std::endl;
        file << "  /|\\" << std::endl;
        file << " / | \\" << std::endl;
        file << "   |" << std::endl;
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