#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];
typedef int ShortPatharcTable[MAXVEX];
typedef struct {
	int numVertexes;
	int arc[MAXVEX][MAXVEX];
}Mgraph;
void shortPath(Mgraph G,int v0,Patharc * P,ShortPatharcTable * D){
	int v,w,k,min;
	int final[MAXVEX];
	for(v=0;v<G.numVertexes;v++){
		final[v]=0;
		(*D)[v] = G.arc[v0][v];
		(*P)[v] = v0;
	}
	(*D)[v0] = 0;
	final[v0] = 1;
	for(v=1;v<G.numVertexes;v++){
		min = INFINITY;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w]&&(*D)[w]<min){
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w]&&(min+G.arc[k][w])<(*D)[w]){
				(*D)[w] = min+G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}
int main(void){
	Patharc  P;
	ShortPatharcTable D;
	Mgraph * G = (Mgraph *)malloc(sizeof(Mgraph));
	int i,j,k;
	G->numVertexes = 6;
	for(i=0;i<G->numVertexes;i++){
		for(j=0;j<G->numVertexes;j++){
			scanf("%d",&k);
			(G->arc)[i][j] = k;
		}
	}
	shortPath((*G),0,&P,&D);
	for(i=0;i<G->numVertexes;i++){
		printf("%d ",D[i]);
	}
	printf("\n");
}

