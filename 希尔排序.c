#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n){
	int i,temp,j,gap = n;
	do{
		gap = gap/3 +1;
		for(i = gap ; i<n ; i ++){
			temp = a[i];
			for(j = i-gap ; j>=0&&a[j]>temp; j -= gap){
				a[j+gap] = a[j];
			}
			a[j+gap] = temp;
		}
	}while(gap>1);
}
void sort1(int a[],int n){
	int i,j,temp,val,gap = n;
	do{
		gap = gap/3+1;
		for(i = 0; i<n ; i++){
			val = a[i];
			temp = i;
			for(j = i+gap;j<n&&a[j]<val;j += gap){
				temp = j;
				val = a[j];
			}
			if(i!=temp){
				val = a[i];
				a[i] = a[temp];
				a[temp] = val;
			}
		}
	}while(gap>1);
}

void sort2(int a[],int n){
	int i,j,val,gap = n;
	do{
		gap = gap/3 +1;
		for(i = 0 ;i <n ; i++ ){
			for(j = 0 ; j<n -gap-i*gap; j += gap){
				if(a[j]>a[j+gap]){
					val = a[j];
					a[j] = a[j+gap];
					a[j+gap] = val;
				}
			}
		}
	}while(gap>1);
}
 
int findNumber(int a[], int low, int high)  
{  
    int val = a[low];  
  
    while (low < high) {  
        while (low < high && a[high] >= val) {  
            --high;  
        }  
        a[low] = a[high];  
  
        while (low < high && a[low] <= val) {  
            ++low;  
        }  
        a[high] = a[low];  
    }  
    a[low] = val;  
  
    return low;  
} 
void sort3(int a[], int low, int high)  
{  
    int n = 0;  
    if (low < high) {  
        n = findNumber(a, low, high);  
        sort3(a, low, n - 1);  
        sort3(a, n + 1, high);  
    }  
}  
  
 

int main(void){
	int i;
	int a[7] = {4,3,8,1,2,9,0};
	for(i = 0; i<sizeof(a)/sizeof(a[0]); i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	sort3(a,0,6);
	for(i = 0; i<sizeof(a)/sizeof(a[0]);i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}