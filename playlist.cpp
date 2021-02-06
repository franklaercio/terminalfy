#include <iostream>

#include "playlist.h"

using namespace std;

void Playlist::create(Song song) {
    node *temp=new node;
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

void Playlist::list() {
    node *temp = new node;
    temp = head;

    int count = 1;

    while(temp != NULL) {
      cout << count << ": " << temp-> data.getTitle() << " - " << temp-> data.getSongwriter() << endl; 
      temp = temp->next;
      count += 1;
    }
}

void Playlist::add(Song song) {
    node *temp = new node;
    temp->data = song;
    temp->next = head;
    head = temp;
}