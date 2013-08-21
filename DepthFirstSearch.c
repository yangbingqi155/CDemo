#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5
struct point{int x;int y;} stack[512];
int top=0;
void push(struct point p){
  stack[top++]=p;
}
struct point pop(){
  return stack[--top];
}
int is_empty(){
  return top==0;
}
int maze[MAX_ROW][MAX_COL]={
  0, 1, 0, 0, 0,
  0, 1, 0, 1, 0,
  0, 0, 0, 0, 0,
  0, 1, 1, 1, 0,
  0, 0, 0, 1, 0,
};
struct point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};
//print 
void maze_print(){
  int i,j;
  for(i=0;i<MAX_ROW;i++){
    for(j=0;j<MAX_COL;j++){
      printf("%d ",maze[i][j]);
    }
    putchar('\n');
  }
  printf("*************************\r\n");
}
void visit_maze(int row,int col,struct point pre){
  maze[row][col]=2;
  predecessor[row][col]=pre;
  struct point visit_maze={row,col};
  push(visit_maze);
}
int main(void){
  maze_print();
}
