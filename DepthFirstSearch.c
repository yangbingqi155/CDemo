#include <stdio.h>
#define MAX_ROW 5
#define MAX_COL 5
struct point{int row;int col;} stack[512];
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
  struct point p={0,0};
  struct point current;
  push(p);
  maze[p.row][p.col]=2;
  while(!is_empty()){
    current=pop();
    if(current.row==MAX_ROW-1&&current.col==MAX_COL-1){
      break;
    }
    //up
    if(current.row-1>=0&&maze[current.row-1][current.col]==0){
      push(current);
      visit_maze(current.row-1,current.col,current);
      maze_print();
    }
    //right
    if(current.col+1<MAX_COL&&maze[current.row][current.col+1]==0){
      push(current);
      visit_maze(current.row,current.col+1,current);
      maze_print();
    }
    //down
    if(current.row+1<MAX_ROW&&maze[current.row+1][current.col]==0){
      push(current);
      visit_maze(current.row+1,current.col,current);
      maze_print();
    }
    //left
    if(current.col-1>=0&&maze[current.row][current.col-1]==0){
      push(current);
      visit_maze(current.row,current.col+1,current);
      maze_print();
    }
  }
  if(current.row==MAX_ROW-1&&current.col==MAX_COL-1){
    printf("%d  %d\n",current.row,current.col);
    
    while(predecessor[current.row][current.col].row!=-1){
      current=predecessor[current.row][current.col];
      printf("%d  %d\n",current.row,current.col);
    }
  }
  else{
    printf("No path.\n");
  }
}
