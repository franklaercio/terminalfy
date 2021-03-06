#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"

using namespace std;

struct node {
    Song data;
    node *next;
};	

class SongList {
    private:
        int size;
        node *head;
        node *tail;
    public:
        SongList() {
            head = NULL;
            tail = NULL;
        } 
        
        void create(Song song);

        Song findSong(string songName);

        void listAllMusicBySongList(SongList *songList);

        void add(Song song);

        void add(SongList *songList);

        void remove(string songTitle);

        void remove(SongList *songList);

        void list();

        int getSize();

        void setSize(int size);
};	
  
#endif