#include<stdio.h>
int countDupUnsorted(int a[],int nsize,int b[],int h,int l){
	int i,ele;
	for(i=0;i<h;i++){
		b[i]=0;
	}
	for(i=0;i<nsize;i++){
		ele=a[i];
		b[ele]=b[ele]+1;
	}
	for(i=0;i<=h;i++){
		if(b[i]>1){
			printf("%d is present %d times\n",i,b[i]);
		}
	}
}
int main(){
	int i,n,max,min;
	int a[100], b[100];
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter the elements in the array\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<n;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	min=a[0];
	for(i=0;i<n;i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	countDupUnsorted(a,n,b,max,min);
}
