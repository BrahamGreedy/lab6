#define _USE_MATH_DEFINES




hexagon::hexagon(int x, int y, int rad){
   center.x = x;
   center.y = y;
   r = rad;
   calc_external_coords();
}

void hexagon::calc_external_coords(){
   double theta = 0.0;
   for(int i = 0; i<6; i++){
      external[i].x = center.x + r*cos(theta);
      external[i].y = center.y + r*sin(theta);
      theta+=M_PI/3;
   }
}

void hexagon::hexagon_draw(){
   for(int i = 0; i<6; i++){
      line(external[i].x, external[i].y, external[(i+1)%6].x, external[(i+1)%6].y);
   }
}

void hexagon::hexagon_remove(){
   setcolor(COLOR(235, 245, 238));
   for(int i = 0; i<6; i++){
      line(external[i].x, external[i].y, external[(i+1)%6].x, external[(i+1)%6].y);
   }
   setcolor(COLOR(70, 35, 122));
}

void hexagon::move(int direction){//direction: 0-up, 1-down equals for left and right it's realised with %2
   int d[2] = {-2, 2};
   direction<2?center.y+=d[direction%2]:center.x+=d[direction%2];
   hexagon_remove();
   calc_external_coords();
   hexagon_draw();
}

void hexagon::rotate(int direction){
   //how?
}

void hexagon::change_size(int direction){
   int d[2] = {-2, 2};
   r+=d[direction];
   hexagon_remove();
   calc_external_coords();
   hexagon_draw();
}

void hexagon::help(int type){//type: 0-about program, 1-move, 2-rotate, 3-change_size
   setbkcolor(COLOR(61, 220, 151));
   setfillstyle(SOLID_FILL, COLOR(61, 220, 151));
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

bool hexagon::in_field(){
   for(int i=0; i<6; i++){
      if(_abracadabra_cast(external[i]);