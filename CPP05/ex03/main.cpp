#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{
  Intern someRandomIntern;
  AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    rrf = someRandomIntern.makeForm("paperino", "Bender");
}
/*
int main() {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
    if (rrf)
    {
        rrf->beSigned(Bureaucrat("John", 4));
        rrf->execute(Bureaucrat("John", 4));
        delete rrf;
    }
    rrf = someRandomIntern.makeForm("Shrubbery Creation", "Bender");
    if (rrf)
    {
        rrf->beSigned(Bureaucrat("John", 4));
        rrf->execute(Bureaucrat("John", 4));
        delete rrf;
    }
    rrf = someRandomIntern.makeForm("Presidential Pardon", "Bender");
    if (rrf)
    {
        rrf->beSigned(Bureaucrat("John", 4));
        rrf->execute(Bureaucrat("John", 4));
        delete rrf;
    }
    rrf = someRandomIntern.makeForm("paperino", "Bender");
    if (rrf)
    {
        rrf->beSigned(Bureaucrat("John", 4));
        rrf->execute(Bureaucrat("John", 4));
        delete rrf;
    }
    else
        std::cout << "Form creation failed, rrf is NULL." << std::endl;
    return 0;
}
*/