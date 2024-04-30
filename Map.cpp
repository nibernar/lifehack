#include "Map.hpp"

Map::Map() {

}

Map::~Map() {

}

std::vector<std::vector<Node> > Map::getMap() const {
    return this->_map;
}

void Map::setMap( std::vector<std::vector<std::string> > vec ) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::vector<Node> node_row;
        for (size_t j = 0; j < vec[i].size(); j++) {
            const std::string & str = vec[i][j];
            for (size_t k = 0; k < str.length(); k++) {
                char c = str[k];
                Node node(c);
                if (c == 'X')
                    node.setLife(true);
                node_row.push_back(node);
            }
        }
        this->_map.push_back(node_row);
    }
}

void Map::generation() {
    for (size_t i = 0; i < this->_map.size(); i++) {
        for (size_t j = 0; j < this->_map[i].size(); j++) {
            if (this->_map[i][j].getNode() == '1')
                continue;
            else {
                this->_map[i][j].checkCase(this->getMap(), i, j);
            }
        }
    }
}

void Map::update() {
    for (size_t i = 0; i < this->_map.size(); i++) {
        for (size_t j = 0; j < this->_map[i].size(); j++) {
            if (this->_map[i][j].getNode() == '1')
                continue;
            if (this->_map[i][j].getDormance() == true) {
                this->_map[i][j].setNode('X');
                this->_map[i][j].setLife(true);
                this->_map[i][j].setDormance(false);
            }
            else if (this->_map[i][j].getDormance() == false) {
                this->_map[i][j].setNode('0');
            }
        }
    }
}

std::ostream& operator<<(std::ostream & out, const Map & src) {
    for (const auto& row : src.getMap()) {
        for (const auto& elem : row) {
            out << elem.getNode();
        }
        out << std::endl;
    }
    return out;
}