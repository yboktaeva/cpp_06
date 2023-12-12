/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:42:50 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/12 16:49:32 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>

class Base
{
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif