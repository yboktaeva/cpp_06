/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:12:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/12 14:44:01 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
    Data *data = new Data;
    data->n = 42;
    data->f = 42.42f;
    data->s1 = "Lorem ipsum dolor sit amet";
    uintptr_t raw = Serializer::serialize(data);
    std::cout << GREEN << "raw before: " << raw << RESET << std::endl;
    std::cout << GREEN << "data before: " << data << RESET << std::endl;
    std::cout << GREEN << "data->n: " << data->n << RESET << std::endl;
    std::cout << GREEN << "data->f: " << data->f << RESET << std::endl;
    std::cout << GREEN << "data->s1: " << data->s1 << RESET << std::endl;
    data = Serializer::deserialize(raw);
    std::cout << CYAN << "raw after: " << raw << RESET << std::endl;
    std::cout << CYAN << "data after: " << data << RESET << std::endl;
    std::cout << CYAN << "data->n: " << data->n << RESET << std::endl;
    std::cout << CYAN << "data->f: " << data->f << RESET << std::endl;
    std::cout << CYAN << "data->s1: " << data->s1 << RESET << std::endl;
    return 0;
}