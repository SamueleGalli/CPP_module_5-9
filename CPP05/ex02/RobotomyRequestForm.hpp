#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class   RobotomyRequestForm : public AForm
{
    private:
        char const *target;
    public:
    //constructor
    RobotomyRequestForm();

    //copy constructor
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    
    //robotomizing
    virtual void    execute(Bureaucrat const & executor) const;
    
    //target for RobotomyRequestForm
    RobotomyRequestForm(char const *target);

    //copy assignment operator
    RobotomyRequestForm   &operator=(RobotomyRequestForm const &rrf);

    //destructor
    ~RobotomyRequestForm();
};

#endif