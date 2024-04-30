#include "Node.hpp"

Node::Node(const char & c) : _Node(c), _life(false), _dormance(false) {

}

Node::~Node() {

}

bool Node::getLife() const {
    return this->_life;
}

bool Node::getDormance() const {
    return this->_dormance;
}

void Node::setLife( bool status ) {
    this->_life = status;
}

void Node::setDormance( bool status ) {
    this->_dormance = status;
}

char Node::getNode() const {
    return this->_Node;
}

void Node::setNode( char c ) {
    this->_Node = c;
}

void Node::checkCase( const std::vector<std::vector<Node>>& map, size_t i, size_t j ) {
    int dRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int life = 0;
    for (int k = 0; k < 8; k++) {
        size_t ni = i + dRow[k];
        size_t nj = j + dCol[k];
        if (ni >= 0 && ni < map.size() && nj >= 0 && nj < map[0].size()) {
            const Node & neighbor = map[ni][nj];
            if (neighbor.getLife() == true) {
                life += 1;
            }
        }
    }
    if (this->getLife() == true)
    {
        if (life == 2 || life == 3)
            this->setDormance(true);
        // else
        //     this->setDormance(false);
    }
    else
    {
        if (life == 3)
            this->setDormance(true);
        // else
        //     this->setDormance(false);
    }
}
