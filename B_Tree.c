#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define SIZE 3
typedef struct {
	int count;
	int data[MAX][MAX];
}Graphy;
typedef struct Node{
	int size;
	int keyNum;
	int data[SIZE+1];
	struct Node* ptr[SIZE+2];
	struct Node * parent;
}BTree;
void initBTree(BTree *B,int size){
	int i;
	B->size = size;
	B->keyNum = 0;
	B->parent = NULL;
	for(i = 0 ;i < size +1; i++){
		(B->data)[i] = 0;
	}
	for(i = 0 ;i < size +2; i++){
		(B->ptr)[i] = NULL;
	}
}
BTree * createBTree(int size){
	int i;
	BTree * B = (BTree *)malloc(sizeof(BTree));
	B->keyNum = 0;
	B->parent = NULL;
	B->size = size;
	for(i = 0 ;i< size+1 ;i++){
		(B->data)[i] = 0;
	}
	for(i=0 ; i<size+2 ; i++){
		(B->ptr)[i] = NULL;
	}
	return B;
}
void fenlie(BTree ** B){
	BTree * child,*parent;
	int i,j;
	int total = ((*B)->keyNum)/2;
	if((*B)->parent==NULL){
		child = createBTree((*B)->size);
		parent = createBTree((*B)->size);
		for(i=total,j=0; i<(*B)->keyNum ; i++,j++){
			(child->data)[j] = ((*B)->data)[i+1];
			(child->ptr)[j] = ((*B)->ptr)[i+1];
			((*B)->data)[i+1] = 0;
			((*B)->ptr)[i+1] = NULL;
		}
		(parent->keyNum) = 1;
		child->keyNum = ((*B)->keyNum)-(total+1);
		(*B)->keyNum = total;
		(child->ptr)[j] = ((*B)->ptr)[(*B)->keyNum];
		(parent->data)[0] = ((*B)->data)[total];
		((*B)->data)[total] = 0;
		(parent->ptr)[0] = (*B);
		(parent->ptr)[1] = child;
		((*B)->parent) = parent;
		(child->parent) = parent;
		(*B) = parent;
	}else{
		child = createBTree((*B)->size);
		for(i=total,j=0; i<(*B)->keyNum ; i++,j++){
			(child->data)[j] = ((*B)->data)[i+1];
			(child->ptr)[j] = ((*B)->ptr)[i+1];
			((*B)->data)[i+1] = 0;
			((*B)->ptr)[i+1] = NULL;
		}
		child->keyNum = ((*B)->keyNum)-(total+1);
		(*B)->keyNum = total;
		parent = (*B)->parent;
		for(i = 0;i <parent->keyNum; i++ ){
			if(((*B)->data)[total]<(parent->data)[i]){
				for(j = parent->keyNum ; j>=i ; j--){
					(parent->data)[j] = (parent->data)[j-1];
					(parent->ptr)[j+1] = (parent->ptr)[j];
				}
				(parent->data)[i] = ((*B)->data)[total];
				(parent->ptr)[i+1] = child;
				child->parent = parent;
				(parent->keyNum) += 1;
				if((parent->keyNum)>(parent->size))fenlie(&parent);
				return ;
			}
		}
		if(i==parent->keyNum){
			(parent->data)[i] = ((*B)->data)[total];
			(parent->ptr)[i+1] = child;
			child->parent = parent;
			(parent->keyNum) += 1;
			if((parent->keyNum)>(parent->size))fenlie(&parent);
		}
	}
}
void insertBTree(BTree ** B,int key){
	int i,j;
	if(((*B)->keyNum)==0){
		(*B)->data[0] = key;
		((*B)->keyNum) += 1;
		(*B)->parent = NULL;
		if(((*B)->keyNum)>((*B)->size))fenlie((B));
		return ;
	}else{
		for(i = 0; i<(*B)->keyNum ; i++){
			if(key == (((*B)->data)[i]))return;
			if(key < ((*B)->data)[i]){
				if(((*B)->ptr)[i] == NULL){
					for(j = (*B)->keyNum ; j>i ; j--){
						((*B)->data)[j] = ((*B)->data)[j-1];
					}
					((*B)->data)[i] = key;
					((*B)->keyNum) += 1;
					if(((*B)->keyNum)>((*B)->size))fenlie((B));
					return ;
				}else{
					insertBTree(&(((*B)->ptr)[i]),key);
					return ;
				}
			}
			//else{
				//if((B->ptr)[i+1] == NULL){
				//	for( j = B->keyNum ;j >i+1 ;j--){
				//		(B->data)[j] = (B->data)[j-1];
				//	}
				//	(B->data)[i+1] = key;
				//	(B->keyNum) += 1;
				//	if((B->keyNum)>(B->size))fenlie(&(*B));
				//	return ;
				//}else{
				//	insertBTree(&(*(B->ptr)[i+1]),key);
				//	return ;
				//}
			//}
		}
		if(((*B)->ptr)[(*B)->keyNum]!=NULL){
			insertBTree(&(((*B)->ptr)[(*B)->keyNum]),key);
			if((((*B)->ptr)[(*B)->keyNum])->keyNum > (*B)->size)fenlie(&(((*B)->ptr)[(*B)->keyNum]));
		}
		else{
			((*B)->data)[(*B)->keyNum] = key;
			((*B)->keyNum) += 1;
			if(((*B)->keyNum)>((*B)->size))fenlie(B);
			return ;
		}
	}
}

int IsRead[MAX];
void InitGraphy(Graphy * G,int count){
	int i,j,temp;
	G->count = count;
	printf("«Î ‰»ÎÕºµƒ¡⁄Ω”æÿ’Û£∫");
	for(i = 0; i<G->count ; i++ ){
		for(j = 0; j<G->count ; j++ ){
			scanf("%d",&temp);
			(G->data)[i][j] = temp;
		}
	}
}
int main(void){
	BTree *B = createBTree(3);
	int key,i;
	printf("«Î ‰»Î:");
	scanf("%d",&key);
	while(key != -1){
		insertBTree(&B,key);
		scanf("%d",&key);
	}
	for(i = 0; i<B->keyNum ;i ++){
		printf("%d ",(B->data)[i]);
	}
	return 0;
}