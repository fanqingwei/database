#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node * next;
}Linked;
int create(Linked** L){
	int data;
	scanf("%d",&data);
	if(data==-1)return 0;
	else{
		*L = (Linked*)malloc(sizeof(Linked));
	    (*L)->data = data;
	    (*L)->next = NULL;
	    create(&(*L)->next);
		return 0;
	}
}
void reverse(Linked ** L){
	Linked *p,*q;
	if((*L)==NULL||(*L)->next==NULL){
		return ;
	}
	else{
		p = (*L)->next;
		while(p!=NULL){
			q = p->next;
		    p->next = (*L);
		    (*L) = p;
		    p = q;
		}
	}
}
void reverse1(Linked** L){
	Linked * p,*q;
	if((*L)==NULL) return;
	else{
		p = (*L)->next;
		while(p!=NULL){
			q = p->next;
			p = q->next;
			q->next = (*L)->next;
			(*L)->next = q;
		}
	}
}
int main(void){
	Linked * L = NULL;
	create(&L);
	printf("%d ",L->data);
	printf("%d ",L->next->data);
	reverse1(&L);
	printf("%d ",L->data);
	printf("%d ",L->next->data);
	printf("%d ",L->next->next->data);
	return 0;
}