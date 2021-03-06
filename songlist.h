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

        SongList(const SongList &anotherList) {
            SongList *newSongList =new SongList;
            *newSongList = (anotherList);
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

        friend SongList* operator + (SongList const &s1, SongList const &s2) {
            SongList *result = new SongList();

            node *currentFirstList = new node;
            currentFirstList = s1.head;   

            while(currentFirstList != NULL) {
                result->add(currentFirstList->data);
                currentFirstList = currentFirstList->next;
            }

            node *currentSecondList = new node;
            currentSecondList = s2.head;   

            while(currentSecondList != NULL) {
                result->add(currentSecondList->data);
                currentSecondList = currentSecondList->next;
            }

            return result; 
        }
};	
  
#endif