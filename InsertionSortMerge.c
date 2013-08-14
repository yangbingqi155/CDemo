#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };
void merge(int start, int mid, int end)
{
  int i=0;
  int j=0;
  int n1=mid-start+1;
  int n2=end-mid;
  int left[n1];
  int right[n2];
  int k=start;
  for(i=0;i<n1;i++){
    left[i]=a[start+i];
  }
  for(j=0;j<n2;j++){
    right[j]=a[mid+j+1];
  }
  i=j=0;
  while(i<n1&&j<n2){
    if(left[i]>right[j]){
      a[k++]=right[j];
	j++;	
    }
    else{
      a[k++]=left[i];
      i++;
    }
  }
  while(i<n1){
    a[k++]=left[i++];
  }
  while(j<n2){
    a[k++]=right[j++];
  }
}

void sort(int start, int end)
{
  int mid;
  if(start<end){
    mid=(start+end)/2;
    printf("Sort:(%d-%d  %d-%d) %d  %d %d %d %d %d %d %d   \n",start,mid,mid+1,end,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
    sort(start,mid);
    sort(mid+1,end);
    merge(start,mid,end);
    printf("Merge:(%d-%d  %d-%d) %d  %d %d %d %d %d %d %d   \n",start,mid,mid+1,end,a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
  }
}

int main(void)
{
	sort(0, LEN-1);

	return 0;
}
