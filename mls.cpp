#include<iostream>
#include<stdio.h>
#include "MusicClipPtr.h"


int main() {
  MusicClipPtr a(1); // = new MusicClipPtr(1);
  // std::string mystring;
  // double price;
  // int genre;
  // a->id = 1;

  // std::cout <<"Enter the value for genre : "<<std::endl;
  // getline(std::cin, mystring);
  // a->setGenre(mystring);
  // std::cout <<"Enter the Artist : "<<std::endl;
  // getline(std::cin, mystring);
  // a->setArtist(mystring);
  // std::cout <<"Enter the price of the audio : "<< std::endl;
  // std::cin >> price;
  // a->setPrice(price);
  // std::cout << "Enter the genre of the clip : " << std::endl;
  // std::cin>>genre;
  // a->setGenre(genre);
  a->displayclip();

  return 0;
}