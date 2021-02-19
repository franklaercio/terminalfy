#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>

using namespace std;

class Song {
    private:
        string title;
        string songwriter;

    public:
        string getTitle();

        void setTitle(string title);

        string getSongwriter();
        
        void setSongwriter(string songwriter);
};

#endif