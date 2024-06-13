/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Setup
*/

#pragma once

#include <string>
#include <cstdint>

class SetupException : public std::exception
{
    public:
        SetupException(const std::string& message);
        SetupException(const std::string& cause, const std::string& message);
        ~SetupException() = default;
        const char *what() const noexcept;
    private:
        std::string _message = "";
};

class Setup
{
    public:
        Setup(int ac, char **av);
        ~Setup() = default;

        const std::string& map() const { return this->_mapFile; }
        const std::string& display() const { return this->_display; }
        std::uint32_t iterations() const { return this->_iterations; }
    protected:
    private:
        std::string _mapFile = "";
        std::string _display = "";
        std::uint32_t _iterations = 0;
};
