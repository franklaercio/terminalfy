#include "playlist.h"

using namespace std;

void PlayList::create(string name) {
    playlistNode *temp = new playlistNode;
    temp->name=name;
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

void PlayList::listAll() {
    playlistNode *current = new playlistNode;
    current = head;

    int count = 1;

    if(current == NULL) {
        cout << "Can't found a playlist because your playlist is empty." << endl; 
    }

    while(current != NULL) {
      if(current->name.empty() && count == 1) {
          cout << "Can't found a playlist because your playlist is empty." << endl; 
      }else{
          cout << count << ": " << current->name << endl;
      }    

      current = current->next;

      count += 1;
    }
}