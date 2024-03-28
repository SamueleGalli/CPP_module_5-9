#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name)
{
    this->name = name;
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

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

void      GradeTooHighException(void)
{
    std::cout << Error it must not be minor of 1 << std::endl;
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

void    GradeTooLowException(void)
{
    std::cout << Error it must not be major of 150 << std::endl;
}

std::string Bureaucrat::getName(void)
{
    return (name);
}

int Bureaucrat::getGrade(void)
{
    return (grade);
}

std::ostream    &operator<<(std::ostream &out, Bureaucrat &B)
{
    out << B.getName() << ", bureaucrat grade " << B.getGrade();
    return out;
}