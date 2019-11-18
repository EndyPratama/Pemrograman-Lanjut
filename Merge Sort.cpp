#include<stdlib.h> 
#include<stdio.h>

int a[8] = { 6, 5, 3, 8, 1, 7, 2, 4 };
int b[7];

void merging(int low, int mid, int high) {
   int l1, l2, i;

	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		//printf("Masuk for\n");
	  	if(a[l1] <= a[l2]){
	  		//printf("Masuk if\n");
			//printf("a[l1]<=a[l2]\n");
	        b[i] = a[l1++];	//low++
	        //printf("%d=%d\n",b[i],a[l1]);
		}
      	
      	else{
      		//printf("Masuk else\n");
      		b[i] = a[l2++];	//mid+1++
         	//printf("%d = %d\n",b[i],a[l2]);
      	}
   }
   
	while(l1 <= mid){
   		//printf("l1<=mid\n");
      	b[i++] = a[l1++];		//b++=low++
      	//printf("%d = %d\n",b[i],a[l1]);
	}
		
	while(l2 <= high){
		//printf("l2<=high\n");
		b[i++] = a[l2++];		//b++=mid+1++
      	//printf("%d = %d\n",b[i],a[l2]);

	}
      
	for(i = low; i <= high; i++){//mengatur ulang posisi
		//printf("Masuk for\n");
		a[i] = b[i];			//a=b
		printf("%d = %d\n",a[i],b[i]);
	}
}

void sort(int low, int high){			//low = 0; high = 10
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      //printf("\nMelewati low=%d,mid=%d",low,mid);		//0,5;0,2;0,1;
	  sort(low, mid);//mid pindah ke high
      //printf("\nMelewati mid+1=%d,high=%d",mid+1,high);	//0,1;
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
   
	for(i = 0; i < 8; i++)
		printf("%d ", a[i]);

	sort(0, 7);

	printf("\nList after sorting\n");
   
	for(i = 0; i < 8; i++)
		printf("%d ", a[i]);
}
