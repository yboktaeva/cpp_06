/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:58 by yuliaboktae       #+#    #+#             */
/*   Updated: 2023/12/12 14:13:14 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <exception>
# include <cmath>
# include <cctype>
# include <limits>
# include <climits>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
    public:
        static char toChar(std::string str);
        static int toInt(std::string str);
        static float toFloat(std::string str);
        static double toDouble(std::string str);
        static void convert(std::string str);
    
    class NonDisplayable : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

bool isDigits(std::string str);

#endif