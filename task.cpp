#define _USE_MATH_DEFINES
#include <graphics.h>
#include <task.hpp>
#include <math.h>

Figure::Figure(int rad, int N){
   r = rad;
   n = N;
   external = new coords[n];
}

void Figure::set_external(int i, coords temp){
   external[i].x = temp.x;
   external[i].y = temp.y;
}

void Figure::calc_external_coords(){
   double theta = 0.0;
   for(int i = 0; i<n; i++){
      external[i].x = center.x + r*cos(theta);
      external[i].y = center.y + r*sin(theta);
      theta+=M_PI/3;
   }
}

void Figure::calc_center(){
   int temp_x = 0, temp_y = 0;
   for(int i=0; i<n; i++){
      temp_x += external[i].x;
      temp_y += external[i].y;
   }
   center.x = temp_x/n;
   center.y = temp_y/n;
}

void Figure::draw(){
   for(int i = 0; i<n; i++){
      line(external[i].x, external[i].y, external[(i+1)%n].x, external[(i+1)%n].y);
   }
}

void Figure::remove(){
   setcolor(COLOR(235, 245, 238));
   for(int i = 0; i<n; i++){
      line(external[i].x, external[i].y, external[(i+1)%n].x, external[(i+1)%n].y);
   }
   setcolor(COLOR(70, 35, 122));
}

void Figure::move(int direction){//direction: 0-up, 1-down equals for left and right it's realised with %2
   int d[2] = {-2, 2};
   if(in_field(d[direction%2])){
      remove();
      direction<2?center.y+=d[direction%2]:center.x+=d[direction%2];
      for(int i = 0; i<n; i++){
         direction<2?external[i].y+=d[direction%2]:external[i].x+=d[direction%2];
      }
      draw();
   }else{
      error();
   }
}

void Figure::rotate(int direction, int type){//direction: 0 - rotate left, 1 - rotate right
   int d[2] = {1, -1};
   remove();
   coords temp;
   int reduce = 0;
   rot>0?reduce = -1:reduce=1;
   if(type == 0){
      rot += d[direction];
      for(int i=0; i < n; i++){
         temp.x = center.x+(-center.x+external[i].x)*cos(d[direction]*M_PI/12)+(center.y-external[i].y)*sin(d[direction]*M_PI/12);
         temp.y = center.y+(-center.x+external[i].x)*sin(d[direction]*M_PI/12)+(-center.y+external[i].y)*cos(d[direction]*M_PI/12);
         external[i] = temp;
      }
   }else{
      int temp_rot = rot;
      while(temp_rot != 0){
         for(int i=0; i < n; i++){
            temp.x = center.x+(-center.x+external[i].x)*cos(-reduce*M_PI/12)+(center.y-external[i].y)*sin(-reduce*M_PI/12);
            temp.y = center.y+(-center.x+external[i].x)*sin(-reduce*M_PI/12)+(-center.y+external[i].y)*cos(-reduce*M_PI/12);
            external[i] = temp;
         }
         temp_rot += reduce;
      }
   }
   draw();
}

void Figure::change_size(int direction){
   int d[2] = {-2, 2};
   remove();
   if(in_field(d[direction])){
      r+=d[direction];
      calc_external_coords();
      rotate(0, 1);
   }else{
      error();
   }
}

void Figure::help(int type){//type: 0-about program, 1-move, 2-rotate, 3-change_size
   setbkcolor(COLOR(61, 220, 151));
   bar(670, 45, 1000, 370); 
   switch(type){
      case 0:
         outtextxy(675, 50, "Добро пожаловать!");
         outtextxy(675, 50+textheight("Д"), "Для того чтобы начать");
         outtextxy(675, 50+textheight("Д")*2, "нажми на соответствующую кнопку.");
         outtextxy(675, 50+textheight("Д")*3, "И следуй дальнейшим указаниям.");
         break;
      case 1:
         outtextxy(675, 50, "Ты теперь можешь передвигать фигуру!");
         outtextxy(675, 50+textheight("Д"), "Для того чтобы двигать");
         outtextxy(675, 50+textheight("Д")*2, "нажимай на стрелочки на клавиатуре");
         break;
      case 2:
         outtextxy(675, 50, "Ты теперь можешь поворачивать фигуру!");
         outtextxy(675, 50+textheight("Д"), "Для того чтобы поворачивать фигуру");
         outtextxy(675, 50+textheight("Д")*2, "нажимай на стрелочки (<- или ->) на клавиатуре");
         break;
      case 3:
         outtextxy(675, 50, "Ты теперь можешь изменять размер фигуры!");
         outtextxy(675, 50+textheight("Д"), "Для того чтобы изменять размер фигуры");
         outtextxy(675, 50+textheight("Д")*2, "нажимай на стрелочки (<- или ->) на клавиатуре");
         break;
   }
   setbkcolor(COLOR(235, 245, 238));
}

void Figure::error(){
   setcolor(RED);
   outtextxy(675, 5, "ERROR!!");
   delay(150);
   bar(674, 4, 676+textwidth("ERROR!!"), 6+textheight("ERROR!!"));
   setcolor(COLOR(70, 35, 122));
}

bool Figure::in_field(int dl){
   for(int i=0; i<n; i++){
      if(external[i].x + dl*10 >= 638) return false;
      if(external[i].x - dl*10 < 0) return false;
   }
   return true;
}

void save(){
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.jpg", output);
   freeimage(output);
}