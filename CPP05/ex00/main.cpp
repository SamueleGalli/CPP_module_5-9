/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/04/01 18:59:20 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat B(100, "Bill");

    /*std::cout << B << std::endl;
    B.Increment_Grade(99);
    std::cout << B << std::endl;
    B.Decrement_Grade(149);
    std::cout << B << std::endl;
    */
    std::cout << B << std::endl;
    B.Increment_Grade(200);
    std::cout << B << std::endl;
    B.Decrement_Grade(170);
    std::cout << B << std::endl;
    
}