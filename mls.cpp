#include<iostream>
#include<stdio.h>
#include "Node.h"

int main() {
  MusicClipPtr d = MusicClipPtr(1);
  Node a = Node(d);
  // MusicClipPtr a = MusicClipPtr(1); 
  // MusicClipPtr& b = a;

  a.getClip()->displayclip();

  return 0;
}