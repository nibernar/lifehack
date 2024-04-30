#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include "Map.hpp"

class Node {
public:
    void checkCase( const std::vector<std::vector<Node>>& map, size_t i, size_t j );
    void setNode( char c );
    char getNode() const;
    bool getLife() const;
    bool getDormance() const;
    void setLife( bool status );
    void setDormance( bool status );
    Node(const char & c);
    ~Node();
private:
    char _Node;
    bool _life;
    bool _dormance;
};

#endif