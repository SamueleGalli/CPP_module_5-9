#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class   RobotomyRequestForm : public AForm
{
    public:
    //constructor
    RobotomyRequestForm();

    //robotomizing
    virtual void    execute(Bureaucrat const & executor) const;
    
    //copy constructor
    RobotomyRequestForm(RobotomyRequestForm const &copy);

    //copy assignment operator
    RobotomyRequestForm   &operator=(RobotomyRequestForm const &rrf);

    //destructor
    ~RobotomyRequestForm();
};

#endif