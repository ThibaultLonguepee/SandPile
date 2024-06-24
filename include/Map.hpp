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
        void draw(const std::string& display) const noexcept;
        void update() noexcept;

        const Map& operator=(const Map& source);

    private:
        #if defined(COPY_COLLAPSE)
        void _copyCollapse() noexcept;
        #elif defined(SELF_COLLAPSE)
        void _selfCollapse() noexcept;
        #else
        void _recCollapse(uint32_t x, uint32_t y) noexcept;
        #endif

        #if defined(SELF_COLLAPSE) || defined(COPY_COLLAPSE)
        void _safeChange(uint32_t x, uint32_t y, int8_t delta) noexcept;
        #endif

    private:
        uint32_t _width = 0;
        uint32_t _height = 0;
        std::string _source = "";
        std::vector<std::vector<uint8_t>> _map = {};
};
