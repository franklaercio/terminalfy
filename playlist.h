#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include "songlist.h"
#include <string>

using namespace std;

struct playlistNode {
    string name;
    SongList *songList;
    playlistNode *next;
};	

class PlayList {
    private:
        string name;
        SongList *songList;
        playlistNode *head;
        playlistNode *tail;
    public:
        PlayList() {
            songList = new SongList();
            head = NULL;
            tail = NULL;
        }

        void create(string name);

        void listAll();

        void addSong(Song *song);

        string getName();

        void setName(string name);
};	
  
#endif