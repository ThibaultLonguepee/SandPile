/*
** EPITECH PROJECT, 2024
** SandPile
** File description:
** Map
*/

#include "Map.hpp"
#include "SandPileException.hpp"
#include <fstream>
#include <iostream>

Map::Map(const std::string& source, const std::string& display)
    : _source(source)
{
    std::ifstream file(source);
    if (!file.is_open())
        throw SandPileException(source, "could not open map.");

    std::string line = "";
    uint32_t row = 0;

    while (std::getline(file, line)) {
        uint32_t col = 0;
        uint32_t w = line.length();

        if (row == 0) this->_width = w;
        ++row;
        if (w != this->_width) throw SandPileException(
            "Map (" + std::to_string(row) + ")",
            "bad amount of columns at this row.");
        this->_map.push_back(std::vector<uint8_t>());

        for (auto c : line) {
            int8_t i = -1;

            ++col;
            for (int8_t j = 0; j < 4; j++)
                if (display[j] == c) { i = j; break; }
            if (i < 0) throw SandPileException(
                    "Map (" + std::to_string(row) + "," + std::to_string(col) + ")",
                    "unknwon character found.");
            this->_map[row - 1].push_back(static_cast<uint8_t>(i));
        }
    }
    this->_height = row;
}

Map::Map(const Map& source)
{
    this->_width = source.width();
    this->_height = source.height();
    this->_source = source.source();
    for (const auto& row : source._map)
        this->_map.push_back(row);
}

const Map& Map::operator=(const Map& source)
{
    this->_width = source.width();
    this->_height = source.height();
    this->_source = source.source();

    this->_map.clear();
    for (const auto& row : source._map)
        this->_map.push_back(row);
    return *this;
}

uint32_t Map::at(uint32_t x, uint32_t y) const
{
    if (x >= this->_width || y >= this->_height)
        throw std::out_of_range(
            "Map (" + std::to_string(x) + ", " + std::to_string(y) + ")");
    return this->_map[y][x];
}

void Map::update() noexcept
{
    uint32_t x = this->_width / 2;
    uint32_t y = this->_height / 2;
    #ifdef COPY_COLLAPSE
    this->_map[y][x]++;
    this->_copyCollapse();
    #else
    this->_recCollapse(x, y);
    #endif
}

#ifdef COPY_COLLAPSE

void Map::_copyCollapse() noexcept
{
    bool modified;

    do {
        Map copy(*this);
        modified = false;
        for (uint32_t y = 0; y < this->_height; y++) {
            for (uint32_t x = 0; x < this->_height; x++) {
                if (this->_map[y][x] < 4)
                    continue;
                modified = true;
                safeChange(x, y, -4);
                safeChange(x, y - 1, 1);
                safeChange(x, y + 1, 1);
                safeChange(x - 1, y, 1);
                safeChange(x + 1, y, 1);
            }
        }
        this->_map = copy._map;
    } while (modified)
}

void Map::_safeChange(uint32_t x, uint32_t y, int8_t delta) noexcept
{
    if (x > this->_width || y > this->_height)
        return;
    this->_map[y][x] += delta;
}

#else

void Map::_recCollapse(uint32_t x, uint32_t y) noexcept
{
    if (x >= this->_width || y >= this->_height)
        return;
    this->_map[y][x]++;
    if (this->_map[y][x] < 4)
        return;
    this->_map[y][x] -= 4;
    this->_recCollapse(x - 1, y);
    this->_recCollapse(x + 1, y);
    this->_recCollapse(x, y - 1);
    this->_recCollapse(x, y + 1);
}

#endif

void Map::draw(const std::string& display) const noexcept
{
    for (uint32_t y = 0; y < this->_height; y++) {
        std::string line = "";
        for (uint32_t x = 0; x < this->_width; x++)
            line += display[this->_map[y][x]];
        std::cout << line << std::endl;
    }
}
