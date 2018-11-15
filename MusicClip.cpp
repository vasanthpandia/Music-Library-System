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

MusicClip::Genre MusicClip::getGenre() {
  return genre;
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

MusicClip::Genre MusicClip::setGenre(Genre x) {
  genre = x;
  return genre;
}

double MusicClip::setPrice(double x) {
  price = x;
  return price;
}

std::vector<std::string> MusicClip::setPeople(std::vector<std::string> x) {
  people = x;
  return people;
}
