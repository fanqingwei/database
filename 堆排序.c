#include<stdio.h>
void createHeap(int a[],int s,int n){
	int i,temp=a[s];
	
	for(i = 2*s ; i<=n ; i*=2){
		if(i<n&&a[i]<a[i+1]){
			i++;
		}
		if(temp>a[i])break;
		a[s] = a[i];
		s = i;
	}
	a[s] = temp;
}
void HeapSort(int a[],int n){
	int i,val;
	for(i = n/2 ; i>0 ; i--){
		//初始化数组为大顶堆，从最后一个父节点开始,假设为所在父节点一下全是大顶堆
		createHeap(a,i,n);
	}
	for(i = n ; i>1; i--){
		val = a[1];
		a[1] = a[i];
		a[i] = val;
		//修改大顶堆,因为只改变了第一个父节点,所以修改第一个父节点为大顶堆
		createHeap(a,1,i-1);
	}
}
int main(void){
	int i = 0;

	int a[7] = {0,7,4,8,2,3,5};
	for(i=0;i<7;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	HeapSort(a,6);
	for(i=0;i<7;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}