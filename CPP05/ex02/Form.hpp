#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        bool        sign;
        const int   grade_to_sign;
        const int   grade_to_execute;
        char const  *name;
    public:
        //constructor
        Form(void);
        Form(char const *name_form, const int grade_sign, const int grade_ex);
        
        //copy constructor
        Form(Form const &copy);

        //copy assignment operator
        Form  &operator=(Form const &f);

        //exception
        void    GradeTooHighException(void);
        void    GradeTooLowException(void);
        
        //sign
        void    beSigned(Bureaucrat &b);
        
        //getting
        char const  *getName(void) const;

        bool        getSign(void) const;

        int         getGradeToSign(void) const;
        int         getGradeToExecute(void) const;

        //destructor
        ~Form();
};

#endif