#include "Bureaucrat.hpp"

//constructor

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(char const *name_b, int grade_b)
{
    if (grade_b < 1)
    {
        std::cout << "too high grade" << std::endl;
        exit (1);
    }
    if (grade_b > 150)
    {
        std::cout << "too low grade" << std::endl;
        exit (1);
    }
    this->name = name_b;
    this->grade = grade_b;
}

//copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    if (this != &copy)
        *this = copy;
}

//copy assignment operator
Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &B)
{
    if (this != &B)
    {
        this->grade = B.grade;
        this->name = B.name;
    }
    return (*this);
}

//inc and dec

void        Bureaucrat::Increment_Grade()
{  
    this->grade--;
    try 
    {
        if (this->grade < 1)
        {
            this->grade++;
            throw std::exception();
        }
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
}

void        Bureaucrat::Decrement_Grade()
{
    this->grade++;
    try
    {
        if (this->grade > 150)
        {
            this->grade--;
            throw std::exception();
        }
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
    if (f.getGradeToSign() > 150 || f.getGradeToSign() < 1 || f.getGradeToExecute() > 150 || f.getGradeToExecute() < 1)
    {
        std::cout << "invalid Form value to be shown" << std::endl;
        return ;
    }
    if (f.getSign() == true)
        std::cout << name << " signed" << f.getName() << std::endl;
    else
        std::cout << name << " couldn't sign " << f.getName() << " because first you need to sign it" << std::endl;
}

//destructor

Bureaucrat::~Bureaucrat()
{
}