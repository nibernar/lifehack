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
    bool getDormance() const;
    void setDormance( bool status );
    Node(const char & c);
    ~Node();
private:
    char _Node;
    bool _dormance;
};

#endif