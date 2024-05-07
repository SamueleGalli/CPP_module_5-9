#include "Form.hpp"

//constructor

Form::Form(char const *name_form, const int grade_sign, const int grade_ex)
: sign(false), grade_to_sign(grade_sign), grade_to_execute(grade_ex), name(name_form)
{
    try
    {
        if (grade_sign < 1 || grade_ex < 1)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
    try
    {
        if (grade_sign > 150 || grade_ex > 150)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        GradeTooLowException();
    }
}

Form::Form(void)
: sign(false), grade_to_sign(1), grade_to_execute(1), name("default")
{
}
//copy constructor
Form::Form(Form const &copy)
: sign(copy.sign),
  grade_to_sign(copy.grade_to_sign),
  grade_to_execute(copy.grade_to_execute),
  name(copy.name)
{
}

//copy assignment operator
Form  &Form::operator=(Form const &f)
{
    if (this != &f)
    {
        this->sign = f.sign;
        this->name = f.name;
    }
    return (*this);
}

//exeception
void      Form::GradeTooHighException(void)
{
    std::cout << "Error it must not be minor of 1" << std::endl;
}

void    Form::GradeTooLowException()
{
    std::cout << "Error it must not be major of 150" << std::endl;
}

//sign

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->grade_to_sign)
    {
        if (this->sign == false)
        {
            std::cout << "|signing \"" << this->name << "\" form|" << std::endl;
            this->sign = true;
        }
        else
            std::cout << "invalid: already signed" << std::endl;
    }
    else
        std::cout << "Invalid: grade insufficient" << std::endl;
}


//getting

char const    *Form::getName(void) const
{
    return (this->name);
}

bool    Form::getSign(void) const
{
    return (this->sign);
}


int   Form::getGradeToSign(void) const
{
    return (this->grade_to_sign);
}

int   Form::getGradeToExecute(void) const
{
    return (this->grade_to_execute);
}

//decostructor

Form::~Form()
{
}