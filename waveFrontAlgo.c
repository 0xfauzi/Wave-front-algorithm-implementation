#include "planning_map.h"
#include "waveFrontPlan.c"
#include "queue.c"

Cell nextCell;
void generate();

void generate()
{
  //Initialize goal cell to 2
  world_map[goal_y][goal_x] =2;

  //Put goal cell in the next
  nextCell.x = goal_x;
  nextCell.y = goal_y;
  enQueue(nextCell.x, nextCell.y);
  //End
  //display();

  while(rear != front)
  {
    writeDebugStreamLine("front: %d", queue[front]);
    writeDebugStreamLine("front+1:%d", queue[front+1]);

    //Take next cell from queue
    nextCell.x = queue[front];
    nextCell.y = queue[front+1];
    //End

    //Determine non obstacle neighbors
    Cell temp;
    temp.x = nextCell.x;
    temp.y = nextCell.y;
    computeNeighbor(temp);
    display();
    //End
    int y = queue[front+1];
    int x = queue[front];

    writeDebugStreamLine("next value: %d", world_map[y][x]+1);
    //If non obstacle cell value is 0
    if(northVal == 0)
    {
      world_map[northNeigh.y][northNeigh.x] = world_map[y][x]+1;
      enQueue(northNeigh.x,northNeigh.y);
      display();
    }
    if(southVal == 0)
    {
      world_map[southNeigh.y][southNeigh.x] = world_map[y][x]+1;
      enQueue(southNeigh.x,southNeigh.y);
      display();
    }
    if(eastVal == 0)
    {
      world_map[eastNeigh.y][eastNeigh.x] = world_map[y][x]+1;
      enQueue(eastNeigh.x,eastNeigh.y);
      display();
    }
    if(westVal == 0)
    {
      world_map[westNeigh.y][westNeigh.x] = world_map[y][x]+1;
      enQueue(westNeigh.x,westNeigh.y);
      display();
    }
    deQueue();
  }

	for(int i=0;i<Y_SIZE;i++)
	{
	  for(int j=0;j<X_SIZE;j++)
	  {
	    writeDebugStream("%d ", world_map[i][j]);
	  }
	}

}
