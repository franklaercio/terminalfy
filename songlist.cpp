#include <iostream>

#include "songlist.h"

using namespace std;

/**
 *  Function for create the songlist node
 *  
 *  @return
*/
void SongList::create(Song song) {
    node *temp = new node;
    temp->data = song;
    temp->next=NULL;
    
    if(head==NULL) {
        head=temp;
        tail=temp;
        temp=NULL;
    } else {	
        tail->next=temp;
        tail=temp;
    }
}

/**
 *  Function for list all of music
 *  
 *  @return
*/
void SongList::list() {
    node *current = new node;
    current = head;   

    int count = 1;

    if(current == NULL) {
        cout << "Can't found a song because your songlist is empty." << endl; 
    }

    while(current != NULL) {
      if(current->data.getTitle().empty() && count == 1) {
          cout << "Can't found a song because your songlist is empty." << endl; 
      }else{
          cout << count << ": " << current-> data.getTitle() << " - " << current-> data.getSongwriter() << endl;
      }    

      current = current->next;

      count += 1;
    }
}

/**
 *  Function for find the song in songlist
 *  
 *  @return Song
*/
Song SongList::findSong(string songName) {
    node *current = new node;
    current = head;

    int count = 1;

    Song *song = new Song();

    if(current == NULL) {
        cout << "Can't found a song because your songlist is empty." << endl; 
        return *song;
    }

    while(current != NULL) {
      if(current->data.getTitle().compare(songName) == 0) {
          song = &current->data;
          return *song;
      }   

      current = current->next;
    }

    cout << "Can't found the music." << endl;
    return *song;
}

/**
 *  Function for add the song in songlist
 *  
 *  @return
*/
void SongList::add(Song song) {
    node *temp = new node;
    temp->data = song;
    temp->next = head;
    head = temp;
}

/**
 *  Function for remove a song in songlist
 *  
 *  @return
*/
void SongList::remove(string songTitle) {
    node *current=new node;
    node *previous=new node;

    current=head;

    while(current != NULL) {
        string title = current->data.getTitle();
        
        if((title.compare(songTitle)) == 0) { 
            break; 
        } else {
            previous = current; 
            current = current->next;
        }
    }

    if(current == NULL) {
        cout << "Can't remove value: no match found." << endl; 
    } else {
        cout << "Deleting: " << current->data.getTitle() << endl;
        previous->next = current->next;
        delete current;
    }
}