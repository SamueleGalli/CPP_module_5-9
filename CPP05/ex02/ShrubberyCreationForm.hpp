#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;

class   ShrubberyCreationForm : public AForm
{
    public:
    //constructor
    ShrubberyCreationForm();
    //target for working directory
    virtual void    execute(Bureaucrat const & executor) const;
    
    //copy constructor
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);

    //copy assignment operator
    ShrubberyCreationForm   &operator=(ShrubberyCreationForm const &scf);

    //destructor
    ~ShrubberyCreationForm();
};

#endif