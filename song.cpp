#include "song.h"

string Song::getTitle() {
    return this -> title;
}

void Song::setTitle(string title) {
    this -> title = title;
}

string Song::getSongwriter() {
    return this -> songwriter;
}

void Song::setSongwriter(string songwriter) {
    this -> songwriter = songwriter;
}