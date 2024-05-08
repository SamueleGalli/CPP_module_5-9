#include "PresidentialPardonForm.hpp"

//constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
}

//copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
    if (this != &copy)
        *this = copy;
}

// target for working directory
PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    this->target = target;
}


//copy assignment operator
PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
    (void)ppf;
    return (*this);
}

//execute form
//pardoning by Zaphof Beeblebrox
void    PresidentialPardonForm::execute(std::string target)
{
    if (AForm.GetGradeToSign() == 25 && AForm.GetGradeToExecute() == 5)
        std::cout << target << " \"has been pardoned by Zaphod Beeblebrox\"" << std::endl;
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}