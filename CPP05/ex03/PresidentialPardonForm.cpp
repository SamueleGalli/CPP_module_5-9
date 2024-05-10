#include "PresidentialPardonForm.hpp"

//constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("PresidentialPardonForm")
{
}

//copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), target(copy.target)
{
}

//target for PresidentialPardonForm
PresidentialPardonForm::PresidentialPardonForm(char const *target) : AForm(target, 25, 5), target(target)
{
}

//copy assignment operator
PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
    (void)ppf;
    return (*this);
}

//execute form
//pardoning by Zaphof Beeblebrox
void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
    std::cout << this->target << " \"has been pardoned by Zaphod Beeblebrox\"" << std::endl;
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}