#include"planning_map.h"
#include "waveFrontPlan.c"

int rear=0; int front=0;



Cell queue[MAP_AREA*2];


void enQueue(int x, int y);
void deQueue();
void display();
int isEmpty();

void enQueue(int x, int y)
{
  if(rear<sizeof(queue))
  {
     queue[rear] = x;
     queue[rear+1] = y;
     rear+=2;
  }
  else
  {
     writeDebugStreamLine("Cannot enqueue");
  }
}

void deQueue()
{
  writeDebugStreamLine("Dequeueing: %d,%d", queue[front].x,queue[front+1]);
  queue[front]=0;
  queue[front+1]=0;
  front+=2;
  display();
}

void display()
{
    int i;
    for(i=front;i<rear-1;i+=2)
    {
        writeDebugStreamLine("\n %d. %d,%d",i, queue[i],queue[i+1]);
    }
}

int isEmpty()
{
  int returnValue;
  front == rear ? returnValue = 0:returnValue = 1;
  return returnValue;
}
