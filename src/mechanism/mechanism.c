/*

mechanism.c

game logic

*/
struct position
{
  int x;
  int y;
};

struct player
{
  struct position player_position;
  int id;
  int points;
};

struct game
{
  struct player player;
  struct position apple_position;
};
