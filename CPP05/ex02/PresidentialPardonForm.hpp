#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        char const *target;
    public:
    //constructor
    PresidentialPardonForm();

    //copy constructor
    PresidentialPardonForm(PresidentialPardonForm const &copy);

    //target for RobotomyRequestForm
    PresidentialPardonForm(char const *target);

    //copy assignment operator
    PresidentialPardonForm   &operator=(PresidentialPardonForm const &ppf);

    //execute form
    //pardoning by Zaphof Beeblebrox    
    virtual void    execute(Bureaucrat const & executor) const;
    //destructor
    ~PresidentialPardonForm();
};

#endif