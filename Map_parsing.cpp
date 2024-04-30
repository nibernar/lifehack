#include "Map_parsing.hpp"

MapParsing::MapParsing() {

}

MapParsing::~MapParsing() {

}

std::vector<std::vector<std::string> > MapParsing::getMapParsing() const {
    return this->_mapParsing;
}

void MapParsing::checkWall( std::string & line ) const {
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != '1')
            throw std::invalid_argument("MapParsing Error : wall is open");
    }
}

void MapParsing::checkChar( std::string const & line) const {
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'X')
            throw std::invalid_argument("MapParsing Error : only '0' '1' or 'X' char");
        if (i == 0 || i == line.length() - 1)
        {
            if (line[i] != '1')
                throw std::invalid_argument("MapParsing Error : mapParsing is not carre");
        }
    }
}


void MapParsing::setMapParsing( const std::string & line ) {
    std::istringstream iss(line);
    std::vector<std::string> row;
    std::string element;
    while (iss >> element) {
        row.push_back(element);
    }
    this->_mapParsing.push_back(row);
}

void MapParsing::parsMapParsing() {
    for (const auto& row : this->getMapParsing()) {
        static size_t numRow = this->_mapParsing[0][0].size();
        for (const auto& elem : row) {
            if (numRow != elem.size())
                throw std::invalid_argument("MapParsing Error : mapParsing is not carre");
            checkChar(elem);
        }
    }
    checkWall(this->_mapParsing[0][0]);
    checkWall(this->_mapParsing[this->_mapParsing.size() - 1][0]);
}

std::ostream& operator<<(std::ostream & out, const MapParsing & src) {
    for (const auto& row : src.getMapParsing()) {
        for (const auto& elem : row) {
            out << elem << std::endl;
        }
    }
    return out;
}