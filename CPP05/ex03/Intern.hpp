#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class   Intern : public AForm
{
    private:
    public:
    //constructor
    Intern();
    //copy constructo
    Intern(const Intern &copy);

    //copy assignment operator
    Intern &operator=(Intern const &I);

    //making Form
    AForm   *makeForm(std::string name_form, std::string target);
    

    //executing Form
    virtual void    execute(Bureaucrat const & executor) const;
    //destructor
    ~Intern();
};

#endif