#include "MusicClipPtr.h"

MusicClipPtr::MusicClipPtr(int i) {
  id = i;
  filestr = filename();
  mclip = NULL;
};

MusicClipPtr::~MusicClipPtr() {
  delete mclip;
}

char* MusicClipPtr::filename() {
  char filepart1[] = "mclip_";
  char filepart2[] = ".clip";

  std::ostringstream oss;
  oss<<id; //convert int to stringstream

  char * filenumber = const_cast<char*>( oss.str().c_str()); //convert stringstream to char array

  char *file_name = new char(std::strlen(filepart1) + std::strlen(filenumber) + std::strlen(filepart2));
  std::strcpy(file_name, filepart1);
  std::strcat(file_name, filenumber);
  std::strcat(file_name, filepart2);
  return file_name;
}

void MusicClipPtr::loadFromFile() {
  std::ifstream clipfile(filestr);
  std::string line;

  int c_index, c_id;
  std::string c_artist, c_title;
  // std::vector<std::string> c_people;
  int c_genre;
  // // public** clip;
  double c_price;
  if (clipfile.is_open())
  {
    std::cout << "loadfrom file" << std::endl;
    getline(clipfile, line);
    std::stringstream s(line);
    s >> c_id; //clip id

    getline(clipfile, line);
    std::stringstream t(line);
    t >> c_index; //clip index

    getline(clipfile, c_title); //clip title

    getline(clipfile, line);
    std::stringstream u(line);
    u >> c_genre; //clip genre

    getline(clipfile, c_artist); //clip artist

    getline(clipfile, line); //clip people - to be handled and created as a vector

    getline(clipfile, line);
    std::stringstream v(line);
    v >> c_price; //clip price

    mclip = new MusicClip();
    mclip->setId(c_id);
    mclip->setTitle(c_title);
    mclip->setArtist(c_artist);
    mclip->setGenre(c_genre);
    mclip->setPrice(c_price);
    clipfile.close();
  } else {
    std::cout <<"File not opened" << std::endl;
  }

}

void MusicClipPtr::saveToFile() {
  std::ofstream clipfile;
  clipfile.open(filestr);
  clipfile << "Writing this to file" << std::endl << "Another line" << std::endl << "another line" << std::endl;
  clipfile.close();
}


void MusicClipPtr::dispdetails() {
  std::cout << "File Name is : " << filestr << std::endl << "Id is : " << id << std::endl;
}

MusicClip* MusicClipPtr::operator-> () {
  std::cout << "Inside overload method" << std::endl;
  if(mclip == NULL) {
    loadFromFile();
  }
  return mclip;
}

MusicClip& MusicClipPtr::operator* () {
  if(mclip == NULL) {
    loadFromFile();
  }
  return *mclip;
}
