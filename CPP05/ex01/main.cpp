/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/07 15:34:44 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat B(100, "Bill");
    //Form F("ASIA", -50, -50);
    //Form F("AMERICA", 300, 300);
    Form F("EUROPE", 50, 50);
    //Bureaucrat
    /*std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Increment_Grade(200);
    std::cout << "--------------------------" << std::endl;
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Decrement_Grade(170);
    std::cout << "--------------------------" << std::endl;
    std::cout << B << std::endl;*/
    //Form
    std::cout << "--------------------------" << std::endl;
    B.signForm(F);
    B.Increment_Grade(50);
    std::cout << "--------------------------" << std::endl;
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    F.beSigned(B);
    std::cout << "--------------------------" << std::endl;
    B.signForm(F);
    std::cout << "--------------------------" << std::endl;
    F.beSigned(B);
}