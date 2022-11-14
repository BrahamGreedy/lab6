#define _USE_MATH_DEFINES




hexagon::hexagon(double x, double y, int rad){
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
   if(in_field(d[direction%2])){
      hexagon_remove();
      direction<2?center.y+=d[direction%2]:center.x+=d[direction%2];
      for(int i = 0; i<6; i++){
         direction<2?external[i].y+=d[direction%2]:external[i].x+=d[direction%2];
      }
      hexagon_draw();
   }else{
      error();
   }
}

void hexagon::rotate(int direction){//direction: 0 - rotate left, 1 - rotate right
   int d[2] = {1, -1};
   hexagon_remove();
   for(int i=0; i < 6; i++){
      external[i].x = center.x*cos(d[direction]*M_PI/12)+center.x+center.y*sin(d[direction]*M_PI/12)+external[i].x*cos(d[direction]*M_PI/12)-_abracadabra_cast(external[i]);