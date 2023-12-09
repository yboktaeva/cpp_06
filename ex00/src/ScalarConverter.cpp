/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:17:01 by yuliaboktae       #+#    #+#             */
/*   Updated: 2023/12/09 19:47:12 by yuboktae         ###   ########.fr       */
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

char ScalarConverter::toChar(std:: string str) {
    char c;
    try {
        if (std::isnan(atof(str.c_str())) || std::isinf(atof(str.c_str()))) {
            throw std::invalid_argument("Invalid argument");
        }
        if (!isdigit(str[0]) && str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])))
            c = static_cast<char>(str[0]);
        else if (isdigit(str[0]))
            c = static_cast<char>(atoi(str.c_str()));
        else
            throw std::invalid_argument("Invalid argument");
        if (!std::isprint(static_cast<unsigned char>(c)))
            std::cout << RED << "char: Non displayable" << RESET << std::endl;
        else
            std::cout << GREEN << "char: " << c << RESET << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cout << RED << "char: impossible" << RESET << std::endl;
        return 0;
    }
    return c;
}

int ScalarConverter::toInt(std::string str) {
    int i;
    try {
        if (std::isnan(atof(str.c_str())) || std::isinf(atof(str.c_str()))) {
            throw std::invalid_argument("Invalid argument");
        }
        if (!isdigit(str[0]) && str.length() == 1)
            i = static_cast<int>(str[0]);
        if (str[0] == '-')
            i = static_cast<int>(-atoi(str.c_str() + 1));
        else if (isdigit(str[0]))
            i = static_cast<int>(atoi(str.c_str()));
        if (i == 0 && str[0] != '0')
            throw std::invalid_argument("Invalid argument");
        for (size_t j = 1; j < str.size(); ++j) {
            if (!isdigit(str[j]) && str[j] != '.' && str[j] != 'f')
                throw std::invalid_argument("Invalid argument");
        }
        std::cout << GREEN << "int: " << i << RESET << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cout << RED << "int: impossible" << RESET << std::endl;
        return 0;
    }
    return i;
}

float ScalarConverter::toFloat(std::string str) {
    float f;
    try {
        if (!isdigit(str[0]) && str.length() == 1)
            f = static_cast<float>(str[0]);
        if (str[0] == '-')
            f = static_cast<float>(-atof(str.c_str() + 1));
        else if (isdigit(str[0]))
            f = static_cast<float>(atof(str.c_str()));
        if (f == 0 && str[0] != '0')
            throw std::invalid_argument("Invalid argument");
        // for (size_t j = 1; j < str.size(); ++j) {
        //     if (!isdigit(str[j]) && str[j] != '.' && str[j] != 'f')
        //         throw std::invalid_argument("Invalid argument");
        //}
        std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
        
    }
    catch (std::exception &e) {
        std::cout << RED << "float: impossible" << RESET << std::endl;
        return 0;
    }
    return f;
}

double ScalarConverter::toDouble(std::string str) {
    double d;
    try {
        if (!isdigit(str[0]) && str.length() == 1)
            d = static_cast<double>(str[0]);
        if (str[0] == '-')
            d = static_cast<double>(-atof(str.c_str() + 1));
        else if (isdigit(str[0]))
            d = static_cast<double>(atof(str.c_str()));
        if (d == 0 && str[0] != '0')
            throw std::invalid_argument("Invalid argument");
        // for (size_t j = 1; j < str.size(); ++j) {
        //     if (!isdigit(str[j]) && str[j] != '.')
        //         throw std::invalid_argument("Invalid argument");
        //}
        std::cout << GREEN << "double: " << std::fixed << std::setprecision(1) << d << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "double: impossible" << RESET << std::endl;
        return 0;
    }
    return d;
}

void ScalarConverter::convert(std::string str) {
    
    std::string str1[6] = {"-inf", "+inf","nan", "-inff", "+inff", "nanf"};
    for (int i = 0; i < 6; i++) {
        if (str == str1[i]) {
            std::cout << RED << "char: impossible" << RESET << std::endl;
            std::cout << RED << "int: impossible" << RESET << std::endl;
            std::cout << GREEN << "float: " << str1[i] << RESET << std::endl;
            std::cout << GREEN << "double: " << str1[i] << RESET << std::endl;
            return ;
        }
    }
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}