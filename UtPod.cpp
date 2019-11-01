//
// Created by jwall on 10/17/2019.
//
#include "UtPod.h"
#include "Song.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL; // pointer to the head of the linked list
    int currentTime = time(0); //seeding the random function so that shuffle works properly
    srand(currentTime);
}

UtPod::UtPod(int size) {
    int currentTime = time(0);
    srand(currentTime); //seeding the random function so that shuffle works properly
    if((size > MAX_MEMORY)||(size<1)) {
        memSize = MAX_MEMORY; // default memory size is 512
    }
    else{
        memSize = size;
    }
    songs = NULL; // pointer to the head of the linked list
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() < s.getSize()){
        return NO_MEMORY; //there is not enough memory left to add the song in the parameter
    }
    else{
        SongNode *newSong = new SongNode; //dynamically allocating memory for each song node
        newSong->s = s;
        newSong->next = songs;
        songs = newSong;
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode* previous = NULL;
    SongNode* current = songs;
    int status = NOT_FOUND;
    while(current != NULL){
        if(current->s == s){ //using the overloaded == comparison operator
            status = SUCCESS;
            if(previous==NULL){ //checking for if the song to be removed is at the top of the list
                songs = current->next;
                delete current; //freeing up the dynamically allocated memory for the node
            }
            else{ //if the song is in the middle or at the end, simply move the node pointers
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

    return status; //if no songs in the list match the parameter, the default status is NOT_FOUND
}

void UtPod::showSongList() {
    SongNode* current = songs;
    while(current != NULL){ //iterate through the song list showing each song
        cout << current ->s.getTitle() << ", " << current ->s.getArtist() << ", " << current ->s.getSize() << "MB"<<endl;
        current = current->next;
    }

}

UtPod::~UtPod() {
    clearMemory(); //failsafe so that no memory leaks are left when the UtPod falls out of scope
}

int UtPod::getRemainingMemory() {
    int memUsed = 0;
    SongNode* current = songs;
    while(current != NULL){ //iterated through the linked list summing the memory used to subtract from the total
        memUsed += current->s.getSize();
        current = current->next;
    }
    return memSize - memUsed;
}

void UtPod::clearMemory() {
    SongNode* current = songs;
    SongNode* nextNode; //move through the linked list freeing up all the dynamically allocated memory
    while(current != NULL){
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    songs = NULL; //reset the head to NULL so more songs can be added
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




