#include<iostream>
#include<stdio.h>
#include "MusicClip.h"

int main() {
  MusicClip *a = new MusicClip();
  std::string mystring;
  double price;
  // a->id = 1;

  std::cout <<"Enter the value for genre : "<<std::endl;
  getline(std::cin, mystring);
  a->setGenre(mystring);
  std::cout <<"Enter the Artist : "<<std::endl;
  getline(std::cin, mystring);
  a->setArtist(mystring);
  std::cout <<"Enter the price of the audio : "<< std::endl;
  std::cin >> price;
  a->setPrice(price);

  std::cout<< a->getPrice();

  return 0;
}