#include <graphics.h>
#include <control.h>

button Buttons[N_CONTROLS];

void create_button(int i, int x, int y){
   Buttons[i].x0 = x;
   Buttons[i].y0 = y;
}

void create_bg(const char *file_name){
   IMAGE *image;
   image = loadBMP(file_name);
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
}

int select_control(){
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if (x > Buttons[i].x0 && x < Buttons[i].x0 + dx &&
          y > Buttons[i].y0 && y < Buttons[i].y0 + dy)
      {
         return i;
      }
   }
   
   return -1;
}