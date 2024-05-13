/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/13 10:57:46 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{
  Intern someRandomIntern;
  AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    rrf = someRandomIntern.makeForm("paperino", "Bender");

}