#include "MusicClipPtr.h"

MusicClipPtr::MusicClipPtr(int i) {
  id = i;
  filestr = filename();
  mclip = NULL;
};

MusicClipPtr::MusicClipPtr() {
}

MusicClipPtr::~MusicClipPtr() {
  if(mclip != NULL) {
    saveToFile();
  }
  delete mclip;
}

// MusicClipPtr::MusicClipPtr(const MusicClipPtr& objref) {
//   id = objref.id;
//   filestr = objref.filestr;
//   mclip = objref.mclip;
// }

// MusicClipPtr&::MusicClipPtr& operator=(const MusicClipPtr& obj) {
//   id = obj->id;
//   filestr = obj->filestr;
//   mclip = obj->mclip;
// }

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
  std::string c_artist, c_title, c_people, c_clip;
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

    getline(clipfile, c_people); //clip people - to be handled and created as a vector

    getline(clipfile, line);
    std::stringstream v(line);
    v >> c_price; //clip price

    getline(clipfile, c_clip); //clip

    mclip = new MusicClip();
    mclip->setId(c_id);
    mclip->setTitle(c_title);
    mclip->setArtist(c_artist);
    mclip->setGenre(c_genre);
    mclip->setPrice(c_price);
    mclip->setPeople(c_people);
    mclip->setClip(c_clip);
    clipfile.close();
  } else {
    std::cout <<"File not opened" << std::endl;
  }

}

void MusicClipPtr::saveToFile() {
  std::ofstream clipfile;
  clipfile.open(filestr);
  clipfile << mclip->getId() << std::endl << mclip->getId() << std::endl << mclip->getTitle() << std::endl << mclip->getArtist()<< std::endl << mclip->getGenre() << std::endl;
  std::vector<std::string> peeps = mclip->getPeople();
  for(int i = 0; i < peeps.size(); i++) {
    clipfile << peeps[i] << " ";
  }
  clipfile << std::endl << mclip->getPrice() << std::endl << mclip->getClip() << std::endl;
  clipfile.close();
}

void MusicClipPtr::dcopy() {
  if(mclip == NULL) {
    loadFromFile();
  }

  std::ofstream clipfile;
  clipfile.open("temp.clip");
  clipfile << mclip->getId() << std::endl << mclip->getId() << std::endl << mclip->getTitle() << std::endl << mclip->getArtist()<< std::endl << mclip->getGenre() << std::endl;
  std::vector<std::string> peeps = mclip->getPeople();
  for(int i = 0; i < peeps.size(); i++) {
    clipfile << peeps[i] << " ";
  }
  clipfile << std::endl << mclip->getPrice() << std::endl << mclip->getClip() << std::endl;
  clipfile.close();
}

void MusicClipPtr::createClip() {
  std::string mc_title, mc_artist, mc_people, mc_clip;
  int mc_genre, mc_id;
  double mc_price;
  mclip = NULL;
  mc_id = id;
  std::cout << std::endl << "Enter the clip title : ";
  std::getline(std::cin, mc_title);
  std::cout << std::endl << "Enter the Name of the artist : ";
  std::getline(std::cin, mc_artist);
  std::cout << std::endl << "Enter the name of the people associated as comma seperated values : ";
  std::getline(std::cin, mc_people);
  std::cout << std::endl << "Enter the genre of the song : ";
  std::cin >> mc_genre;
  std::cout << std::endl << "Enter the price of the song : ";
  std::cin >> mc_price;
  std::cout << std::endl <<"Enter or paste the contents for clip field : ";
  std::cin.ignore();
  std::getline(std::cin, mc_clip);

  std::cout  << std::endl << "New clip is getting created" << std::endl;

  mclip = new MusicClip();
  mclip->setId(mc_id);
  mclip->setTitle(mc_title);
  mclip->setArtist(mc_artist);
  mclip->setGenre(mc_genre);
  mclip->setPrice(mc_price);
  mclip->setPeople(mc_people);
  mclip->setClip(mc_clip);

  saveToFile();

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
