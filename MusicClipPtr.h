#include "MusicClip.h"

class MusicClipPtr {

  //Public declarations.
  public:
  MusicClipPtr(int);
  ~MusicClipPtr();
  MusicClip* operator->() const;
  MusicClip& operator*() const;

  protected:
  int id;
  MusicClip* mclip;

  MusicClipPtr(const MusicClipPtr&);
  MusicClipPtr& operator=(const MusicClipPtr&);

  std::string filename();

}
