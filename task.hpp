#ifndef TASK_HPP
#define TASK_HPP
#define HEIGHT 800
#define WIDTH 1000

struct coords{
   int x;
   int y;
};

class Figure{
   private:
      coords center;
      coords external[6];
      int r;
      int n;
      int rot=0;
      void calc_external_coords();
   public:
      Figure(int rad, int N);
      void set_external(int, coords);
      void calc_center();
      void remove();
      void draw();
      void move(int direction);
      void rotate(int direction, int type);
      void change_size(int direction);
      void help(int type);
      void error();
      bool in_field(int dx);
};

void save();

#endif