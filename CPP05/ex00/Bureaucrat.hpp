#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
class Bureaucrat
{
    private:
        char const *name;
        int        grade;
    public:
        //constructor
        Bureaucrat(int grade_b, char const *name_b);
        //method inc and dec
        void        Increment_Grade(int increment);
        void        Decrement_Grade(int decrement);
        //exception
        void        GradeTooHighException(void);
        void        GradeTooLowException(void);
        //getter
        char const    *getName(void);
        int     getGrade(void);
        //destructor
        ~Bureaucrat();
};
//overload operator print
std::ostream    &operator<<(std::ostream &out, Bureaucrat &B);

#endif
