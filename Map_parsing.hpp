#ifndef MAPPARSING_HPP
#define MAPPARSING_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <sstream>

class MapParsing {
public:
    void checkChar( std::string const & line ) const;
    void checkWall( std::string & line ) const;
    void setMapParsing( const std::string& line );
    std::vector<std::vector<std::string> > getMapParsing() const;
    void parsMapParsing();
    MapParsing();
    ~MapParsing();
private:
    std::vector<std::vector<std::string> > _mapParsing;
};

std::ostream & operator<<( std::ostream & out, MapParsing const & src );

#endif