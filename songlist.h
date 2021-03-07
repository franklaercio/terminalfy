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
            SongList *newSongList =new SongList();
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

        SongList* unionTwoListAnotherRepeatMusic(SongList *one, SongList *two);

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

        void operator >> (SongList const &s1) {
            node *current=new node;
            node *previous=new node;

            current = s1.head;

            while(current != NULL) {
                if(current->next == NULL) {
                    break;
                }

                previous = current; 
                current = current->next;
            }

            if(current != NULL) {
                cout << "Deleting: " << current->data.getTitle() << endl;
                previous->next = current->next;

                delete current;
            }else{
                cout << "Can't delete last music, bescause your songlist is empty!" << endl;
            }
        }

        friend void operator << (SongList *list, Song const &song) {
            node *previous=new node;

            previous = list->head;

            if(previous != NULL) {
               while(previous != NULL) {
                    if(previous->next == NULL) {
                        break;
                    }

                    previous = previous->next;
                }

                node *temp = new node;
                temp->data = song;
                temp->next = NULL;

                previous->next = temp;
            }else{
                list->add(song);
            }
        }    
};	
  
#endif