#include "MusicClip.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include<string>

class MusicClipPtr {

  public:   //Public declarations.
    MusicClipPtr(int);
    ~MusicClipPtr();
    MusicClip* operator->();
    MusicClip& operator*();

    MusicClipPtr(const MusicClipPtr&);
    MusicClipPtr& operator=(const MusicClipPtr&);

    void dispdetails();

  private:  //Private declarations
    int id; 
    char * filestr; //Char array for the filename of the musicclip
    MusicClip* mclip; //Instance of MusicClip 

    void saveToFile();
    void loadFromFile();
    void newClip();
    char* filename();

};
