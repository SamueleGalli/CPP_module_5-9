#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
class Bureaucrat
{
    private:
        std::string name;
        int         grade;
    public:
        Bureaucrat(int grade, std::string name);

        void        Increment_Grade(int increment);
        void        Decrement_Grade(int decrement);

        std::string getName(void);
        int         getGrade(void);

        friend  std::ostream    &operator<<(std::ostream &out, Bureaucrat &B);
        ~Bureaucrat();

};

#endif
