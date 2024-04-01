#include "Bureaucrat.hpp"

//constructor

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(int grade_b, char const *name_b)
: name(name_b), grade(grade_b)
{
    this->name = name_b;
    this->grade = grade_b;
}

//inc and dec

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
    std::cout << "Error: (invalid increment)=\"higher than 1\"" << std::endl;
}


void    Bureaucrat::GradeTooLowException()
{
    std::cout << "Error: (invalid decrement)=\"lower than 150\"" << std::endl;
}

//getter
char const *Bureaucrat::getName(void)
{
    return (name);
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

//show form
void    Bureaucrat::signForm(Form &f)
{
    std::cout << "|Form : (" << f.getName() << ")|" << std::endl;
    if (f.getSign() == true)
        std::cout << "|Sign : (is signed" << ")|" << std::endl;
    else
        std::cout << "|Sign : (is not signed" << ")|" << std::endl;
    std::cout << "|Grade to sign : ("  << f.getGradeToSign() << ")|" << std::endl;
    std::cout << "|Grade to execute : (" << f.getGradeToExecute() << ")|" << std::endl;
}

//destructor

Bureaucrat::~Bureaucrat()
{
}