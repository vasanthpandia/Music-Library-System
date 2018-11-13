#include "MusicClip.h"

int MusicClip::getId() {
  return id;
}

std::string MusicClip::getArtist() {
  return artist;
}

std::string MusicClip::getGenre() {
  return genre;
}

double MusicClip::getPrice() {
  return price;
}

int MusicClip::setId(int x) {
  id = x;
  return id;
}

std::string MusicClip::setArtist(std::string x) {
  artist = x;
  return artist;
}

std::string MusicClip::setGenre(std::string x) {
  genre = x;
  return genre;
}

double MusicClip::setPrice(double x) {
  price = x;
  return price;
}

