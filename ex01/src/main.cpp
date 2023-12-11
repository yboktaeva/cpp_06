/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:12:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/11 20:02:23 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main () {
    Data *data = new Data;
    data->n = 42;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << GREEN << "raw before: " << raw << RESET << std::endl;
    std::cout << GREEN << "data before: " << data << RESET << std::endl;
    Data *originalData = data;
    data = Serializer::deserialize(raw);
    std::cout << GREEN << "raw after: " << raw << RESET << std::endl;
    std::cout << GREEN << "data after: " << data << RESET << std::endl;
    std::cout << GREEN << "data->n: " << data->n << RESET << std::endl;
    delete originalData;
    return 0;
}