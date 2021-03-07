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

    friend playlistNode* operator + (playlistNode const &listOne, playlistNode const &listTwo) {
        playlistNode *node = new playlistNode;
        SongList *songList = new SongList();

        songList = songList->unionTwoListAnotherRepeatMusic(listOne.songList, listTwo.songList);
        node->songList = songList;

        return node;
    }
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

        PlayList(const PlayList &anotherList) {
            PlayList *newSongList =new PlayList();
            *newSongList = (anotherList);
        }

        void create(string name, SongList songList);

        void listAll();

        void add(string playlistName, SongList *songlist);

        void add(PlayList *playlist, SongList *songList);

        void addSong(Song *song);

        void removeSongs(PlayList *playList, SongList *songList);

        void listAllMusicByPlaylistName(string playlistName);

        string getName();

        void setName(string name);

        playlistNode findPlaylistNode(string playlistName);
};
  
#endif