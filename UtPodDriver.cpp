//
// Created by jwall on 10/17/2019.
//

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inFile;
    inFile.open("playlist1.txt"); //this is the file I created to test an undefined list of songs so that I can easily use multiple test cases
    UtPod t;
    string artist;
    string title;
    int size;
    inFile >> artist;
    while(inFile){
        inFile >> title;
        inFile >> size;
        Song s(title, artist,size);
        int result = t.addSong(s);
        if(result != 0){
            cout << "Not enough memory remaining to add " << title << " by " << artist << ".  ";
            cout << t.getRemainingMemory() << "MB of memory remaining in UtPod." << endl;
        }
        inFile >> artist;
    }
    inFile.close();
    cout << endl << "Original List of Songs Displayed Opposite Order of Input File:" << endl<<endl;
    t.showSongList();
    t.sortSongList();
    cout << endl << "Sorted List of Songs:"<<endl<<endl;
    t.showSongList();
    cout << endl << "Shuffled List of Songs:"<<endl<<endl;
    t.shuffle();
    t.showSongList();
    cout << endl << "Reshuffled List of Songs:"<<endl<<endl;
    t.sortSongList();
    t.shuffle();
    t.showSongList();
    cout << endl << "Reshuffled List of Songs:"<<endl<<endl;
    t.sortSongList();
    t.shuffle();
    t.showSongList();
    Song s1("Homemade","Jake_Owen",12);
    t.removeSong(s1);
    Song s2("Heartless","Diplo",24);
    t.removeSong(s2);
    cout << endl << "Attempted to remove Homemade by Jake_Owen (12MB) and Heartless by Diplo" <<endl<<endl;
    t.showSongList();
    t.sortSongList();
    cout << endl << "Sorted List of Songs after multiple shuffles:"<<endl<<endl;
    t.showSongList();
    cout << endl << "Attempted to remove Africa by Toto then print the error code and list" <<endl;
    Song s3("Africa","Toto",20);
    cout << "error code == " <<  t.removeSong(s3) << endl << endl;
    t.showSongList();
    cout << endl << t.getRemainingMemory() << "MB remaining in memory" << endl;
    
}
