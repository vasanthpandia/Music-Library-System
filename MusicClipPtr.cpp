#include "MusicClipPtr.h"

std::string MusicClipPtr::filename() {
  std::string file = "clip-" + std::to_string(id) + ".clip";
}