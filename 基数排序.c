#include<stdio.h>
#include<stdlib.h>
void insertSort(int a[],int n){
	int i,j,val;
	for(i = 1 ; i<n ; i++){
		val = a[i];
		for(j = i-1 ; j>=0&&a[j]>val ; j--){
			a[j+1] = a[j];
		}
		a[j+1] = val;
	}
}
int * jishuSort(int *a,int k[],int n){
	int * c = (int *)malloc(n*sizeof(int));
	int i,j;
	for(i = 0;i<n;i++){
		c[i] = k[i];
	}
	insertSort(k,n);

	for(i = 0 ; i<n ;i++){
		for(j = 0; j<n ; j++){
			if(k[i] == c[j]){
				k[i] = j;
				c[j] = -1;
				break;
			}
			
		}
	}
	
	for(i = 0 ; i<n ; i++){
		c[i] = (a)[k[i]];
	}
	a = c;
	return a;

}
int * countingSort(int *a,int n,int num){
	int *b = (int *)malloc(n*sizeof(int));
	int i,j,k;
	for(i = 0,j = 1 ;  i<num ; i++ ,j *= 10){
		for(k = 0 ; k <n ; k++){
			b[k] = a[k]/j%10;
		}
		a = jishuSort(a,b,n);
	}
	return a;
	
}
int main(void){
	int i;
	int a[8] = {343,233,444,678,234,443,543,556};
	int * b = a;
	b = countingSort(a,8,3);
	for(i = 0 ; i<8 ; i++){
		printf("%d ",b[i]);
	}
	return 0;
}
	
	
