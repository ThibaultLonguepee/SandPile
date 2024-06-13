/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Setup
*/

#pragma once

#include <string>
#include <cstdint>

class Setup
{
    public:
        Setup(int ac, char **av);
        ~Setup() = default;

        const std::string& map() const noexcept { return this->_mapFile; }
        const std::string& display() const noexcept { return this->_display; }
        uint32_t iterations() const noexcept { return this->_iterations; }
    protected:
    private:
        std::string _mapFile = "";
        std::string _display = "";
        uint32_t _iterations = 0;
};
