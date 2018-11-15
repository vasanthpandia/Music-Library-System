#include <iostream>
#include <vector>

class MusicClip {

  enum Genre {  POP_MUSIC,
    FOLK_MUSIC,
    JAZZ,
    BLUES, 
    CLASSICAL, 
    OPERA, 
    COUNTRY_MUSIC, 
    REGGAE,
    ROCK
  };

  private:

  /* Data Member declaration */
  int id, index;
  std::string artist, title;
  std::vector<std::string> people;
  Genre genre;
  // public** clip;
  double price;

  public:

  /* Getter methods */
  int getId();
  std::string getArtist();
  Genre getGenre();
  double getPrice();

  /* Setter Methods */
  int setId(int);
  std::string setArtist(std::string);
  Genre setGenre(Genre);
  double setPrice(double);
};
