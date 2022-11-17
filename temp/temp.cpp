#define _USE_MATH_DEFINES




hexagon::hexagon(int rad, int N){
   r = rad;
   n = N;
}

void hexagon::set_external(int i, coords temp){
   external[i].x = temp.x;
   external[i].y = temp.y;
}

void hexagon::calc_center(){
   int temp_x = 0, temp_y = 0;
   for(int i=0; i<n; i++){
      temp_x += external[i].x;
      temp_y += external[i].y;
   }
   center.x = temp_x/n;
   center.y = temp_y/n;
}

void hexagon::hexagon_draw(){
   for(int i = 0; i<n; i++){
      line(external[i].x, external[i].y, external[(i+1)%n].x, external[(i+1)%n].y);
   }
}

void hexagon::hexagon_remove(){
   setcolor(COLOR(235, 245, 238));
   for(int i = 0; i<n; i++){
      line(external[i].x, external[i].y, external[(i+1)%n].x, external[(i+1)%n].y);
   }
   setcolor(COLOR(70, 35, 122));
}

void hexagon::move(int direction){//direction: 0-up, 1-down equals for left and right it's realised with %2
   int d[2] = {-2, 2};
   if(in_field(d[direction%2])){
      hexagon_remove();
      direction<2?center.y+=d[direction%2]:center.x+=d[direction%2];
      for(int i = 0; i<n; i++){
         direction<2?external[i].y+=d[direction%2]:external[i].x+=d[direction%2];
      }
      hexagon_draw();
   }else{
      error();
   }
}

void hexagon::rotate(int direction, int type){//direction: 0 - rotate left, 1 - rotate right
   int d[2] = {1, -1};
   hexagon_remove();
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
   hexagon_draw();
}

void hexagon::change_size(int direction){
   int d[2] = {-2, 2};
   hexagon_remove();
   if(in_field(d[direction])){
      r+=d[direction];
      for(int i=0; i<n; i++){
         _abracadabra_cast(external);