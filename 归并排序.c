#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
void MergeIng(int * list1,int * list2,int list1_size,int list2_size){
	int i,j,k,m,a[MAXSIZE];
	i = j = k = m = 0;
	while(i<list1_size&&j<list2_size){
		if(list1[i]<list2[j]){
			a[k++] = list1[i++];
		}else{
			a[k++] = list2[j++];
		}
	}
	while(i<list1_size){
		a[k++] = list1[i++];
	}
	while(j<list2_size){
		a[k++] = list2[j++];
	}
	for(m = 0; m<(list1_size+list2_size) ; m++){
		list1[m] = a[m];
	}
}
//递归实现归并排序
void MergeSort(int a[],int n){
	if(n > 1){
		int * list1 = a;
	    int list1_size = n/2;
	    int * list2 = a+n/2;
	    int list2_size = n-list1_size;
		MergeSort(list1,list1_size);
		MergeSort(list2,list2_size);
		MergeIng(list1,list2,list1_size,list2_size);
	}
}
//迭代实现归并排序
void MergeSort1(int a[],int n){
	int left_min,left_max,right_min,right_max,i,k = 0,j;
	int * temp = (int *)malloc(n*sizeof(int));
	for(i = 1 ;i< n ; i *=2){
		for(left_min = 0 ;left_min<n-i ; left_min = j){
			left_max = right_min = left_min+i;
			right_max = left_max+i;
			if(right_max>n)right_max = n;
			j = right_max;
			while(left_min<left_max&&right_min<right_max){
				if(a[left_min]<a[right_min]){
					temp[k++] = a[left_min++];
				}else{
					temp[k++] = a[right_min++];
				}
			}
			//如果left_min<left_max 则right_min = right_max
			printf("%d   %d  %d  %d   %d\n",right_min,right_max,j,left_min,left_max);
			while(left_min<left_max){
				a[--right_min] = a[--left_max];
			}
			while(k>0){
				a[--right_min] = temp[--k];
			}
		}
	}
}
int main(void){
	int i;
	int a[8] = {9,5,6,14,3,7,2,10};
	MergeSort1(a,sizeof(a)/sizeof(a[0]));
	for(i = 0 ; i< sizeof(a)/sizeof(a[0]) ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}