/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** main
*/

#include <iostream>
#include "Setup.hpp"
#include "Map.hpp"

int main(int ac, char **av)
{
    try {

        Setup setup(ac, av);
        Map map(setup.map(), setup.display());
        map.draw(setup.display());

    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
