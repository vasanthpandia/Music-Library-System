#include<iostream>
class MusicClip {

  // enum Genre {  "POP MUSIC" = 1, "FOLK MUSIC", "JAZZ", "BLUES", "CLASSICAL", "OPERA", "COUNTRY MUSIC", "REGGAE", "ROCK" };

  /* Data Member declaration */
  private: int id;
  private: std::string artist;
  private: std::string genre;
  // public** clip;
  private: double price;

  /* Getter methods */
  public: int getId();
  public: std::string getArtist();
  public: std::string getGenre();
  public: double getPrice();

  /* Setter Methods */
  public: int setId(int);
  public: std::string setArtist(std::string);
  public: std::string setGenre(std::string);
  public: double setPrice(double);
};