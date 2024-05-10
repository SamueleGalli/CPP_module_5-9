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

    //robotomizing
    virtual void    execute(Bureaucrat const & executor) const;
    
    //target for RobotomyRequestForm
    RobotomyRequestForm(char const *target);

    //copy constructor
    RobotomyRequestForm(RobotomyRequestForm const &copy);

    //copy assignment operator
    RobotomyRequestForm   &operator=(RobotomyRequestForm const &rrf);

    //destructor
    ~RobotomyRequestForm();
};

#endif