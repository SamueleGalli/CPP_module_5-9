#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class Form;

class Bureaucrat
{
    private:
        char const *name;
        int         grade;
    public:
        //constructor
        Bureaucrat(void);
        Bureaucrat(int grade_b, char const *name_b);
        
        //copy constructor
        Bureaucrat(Bureaucrat const &copy);
        //method inc and dec
        void        Increment_Grade();
        void        Decrement_Grade();

        //copy assignment operator
        Bureaucrat  &operator=(Bureaucrat const &B);

        //exception
        void        GradeTooHighException(void);
        void        GradeTooLowException(void);

        //getter
        char const *getName(void);
        int         getGrade(void);

        //show form
        void signForm(Form &f);
        //deconstructor
        ~Bureaucrat();

};
//print Bureaucrat
std::ostream    &operator<<(std::ostream &out, Bureaucrat &B);

#endif
