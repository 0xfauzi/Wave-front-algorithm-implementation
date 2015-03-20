#define X_SIZE 5
#define Y_SIZE 4
#define MAP_AREA 20
#define FREE 0
#define OBST 1
#define GOAL 2

int world_map[][] = {{0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 1, 0, 0},
                     {0, 1, 0, 0, 0}};
int start_x = 1;
int start_y = 2;
int goal_x = 4;
int goal_y = 3;
