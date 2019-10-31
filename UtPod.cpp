//
// Created by jwall on 10/17/2019.
//
#include "UtPod.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
    int currentTime = time(0);
    srand(currentTime);
}

UtPod::UtPod(int size) {
    int currentTime = time(0);
    srand(currentTime);
    if((size > MAX_MEMORY)||(size<1)) {
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() < s.getSize()){
        return -1;
    }
    else{
        SongNode *newSong = new SongNode;
        newSong->s = s;
        newSong->next = songs;
        songs = newSong;
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode* previous = NULL;
    SongNode* current = songs;
    int status = -1;
    while(current != NULL){
        if((current->s.getArtist()) == (s.getArtist()) && ((current->s.getTitle())==(s.getTitle()))){
            status = SUCCESS;
            if(previous==NULL){
                songs = current->next;
                delete current;
            }
            else{
                previous->next = current ->next;
                delete current;
            }
            current = NULL;
        }
        else{
            previous = current;
            current = current->next;
        }
    }

    return status;
}

void UtPod::showSongList() {
    SongNode* current = songs;
    while(current != NULL){
        cout << current ->s.getTitle() << ", " << current ->s.getArtist() << ", " << current ->s.getSize() << "MB"<<endl;
        current = current->next;
    }

}

UtPod::~UtPod() {
    clearMemory();
}

int UtPod::getRemainingMemory() {
    int memUsed = 0;
    SongNode* current = songs;
    while(current != NULL){
        memUsed += current->s.getSize();
        current = current->next;
    }
    return memSize - memUsed;
}

void UtPod::clearMemory() {
    SongNode* current = songs;
    SongNode* nextNode;
    while(current != NULL){
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    songs = NULL;
}

void UtPod::shuffle() {
    int size = 0;
    SongNode *current = songs;
    while(current != NULL){ //Finding the size of the linked list
        size += 1;
        current = current ->next;
    }
    for(int i = 0; i < 2000;i++){
        int swapIndex = rand()%(size);
        SongNode *p1 = songs;
        for(int j = 0; j<swapIndex; j++){
            p1=p1->next;
        }
        swapIndex = rand()%(size);
        SongNode *p2 = songs;
        for(int j = 0; j<swapIndex; j++){
            p2=p2->next;
        }
        Song tempSong = p1->s;
        p1->s = p2->s;
        p2->s = tempSong;
    }

}

void UtPod::sortSongList() {
    bool sorted = false;
    while(!sorted){
        SongNode* current = songs;
        SongNode*previous = NULL;
        sorted = true;
        while(current->next != NULL){
            SongNode* nextSong = current->next;
            if((current->s) > (nextSong->s)){
                if(previous==NULL){
                    songs = nextSong;
                }
                else{
                    previous->next = nextSong;
                }
                previous = nextSong;
                SongNode* temp = nextSong->next;
                nextSong->next = current;
                current->next = temp;
                sorted = false;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
    }
}




