/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:02:16 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/09 17:17:18 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string str = argv[1];
    if (str.empty()) {
        std::cout << "Empty string" << std::endl;
        return 1;
    }
    ScalarConverter::convert(str);
    return 0;
}