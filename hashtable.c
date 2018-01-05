#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 12
#define NULLKEY 100
typedef struct {
    int * ele;
    int count;
}HashTable;
int initHashTable(HashTable * H){
    int i;
    H->count = HASHSIZE;
    H->ele = (int *)malloc(sizeof(int)*HASHSIZE);
    if(!H->ele){
        return -1;
    }
    for( i= 0; i<HASHSIZE ; i++){
        (H->ele)[i] = NULLKEY;
		printf("%d ",(H->ele)[i]);
    }
    return 0;
}
int Hash(int key){
	return key%HASHSIZE;
}
void insertHashTable(HashTable * H,int key){
	int addr;
	addr = Hash(key);
	while(((H->ele)[addr])!=NULLKEY){
		addr = (addr+1)%HASHSIZE;
	}
	(H->ele)[addr] = key;
}
int searchHashTable(HashTable *H,int key,int *addr){
	*addr = Hash(key);
	while(((H->ele)[*addr])!= key){
		*addr = (*addr+1)&HASHSIZE;
		if(H->ele[*addr]==NULLKEY||*addr == Hash(key)){
			return -1;
		}
		return 0;
	}

}
int main(void){
	int i,j;
	HashTable H;
	initHashTable(&H);
	printf("请输入数字以（-1）结束\n");
	 for( i= 0; i<HASHSIZE ; i++){
		printf("%d ",(H.ele)[i]);
    }
	 printf("%d",H.count);
	scanf("%d",&i);
	while(i!=-1){
		insertHashTable(&H,i);
		printf("%d ",(H.ele)[1]);
		scanf("%d",&i);
	}
	for(j=0;j<HASHSIZE;j++){
		if((H.ele)[j]!=NULLKEY){
			printf("%d ",(H.ele)[j]);
		}
	}
	printf("\n");
	return 0;
}
