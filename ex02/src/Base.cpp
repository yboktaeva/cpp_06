/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:44:21 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/12 18:48:44 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void) {
    srand(time(NULL)); 
    int random = rand() % 4;
    switch (random) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << GREEN << "A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout <<  GREEN << "B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << GREEN << "C" << RESET << std::endl;
    else
        std::cout << RED << "cast failed: null pointer" << RESET << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN << "A" << RESET << std::endl;
    }
    catch (std::exception &e) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << GREEN << "B" << RESET << std::endl;
        }
        catch (std::exception &e) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << GREEN << "C" << RESET << std::endl;
            }
            catch (std::exception &e) {
                std::cout << RED << e.what() << RESET << std::endl;
            }
        }
    }
}