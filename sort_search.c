#include<stdio.h>
#define SIZE 100

int a[SIZE];
void input(int size){
	int i=0;

	for(i=0;i<size;i++){
	printf("input element: ");
	scanf("%d",&a[i]);
	}
}
void display(int size){
	printf("array elements :\n ");
	int i=0;
	for(i=0;i<size;i++)printf("%d\n",a[i]);
}
int linear_search(int num,int size){
	int i=0;
	for(i=0;i<size;i++)
	if(num==a[i])return i;
	
	return -1;
}
int binary_search(int num,int low,int high){
	if(low>high)return -1;
	int mid=(low+high)/2;
	if(a[mid]>num)binary_search(num,low,mid-1);
	else if(a[mid]<num)binary_search(num,mid+1,high);
	else
	return mid;
}
void selectionsort(int size){
	int i=0,j=0;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	int n=0;
	printf("input size of array: \n");
	scanf("%d",&n);
	input(n);
	display(n);
	int i=0;
	int num=0;
    printf("input number to be found via linear search: \n");
	scanf("%d",&num);
	int found=linear_search(num,n);
	if(found!=-1)
	printf("position of element : %d\n",found+1);
	else
	printf("not found\n");
	printf("sorting elements via selection sort........\n");
	selectionsort(n);
	display(n);
    printf("input number to be found via binary search: \n");
	scanf("%d",&num);
	found=binary_search(num,0,n-1);
	if(found!=-1)
	printf("position of element : %d\n",found+1);
	else
	printf("not found\n");
	return 0;
}
