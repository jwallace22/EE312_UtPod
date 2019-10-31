//
// Created by jwall on 10/17/2019.
//
#include "Song.h"

using namespace std;

Song::Song() {
    title = "Empty";
    artist = "Empty";
    int size = 512;
}

Song::Song(string newTitle, string newArtist, int newSize) {
    title = newTitle;
    artist = newArtist;
    size = newSize;
}

void Song::setArtist(string newArtist) {
    artist = newArtist;
}

void Song::setSize(int newSize) {
    if((newSize > 0)&&(newSize < 512)) {
        size = newSize;
    }
    else{
        size = 512;
    }
}

void Song::setTitle(string newTitle) {
    title = newTitle;
}

string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}

string Song::getTitle() const {
    return title;
}


