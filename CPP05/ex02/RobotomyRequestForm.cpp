#include "RobotomyRequestForm.hpp"

//constructor
RobotomyRequestForm::RobotomyRequestForm() : Form("Default", 72, 45)
{
}

//copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
    if (this != &copy)
        *this = copy;
}

//robotomizing
void    RobotomyRequestForm::execute(std::string target)
{
    std::cout << "DRILLING NOISES" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " robotomization failed" << std::endl;
}

//copy assignment operator
RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm const &rrf)
{
    if (this != &rrf)
    {
        AForm::operator=(rrf);
    }
    return (*this);
}

// destructor
~RobotomyRequestForm::RobotomyRequestForm()
{
}