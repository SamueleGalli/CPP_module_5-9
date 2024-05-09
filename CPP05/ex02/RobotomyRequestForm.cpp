#include "RobotomyRequestForm.hpp"

//constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("RobotomyRequestForm")
{
}

//copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy), target(copy.target)
{
}

//target for PresidentialPardonForm
RobotomyRequestForm::RobotomyRequestForm(char const *target) : AForm(target, 72, 45), target(target)
{
}

//robotomizing
void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
    srand(time(NULL)); //inizzializzatore numeri randomici
    if (rand() % 2 == 0) //controllo se il numero e pari o dispari
        std::cout << this->target << " è stata robotizzata con successo" << std::endl;
    else
        std::cout << this->target << " la robotizzazione è fallita" << std::endl;
}

//copy assignment operator
RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm const &rrf)
{
    (void)rrf;
    return (*this);
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}