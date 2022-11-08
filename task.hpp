#ifndef TASK_HPP
#define TASK_HPP

struct coords{
   int x;
   int y;
};

class hexagon{
   private:
      coords center;
      int r;
   public:
      hexagon(int x, int y);
      void hexagon_remove();
      void hexagon_draw();
      void move(int type);
      void rotate(int direction);
      void change_size(int direction);
}

#endif