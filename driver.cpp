//
// Created by jwall on 10/17/2019.
//
/*
#include <cstdlib>
#include "Song.h"
#include "UtPod.h"
#include <iostream>

int main(){
    Song s("Africa","Toto",512);
    Song b("Every Time We Touch", "Casanda",25);
    std::cout << s.getTitle() << " by " << s.getArtist() << endl;
    std::cout << b.getTitle() << " by " << b.getArtist() << endl;
    return 0;
}
*/
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inFile;
    inFile.open("playlist1.txt");
    UtPod t;
    string artist;
    string title;
    string size;
    inFile >> artist;
    while(inFile){
        inFile >> title;
        inFile >> size;
        Song s(title, artist, stoi(size));
        int result = t.addSong(s);
        if(result != 0){
            cout << "Not enough memory remaining to add " << title << " by " << artist << endl;
        }
        inFile >> artist;
    }
    inFile.close();
    cout << "Original List of Songs Displayed Opposite Order of Input File:" << endl<<endl;
    t.showSongList();
    t.sortSongList();
    cout << endl << "Sorted List of Songs:"<<endl<<endl;
    t.showSongList();
    cout << endl << "Shuffled List of Songs:"<<endl<<endl;
    t.shuffle();
    t.showSongList();
    cout << endl << "Reshuffled List of Songs:"<<endl<<endl;
    t.shuffle();
    t.showSongList();
    cout << endl << "Reshuffled List of Songs:"<<endl<<endl;
    t.shuffle();
    t.showSongList();
    Song s1("Homemade","Jake_Owen",12);
    t.removeSong(s1);
    Song s2("Heartless","Diplo",24);
    t.removeSong(s2);
    cout << endl << "Attemped to remove Homemade by Jake_Owen (12MB) and Heartless by Diplo" <<endl<<endl;
    t.showSongList();
    t.sortSongList();
    cout << endl << "Sorted List of Songs after multiple shuffles:"<<endl<<endl;
    t.showSongList();
}
