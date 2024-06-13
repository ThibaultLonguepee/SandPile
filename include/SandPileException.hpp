/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** SandPileException
*/

#pragma once

#include <exception>
#include <string>

class SandPileException : public std::exception
{
    public:
        SandPileException(const std::string& message);
        SandPileException(const std::string& cause, const std::string& message);
        ~SandPileException() = default;
        const char *what() const noexcept;
    private:
        std::string _message = "";
};