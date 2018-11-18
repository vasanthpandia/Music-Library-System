#include "Node.h"

Node::Node(MusicClipPtr& index) {
  clip = index;
  next = NULL;
}

MusicClipPtr& Node::getClip() {
  return clip;
}

// void Node::setClip(MusicClipPtr& i) {
//   clip = i;
// }

void Node::setNext(Node* newNext) {
  if(newNext == NULL) {
    next = NULL;
  } else {
    next = newNext;
  }
}

Node* Node::getNext() {
  return next;
}
