#include <stdio.h>
#define LEN 5
int a[LEN]={5,22,2,99,3};
void insertion_sort(){
  int i,j,key;
  for(i=1;i<LEN;i++){
    key=a[i];
    printf("---------%d-------------\n",i+1);
    printf("%d   %d   %d  %d   %d\n",a[0],a[1],a[2],a[3],a[4]);
    j=i-1;
    while(j>=0&&a[j]>key){
	  a[j+1]=a[j];
	  j--;
    }
    a[j+1]=key;
    printf("%d   %d   %d  %d   %d\n",a[0],a[1],a[2],a[3],a[4]);
    printf("---------%d-------------\n",i+1);
  }
}
int main(void){
  insertion_sort();
  return 0;
}
