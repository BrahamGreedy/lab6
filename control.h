#ifndef CONTROL_H
#define CONTROL_H
#define dx 327
#define dy 62

enum CONTROLS {MOVE, ROTATE, RESIZE, SAVE, EXIT, N_CONTROLS};

struct button{
   int x0;
   int y0;
};

void create_button(int, int, int);
void create_bg(const char*);
int select_control();

#endif