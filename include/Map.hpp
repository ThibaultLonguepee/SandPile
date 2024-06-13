/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Map
*/

#pragma once

#include <string>
#include <vector>

class Map {
    public:
        Map(const std::string& source, const std::string& display);
        Map(const Map& source);
        ~Map() = default;

        const std::string& source() const noexcept { return this->_source; }
        uint32_t width() const noexcept { return this->_width; }
        uint32_t height() const noexcept { return this->_height; }

        uint32_t at(uint32_t x, uint32_t y) const;
        void update() noexcept;
        void collapse(uint32_t x, uint32_t y);
        void draw(const std::string& display) const noexcept;

        const Map& operator=(const Map& source);

    protected:
    private:
        void safeChange(uint32_t x, uint32_t y, int8_t delta) noexcept;
        uint32_t _width = 0;
        uint32_t _height = 0;
        std::string _source = "";
        std::vector<std::vector<uint8_t>> _map = {};
};
