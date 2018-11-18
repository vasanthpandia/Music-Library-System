#include<iostream>
#include<stdio.h>
#include "LinkedList.h"

void listCommand(LinkedList&);
void setCurrentClip(MusicClipPtr& clip, LinkedList& list, std::string str);
void editPrice(MusicClipPtr& clip, std::string str);
void commandMessage();
void execCommands();

void execCommands() {
  /*Create 10 MusicClipPtr objects*/
  MusicClipPtr c0 = MusicClipPtr(0);
  MusicClipPtr c1 = MusicClipPtr(1);
  MusicClipPtr c2 = MusicClipPtr(2);
  MusicClipPtr c3 = MusicClipPtr(3);
  MusicClipPtr c4 = MusicClipPtr(4);
  MusicClipPtr c5 = MusicClipPtr(5);
  MusicClipPtr c6 = MusicClipPtr(6);
  MusicClipPtr c7 = MusicClipPtr(7);
  MusicClipPtr c8 = MusicClipPtr(8);
  MusicClipPtr c9 = MusicClipPtr(9);

  /*Create Nodes with MusicClipPtr for LinkedList*/
  Node n0 = Node(c0);
  Node n1 = Node(c1);
  Node n2 = Node(c2);
  Node n3 = Node(c3);
  Node n4 = Node(c4);
  Node n5 = Node(c5);
  Node n6 = Node(c6);
  Node n7 = Node(c7);
  Node n8 = Node(c8);
  Node n9 = Node(c9);

  /*Initialize Linkedlist and push nodes*/
  LinkedList l = LinkedList();
  l.push(&n0);
  l.push(&n1);
  l.push(&n2);
  l.push(&n3);
  l.push(&n4);
  l.push(&n5);
  l.push(&n6);
  l.push(&n7);
  l.push(&n8);
  l.push(&n9);

  /*Vector of MusicClipPtr& for those that would be loaded in memory*/
  // std::vector<MusicClipPtr&> inMemoryClips;
  // inMemoryClips.reserve(3);

  MusicClipPtr currentClip = l.getHead()->getClip();

  int input = 1;
  std::string inputstr;

  while(input == 1) {
    commandMessage();
    std::cout << "Enter the command : ";
    std::getline(std::cin, inputstr);

    switch(inputstr[0]) {
      case 'l': listCommand(l);
        break;
      case 'e': setCurrentClip(currentClip, l, inputstr);
        break;
      case 'c': break;
      case 'y': break;
      case 'i': break;
      case 'p': editPrice(currentClip, inputstr);
        break;
      case 's': break;
      case 'q': input = 0;
        break;
      default: break;
    }
  }

}

void listCommand(LinkedList& list) {
  Node* node = list.getHead();

  for(int i = 0; i < 10; i++ ) {
    node->getClip()->displayclip();
    node = node->getNext();
  }
}

void editPrice(MusicClipPtr& clip, std::string str) {
  std::string price = str.substr(2);
  std::stringstream ss(price);
  double d;
  ss >> d;

  clip->setPrice(d);

  std::cout << "Price of current clip changed to " << clip->getPrice();
}

void setCurrentClip(MusicClipPtr& clip, LinkedList& list, std::string str) {
  char a = str[2];

  int num = a - 48;

  Node* node = list.getHead();

  for(int i = 0; i < num; i++) {
    node = node->getNext();
  }
  // clip
  clip = node->getClip();

  std::cout <<"Current clip changed to " << clip->getId() << std::endl;
}

void commandMessage() {
  std::cout << "Enter the commands in following formats " << std::endl;
  std::cout << "l to list all music clips" <<std::endl << "e <index> to edit the clip of index" << std::endl << "c to create a clip" << std::endl << "y to copy current clip to temp" << std::endl << "i to read commands from input file" << std::endl << "p to change price of the current clip" << std::endl << "s to save all clips" << std::endl << "q to quit MLS" << std::endl;
}

int main() {
  std::cout << "::: Welcome to Music Library System :::" << std::endl;
  
  execCommands();
  return 0;
} 
