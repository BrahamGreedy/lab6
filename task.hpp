#ifndef TASK_HPP
#define TASK_HPP
#define HEIGHT 800
#define WIDTH 1000

struct coords{
   double x;
   double y;
};

class hexagon{
   private:
      coords center;
      coords external[6];
      int r;
      int rot=0;
      void calc_external_coords();
   public:
      hexagon(double x, double y, int rad);
      void hexagon_remove();
      void hexagon_draw();
      void move(int direction);
      void rotate(int direction, int type);
      void change_size(int direction);
      void help(int type);
      void error();
      bool in_field(int dx);
};

void save();

#endif