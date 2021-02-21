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
        playlistNode *songList;
        playlistNode *head;
        playlistNode *tail;
    public:
        PlayList() {
            head = NULL;
            tail = NULL;
        }

        void create(string name, SongList songList);

        void listAll();

        void add(string playlistName, SongList *songlist);

        void addSong(Song *song);

        void listAllMusicByPlaylistName(string playlistName);

        SongList getSongListByPlaylistName(string playlistName);

        string getName();

        void setName(string name);

        playlistNode findPlaylistNode(string playlistName);
};	
  
#endif