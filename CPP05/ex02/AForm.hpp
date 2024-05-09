#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <ctime>

class Bureaucrat;

class AForm
{
    private:
        mutable bool        sign;
        const int   grade_to_sign;
        const int   grade_to_execute;
        char const  *name;
    public:
        //constructor
        AForm(void);
        AForm(char const *name_form, const int grade_sign, const int grade_ex);
        
        //copy constructor
        AForm(AForm const &copy);

        //copy assignment operator
        AForm  &operator=(AForm const &f);

        //exception
        void    InvalidGradeException(void) const;
        void    GradeTooHighException(void) const;
        void    GradeTooLowException(void) const;
        void    InvalidSignException(void) const;

        
        //sign
        void  beSigned(Bureaucrat &b) const;
        
        //getting
        char const  *getName(void) const;

        bool        getSign(void) const;

        int         getGradeToSign(void) const;
        int         getGradeToExecute(void) const;

        //execute the form
        virtual void    execute(Bureaucrat const & executor) const = 0;

        //destructor
        ~AForm();
};

#endif