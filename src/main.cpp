/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** main
*/

#include <iostream>
#include "Setup.hpp"

int main(int ac, char **av)
{
    try {
        Setup(ac, av);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
