#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

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

        //method inc and dec
        void        Increment_Grade(int increment);
        void        Decrement_Grade(int decrement);

        //exception
        void        GradeTooHighException(void);
        void        GradeTooLowException(void);

        //getter
        char const *getName(void);
        int         getGrade(void);

        //print Bureaucrat
        friend  std::ostream    &operator<<(std::ostream &out, Bureaucrat &B);
        //show form
        void signForm(Form &f);
        //costructor
        ~Bureaucrat();

};

#endif
