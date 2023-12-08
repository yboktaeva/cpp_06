/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:17:01 by yuliaboktae       #+#    #+#             */
/*   Updated: 2023/12/08 19:02:58 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this != &src)
        *this = src;
    return *this;
}

static char toChar(std:: string str) {
    char c;
    try {
        c = static_cast<char>(std::stoi(str));
    }
    catch (std::exception &e) {
        std::cout << RED << "char: impossible" << RESET << std::endl;
        return 0;
    }
    if (c < 32 || c > 126)
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
    else
        std::<< cout << GREEN << "char: " << c << RESET << std::endl;
    return c;
}

static int toInt(std::string str) {
    int i;
    try {
        i = static_cast<int>(std::stoi(str));
    }
    catch (std::exeption &e) {
        std::cout << RED << "int: impossible" << RESET << std::endl;
        return 0;
    }
    std::cout << GREEN << "int: " << i << RESET << std::endl;
    return i;
}

static float toFloat(std::string str) {
    float f;
    try {
        f = static_cast<float>(std::stof(str));
    }
    catch (std::exeption &e) {
        std::cout << RED << "float: impossible" << RESET << std::endl;
        return 0;
    }
    try {
        
    }
    std::cout << GREEN << "float: " << f << "f" << RESET << std::endl;
    return f;
}

static double toDouble(std::string str) {
    double d;
    try {
        d = static_cast<double>(std::stod(str));
    }
    catch (std::exeption &e) {
        std::cout << RED << "double: impossible" << RESET << std::endl;
        return 0;
    }
    std::cout << GREEN << "double: " << d << RESET << std::endl;
    return d;
}

static void convert(std::string str) {
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}