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

    void saveToFile();
    void loadFromFile();
    void newClip();
    char* filename();
    void dispdetails();

  private:  //Private declarations
    int id; 
    char * filestr; //Char array for the filename of the musicclip
    MusicClip* mclip; //Instance of MusicClip 

    MusicClipPtr(const MusicClipPtr&);
    MusicClipPtr& operator=(const MusicClipPtr&);

    static const char digits[];
};
