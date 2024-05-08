#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class   PresidentialPardonForm
{
    private:
        std::string     target;
    public:
    //constructor
    PresidentialPardonForm();

    //target for working directory
    PresidentialPardonForm(std::string target);
    //copy constructor
    PresidentialPardonForm(PresidentialPardonForm const &copy);

    //copy assignment operator
    PresidentialPardonForm   &operator=(PresidentialPardonForm const &ppf);

    //execute form
    //pardoning by Zaphof Beeblebrox    
    virtual void    execute(Bureaucrat const & executor) const;    //destructor
    //destructor
    ~PresidentialPardonForm();
};

#endif