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

std::vector<std::string> MusicClip::setPeople(std::vector<std::string> x) {
  people = x;
  return people;
}

void MusicClip::displayclip() {
  std::cout<<"**********" <<std::endl;
  std::cout << id << std::endl << title  << std::endl << artist << std::endl << genre << std::endl << price << std::endl;
  std::cout<<"**********" <<std::endl;
}
