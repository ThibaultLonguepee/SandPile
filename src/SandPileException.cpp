/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** SandPileException
*/

#include "SandPileException.hpp"

SandPileException::SandPileException(const std::string& message)
{
    std::string red = "\033[0;31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

    this->_message += bold + red + "Unknown Setup Error: ";
    this->_message += reset + red + message + reset;
}

SandPileException::SandPileException(const std::string& cause, const std::string& message)
{
    std::string red = "\033[0;31m";
    std::string bold = "\033[1m";
    std::string reset = "\033[0m";

    this->_message += red + bold + cause + ": ";
    this->_message += reset + red + message + reset;
}

const char *SandPileException::what() const noexcept
{
    return this->_message.c_str();
}
