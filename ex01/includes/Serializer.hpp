/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:08:04 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/12 14:44:17 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>
# include <stdint.h>

typedef struct Data {
    int n;
    float f;
    std::string s1;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &src);
        ~Serializer();
        Serializer &operator=(const Serializer &src);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif