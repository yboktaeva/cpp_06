/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliaboktaeva <yuliaboktaeva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:16:58 by yuliaboktae       #+#    #+#             */
/*   Updated: 2023/12/07 14:20:33 by yuliaboktae      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(std::string str);
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
        
        static void c
};
#endif