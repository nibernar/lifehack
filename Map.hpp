#ifndef TAB_HPP
#define TAB_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <GLFW/glfw3.h>
#define TILE_SIZE 50

class Map {
public:
    void checkChar( std::string const & line ) const;
    void checkWall( std::string & line ) const;
    void setMap( const std::string& line );
    std::vector<std::vector<std::string> > getMap() const;
    void parsMap();
    Map();
    ~Map();
private:
    std::vector<std::vector<std::string> > _map;
};

std::ostream & operator<<( std::ostream & out, Map const & src );

#endif