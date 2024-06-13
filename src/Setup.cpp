/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Setup
*/

#include "Setup.hpp"

SetupException::SetupException(const std::string& message)
{
    std::string red = "\033[0;31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

    this->_message += bold + red + "Unknown Setup Error: ";
    this->_message += reset + red + message + reset;
}

SetupException::SetupException(const std::string& cause, const std::string& message)
{
    std::string red = "\033[0;31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

    this->_message += red + bold + cause + ": ";
    this->_message += reset + red + message + reset;
}

const char *SetupException::what() const noexcept
{
    return this->_message.c_str();
}

Setup::Setup(int ac, char **av)
{
    if (ac < 4)
        throw SetupException("Arguments count", "too few arguments given.");
    if (ac > 4)
        throw SetupException("Arguments count", "too many arguments given.");

    this->_mapFile = av[1];
    this->_display = av[2];
    this->_iterations = std::atoi(av[3]);

    if (this->_display.length() != 4)
        throw SetupException("Display", "must be 4 characters long.");
    for (uint32_t i = 0; i < 3; i++)
        for (uint32_t j = i + 1; j < 4; j++)
            if (this->_display[i] == this->_display[j])
                throw SetupException("Display", "should not contain repeated characters.");

    if (this->_iterations == 0)
        throw SetupException("Iterations", "must be a number strictly superior than 0.");
}
