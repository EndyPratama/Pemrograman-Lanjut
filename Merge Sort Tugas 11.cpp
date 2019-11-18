#include<stdlib.h> 
#include<stdio.h>

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int low, int mid, int high) {//0,0,1;
   int l1, l2, i;

	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
	  	if(a[l1] <= a[l2]){
			b[i] = a[l1++];		//b0=a1;
		}
      	else{
      		b[i] = a[l2++];		//mid+1++
      	}
   }
   
	while(l1 <= mid){
      	b[i++] = a[l1++];		//b++=low++
	}
		
	while(l2 <= high){
		b[i++] = a[l2++];		//b1=a2;

	}
      
	for(i = low; i <= high; i++){//mengatur ulang posisi
		a[i] = b[i];			 //a=b
	}
}

void sort(int low, int high){			//low = 0; high = 10
   int mid;
   
   if(low < high) {//0,10;1,2;
      mid = (low + high) / 2;
      printf("\nMelewati low=%d,mid=%d",low,mid);		//0,5;0,2;0,1;
	  sort(low, mid);//mid pindah ke high
      printf("\nMelewati mid+1=%d,high=%d",mid+1,high);	//0,1;1,2
      sort(mid+1, high);
      printf("\nMelewati merging\n");					//
      merging(low, mid, high);
   } 
   else { 
      return;
   }   
}

int main() { 
   	int i;
	printf("List before sorting\n");
   
	for(i = 0; i < 11; i++)
		printf("%d ", a[i]);

	sort(0, 10);

	printf("\nList after sorting\n");
   
	for(i = 0; i < 11; i++)
		printf("%d ", a[i]);
}
