#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;

class   ShrubberyCreationForm : public AForm
{
    private:
        char const *target;
    public:
    //constructor
    ShrubberyCreationForm();

    //copy constructor
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);

    //target for working directory
    virtual void    execute(Bureaucrat const & executor) const;
    
    //target for RobotomyRequestForm
    ShrubberyCreationForm(char const *target);


    //copy assignment operator
    ShrubberyCreationForm   &operator=(ShrubberyCreationForm const &scf);

    //destructor
    ~ShrubberyCreationForm();
};

#endif