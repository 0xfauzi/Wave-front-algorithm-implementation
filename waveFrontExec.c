#include "waveFrontPlan.c"
#include "waveFrontAlgo.c"
#include "queue.c"

task main()
{
  generate();
  wait1Msec(2000);
  computePath(world_map,X_SIZE,Y_SIZE,start_x,start_y);
}
