/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/07 15:26:19 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat B(50, "Bill");

    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Increment_Grade(99);
    std::cout << "--------------------------" << std::endl;
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Decrement_Grade(149);
    /*std::cout << "--------------------------" << std::endl;
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Increment_Grade(200);*/
}