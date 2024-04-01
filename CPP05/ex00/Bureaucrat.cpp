#include "Bureaucrat.hpp"

//constructor
Bureaucrat::Bureaucrat(int grade_b, char const *name_b)
{
    this->name = name_b;
    this->grade = grade_b;
}

//method inc and dec
void        Bureaucrat::Increment_Grade(int increment)
{
    int     grade1 = this->grade - increment;
    try 
    {
        if (grade1 < 1)
            throw std::exception();
        else
            this->grade = this->grade - increment;
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
}

void        Bureaucrat::Decrement_Grade(int decrement)
{
    int     grade1 = this->grade + decrement;
    try
    {
        if (grade1 > 150)
            throw std::exception();
        else
            this->grade = this->grade + decrement;

    }
    catch (std::exception &e)
    {
        GradeTooLowException();
    }
}

//exception
void      Bureaucrat::GradeTooHighException(void)
{
    std::cout << "Error it must not be minor of 1" << std::endl;
}

void    Bureaucrat::GradeTooLowException()
{
    std::cout << "Error it must not be major of 150" << std::endl;
}

//getter
char const *Bureaucrat::getName(void)
{
    return (this->name);
}

int Bureaucrat::getGrade(void)
{
    return (grade);
}

//overload operator print
std::ostream    &operator<<(std::ostream &out, Bureaucrat &B)
{
    out << B.getName() << ", bureaucrat grade " << B.getGrade();
    return out;
}

//destructor
Bureaucrat::~Bureaucrat()
{
}