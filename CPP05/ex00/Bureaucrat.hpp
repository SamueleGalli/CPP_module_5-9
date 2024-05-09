#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
class Bureaucrat
{
    private:
        char const *name;
        int        grade;
    public:
        //constructor
        Bureaucrat(char const *name_b, int grade_b);
        Bureaucrat();

        //copy constructor
        Bureaucrat(Bureaucrat const &copy);

        //copy assignment operator
        Bureaucrat  &operator=(Bureaucrat const &B);

        //method inc and dec
        void        Increment_Grade();
        void        Decrement_Grade();

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
