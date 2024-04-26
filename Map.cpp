#include "Map.hpp"

Map::Map() {

}

Map::~Map() {

}

std::vector<std::vector<std::string> > Map::getMap() const {
    return this->_map;
}

void Map::checkWall( std::string & line ) const {
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != '1')
            throw std::invalid_argument("Map Error : wall is open");
    }
}

void Map::checkChar( std::string const & line) const {
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'X')
            throw std::invalid_argument("Map Error : only '0' '1' or 'X' char");
        if (i == 0 || i == line.length() - 1)
        {
            if (line[i] != '1')
                throw std::invalid_argument("Map Error : map is not carre");
        }
    }
}


void Map::setMap( const std::string & line ) {
    std::istringstream iss(line);
    std::vector<std::string> row;
    std::string element;
    while (iss >> element) {
        row.push_back(element);
    }
    this->_map.push_back(row);
}

void Map::parsMap() {
    for (const auto& row : this->getMap()) {
        static size_t numRow = this->_map[0][0].size();
        for (const auto& elem : row) {
            if (numRow != elem.size())
                throw std::invalid_argument("Map Error : map is not carre");
            checkChar(elem);
        }
    }
    checkWall(this->_map[0][0]);
    checkWall(this->_map[this->_map.size() - 1][0]);
}

std::ostream& operator<<(std::ostream & out, const Map & src) {
    for (const auto& row : src.getMap()) {
        for (const auto& elem : row) {
            out << elem << std::endl;
        }
    }
    return out;
}