#include "song.h"

/**
 *  Function for return the song title
 *  
 *  @return string
*/
string Song::getTitle() {
    return this -> title;
}

/**
 *  Function for setting the song title
*/
void Song::setTitle(string title) {
    this -> title = title;
}

/**
 *  Function for return the name of song writer
 *  
 *  @return string
*/
string Song::getSongwriter() {
    return this -> songwriter;
}

/**
 *  Function for setting the name of song writer
*/
void Song::setSongwriter(string songwriter) {
    this -> songwriter = songwriter;
}