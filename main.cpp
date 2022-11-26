#include <iostream>
#include <graphics.h>
#include <task.hpp>
#include <math.h>
#include <control.h>
#include <fstream>

using namespace std;

int main(){
   int type = 0, radius, n;//type: 0-не нажата никая кнопка, 1-move, 2-rotate, 3-resize
   
   ifstream file;
   file.open("info_for_figure.txt");
   file >> n;//get number of vertex
   coords temp[n];
   for(int i=0; i<n; i++){
      file >> temp[i].x >> temp[i].y;//get coords of vertex from file
   }
   Figure a = Figure(fabs(temp[0].x-temp[5].x)/2, n);
   for(int i=0; i<n; i++){
      a.set_external(i, temp[i]);
   }
   a.calc_center();
   initwindow(WIDTH, HEIGHT, "well...");
   create_bg("bg.jpg");
   create_button(MOVE, 657, 378);
   create_button(ROTATE, 657, 463);
   create_button(RESIZE, 657, 547);
   create_button(SAVE, 657, 632);
   create_button(EXIT, 657, 718);
   setbkcolor(COLOR(235, 245, 238));
   setcolor(COLOR(70, 35, 122));
   setfillstyle(SOLID_FILL, COLOR(61, 220, 151));
   a.draw();
   a.help(0);
   while(1){
      while(mousebuttons() != 1){
         switch(type){
            case 1:
               switch(getch(kbhit())){
                  case KEY_UP:
                     a.move(0);
                     break;
                  case KEY_DOWN:
                     a.move(1);
                     break;
                  case KEY_LEFT:
                     a.move(2);
                     break;
                  case KEY_RIGHT:
                     a.move(3);
                     break;
               }
               break;
            case 2:
               switch(getch(kbhit())){
                  case KEY_LEFT:
                     a.rotate(0, 0);
                     break;
                  case KEY_RIGHT:
                     a.rotate(1, 0);
                     break;
               }
               break;
            case 3:
               switch(getch(kbhit())){
                  case KEY_LEFT:
                     a.change_size(0);
                     break;
                  case KEY_RIGHT:
                     a.change_size(1);
                     break;
               }
               break;
         }
      }
      switch(select_control()){
         case MOVE:
            a.help(1);
            type = 1;
            break;
         case ROTATE:
            a.help(2);
            type = 2;
            break;
         case RESIZE:
            a.help(3);
            type = 3;
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}