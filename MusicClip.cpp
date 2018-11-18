#include "MusicClip.h"

int MusicClip::getId() {
  return id;
}

std::string MusicClip::getArtist() {
  return artist;
}

std::string MusicClip::getTitle() {
  return title;
}

int MusicClip::getGenre() {
  return static_cast<int>(genre);
}

double MusicClip::getPrice() {
  return price;
}

std::vector<std::string> MusicClip::getPeople() {
  return people;
}

int MusicClip::setId(int x) {
  id = x;
  return id;
}

std::string MusicClip::setArtist(std::string x) {
  artist = x;
  return artist;
}

std::string MusicClip::setTitle(std::string x) {
  title = x;
  return title;
}

int MusicClip::setGenre(int x) {
  genre = static_cast<MusicClip::Genre>(x);
  return static_cast<int>(genre);
}

double MusicClip::setPrice(double x) {
  price = x;
  return price;
}

std::vector<std::string> MusicClip::setPeople(std::string x) {
  people = tokenisePeople(x);
  return people;
}

std::string MusicClip::getClip() {
  return clip;
}

void MusicClip::setClip(std::string cl) {
  clip = cl;
} 

void MusicClip::displayclip() {
  std::cout<<"**********" <<std::endl;
  std::cout << id << std::endl << title  << std::endl << artist << std::endl << genre << std::endl;
  for(int i = 0; i < people.size(); ++i) {
    std::cout << people[i] << ",";
  }
  std::cout << std::endl << price << std::endl;
  std::cout<<"**********" <<std::endl;
}

std::vector<std::string> MusicClip::tokenisePeople(std::string s)
{
    std::vector<std::string> v;

    std::string str;

    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] != ',')
        {
            str += std::string(1, s[i]);
        }
        else if(s[i] == ',')
        {
            v.push_back(str);
            str.clear();
        }
    }
   
    v.push_back(str);
    str.clear();

    return v;
}
