#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

using namespace std;

struct node {
    Song data;
    node *next;
};	

class Playlist {
    private:
        node *head;
        node *tail;
    public:
        Playlist() {
            head = NULL;
            tail = NULL;
        }
        
        void create(Song song);

        void add(Song song);

        void list();
};	
  
#endif