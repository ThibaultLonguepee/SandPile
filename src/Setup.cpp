/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Setup
*/

#include "Setup.hpp"
#include "SandPileException.hpp"

Setup::Setup(int ac, char **av)
{
    if (ac < 4)
        throw SandPileException("Arguments count", "too few arguments given.");
    if (ac > 4)
        throw SandPileException("Arguments count", "too many arguments given.");

    this->_mapFile = av[1];
    this->_display = av[2];
    this->_iterations = std::atoi(av[3]);

    if (this->_display.length() != 4)
        throw SandPileException("Display", "must be 4 characters long.");
    for (uint32_t i = 0; i < 3; i++)
        for (uint32_t j = i + 1; j < 4; j++)
            if (this->_display[i] == this->_display[j])
                throw SandPileException("Display", "should not contain repeated characters.");

    if (this->_iterations < 0)
        throw SandPileException("Iterations", "must be a number strictly superior than 0.");
}
