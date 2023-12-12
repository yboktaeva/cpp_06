/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:17:01 by yuliaboktae       #+#    #+#             */
/*   Updated: 2023/12/12 14:38:37 by yuboktae         ###   ########.fr       */
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

char const *ScalarConverter::NonDisplayable::what() const throw() {
    return "Non displayable";
}

bool isDigits(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-' && str[i] != '+')
            return false;
    }
    return true;
}

char ScalarConverter::toChar(std:: string str) {
    char c = '\0';
    try {
        if (!isdigit(str[0]) && str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])))
            c = static_cast<char>(str[0]);
        else if (isDigits(str)) {
            int n = atoi(str.c_str());
            if (n > CHAR_MAX || n < CHAR_MIN)
                throw std::invalid_argument("Invalid argument");
            c = static_cast<char>(n);
        }
        else
            throw std::invalid_argument("Invalid argument");
        if (!std::isprint(static_cast<unsigned char>(c)))
            throw NonDisplayable();
        std::cout << GREEN << "char: " << c << RESET << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cout << RED << "char: impossible" << RESET << std::endl;
        return 0;
    }
    catch (const NonDisplayable &e) {
        std::cout << RED << "char: Non displayable" << RESET << std::endl;
        return 0;
    }
    return c;
}

int ScalarConverter::toInt(std::string str) {
    int i = 0;
    long int l = 0;
    char *end;
    try {
        if (!isdigit(str[0]) && str.length() == 1)
            i = static_cast<int>(str[0]);
        else if (isDigits(str)) {
            l = strtol(str.c_str(), &end, 10);
            if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
                throw std::invalid_argument("Invalid argument");
            i = static_cast<int>(l);
        }
        else
            throw std::invalid_argument("Invalid argument");
        std::cout << GREEN << "int: " << i << RESET << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cout << RED << "int: impossible" << RESET << std::endl;
        return 0;
    }
    return i;
}

float ScalarConverter::toFloat(std::string str) {
    float f = 0.0f;
    long double ld = 0.0;
    char *end;
    try {
        if (!isdigit(str[0]) && str.length() == 1)
            f = static_cast<float>(str[0]);
        else if (str[0] == '-' && str.length() > 1 && isDigits(str)) {
            ld = strtold(str.c_str() + 1, &end);
            f = static_cast<float>(-ld);
        }
        else if (isDigits(str)) {
            ld = strtold(str.c_str(), &end);
            f = static_cast<float>(ld);
        }
        else
            throw std::invalid_argument("Invalid argument");
        if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
            throw std::invalid_argument("Invalid argument");
        std::cout << GREEN << "float: " << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "float: impossible" << RESET << std::endl;
        return 0;
    }
    return f;
}

double ScalarConverter::toDouble(std::string str) {
    double d = 0.0;
    long double ld = 0.0;
    char *end;
    try {
        if (!isdigit(str[0]) && str.length() == 1)
            d = static_cast<double>(str[0]);
        else if (str[0] == '-' && str.length() > 1 && isDigits(str)) {
            ld = strtold(str.c_str() + 1, &end);
            d = static_cast<double>(-ld);
        }
        else if (isDigits(str)) {
            ld = strtold(str.c_str(), &end);
            d = static_cast<double>(ld);
        }
        else
            throw std::invalid_argument("Invalid argument");
        if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
            throw std::invalid_argument("Invalid argument");
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
            if (str == "nan" || str == "-inf" || str == "+inf")
                std::cout << GREEN << "float: " << str1[i] + "f" << RESET << std::endl;
            else
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
