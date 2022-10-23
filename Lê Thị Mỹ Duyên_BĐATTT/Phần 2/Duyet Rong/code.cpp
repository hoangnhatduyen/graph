#include <stdio.h>
#include <conio.h>
#define MAX 50
#define TRUE 1
#define FALSE 0
int A[MAX][MAX], n, chuaxet[MAX];

void Init()
{
	FILE *in;
	int i,j;
	in= fopen("dothi.txt","r");
	fscanf(in,"%d",&n);
	printf("\n* So dinh do thi: n=%d",n);
	printf("\n* Ma tran ke la: \n");
	for(i=1; i<=n; i++)
	{
		chuaxet[i]=TRUE;
		for(j=1; j<=n; j++)
		{
			fscanf(in,"%d",&A[i][j]);
			printf("%d  ",A[i][j]);
		}
		printf("\n");
	}
	fclose(in);
}
void BFS(int u)
{
	int queue[MAX], low=1, high=1, v;
	queue[low]=u;
	chuaxet[u]=FALSE;
	printf("\n Ket qua:");
	while(low<=high)
	{
		u = queue[low];
		low=low+1;
		printf("%d  ", u);
		for(v=1; v<=n; v++)
		{
			if(A[u][v] && chuaxet[v])// cho v vao queue
			{
				high = high+1;
				queue[high]=v;
				chuaxet[v]=FALSE;
			}
		}
	}
}
int main()
{
	int u;
	Init();
	printf("\n Dinh bat dau duyet:");  scanf("%d",&u);
	BFS(u);
	getch();
	return 0;
}
