#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <GLFW/glfw3.h> 
#include "Node.hpp"
#define WIDTH 1800
#define HEIGHT 1600

class Node;

class Map {
public:
    void generation();
    void update();
    void setMap( std::vector<std::vector<std::string> > vec );
    std::vector<std::vector<Node> > getMap() const;
    Map();
    ~Map();
private:
    std::vector<std::vector<Node> > _map;
};

std::ostream & operator<<( std::ostream & out, Map const & src );

#endif