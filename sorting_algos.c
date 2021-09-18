#include <stdio.h>
#define SIZE 5

int a[SIZE];
void bubblesort(){
	int i=0,j=0;
	for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
				
			}
	}
}
void insertionsort(){
	int i=0;
	for(i=1;i<SIZE;i++){
		int p=a[i];
		int j=i-1;
		while(j>=0 && a[j]>p){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=p;
	}
}
void shellsort(){
	int i,j,k;
    for(i=SIZE/2;i>0;i/=2){
    	for(j=i;j<SIZE;j++){
    		
    		int p=a[j];
    		
    		for(k=j;k>=i && a[k-i]>p;k-=i)a[k]=a[k-i];
    		
    		a[k]=p;
		}
	}
}

int main(){

	int choice=0;
	printf("input your array : ");
	int i=0;
	for(i=0;i<SIZE;i++)scanf("%d",&a[i]);
		printf("\nArray......: ");
	for(i=0;i<SIZE;i++)printf("\n%d",a[i]);
	printf("\nenter your choice :");
	printf("\n1. Bubble sort");
	printf("\n2. Insertion sort");
	printf("\n3. Shell sort\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			bubblesort();
			break;
		case 2:
			insertionsort();
			break;
		case 3:
			shellsort();
			break;
	}
	printf("\nSorted Array......: ");
	for(i=0;i<SIZE;i++)printf("\n%d",a[i]);
	return 0;
}
