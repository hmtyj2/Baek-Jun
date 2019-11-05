#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int map[300][300];
int direct[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
struct count{
	int even;
	int odd;
};
struct count visit[300][300];
queue<int> q_row;
queue<int> q_col;
int N,cur;

int even_odd(){
	int temp,x,y,row,col;
	while(!q_row.empty()){
		row=q_row.front();
		col=q_col.front();
		q_row.pop();
		q_col.pop();
		if(row==N-1 && col==N-1){

		}
		else{
		for(temp=0;temp<4;temp++){
			x=row+direct[temp][0];
			y=col+direct[temp][1];
			if((0<=x && x<N) && (0<=y && y<N)){
				if(visit[x][y].odd==0 && visit[x][y].even==0){
					if(map[x][y]%2==0){
						visit[x][y].even=visit[row][col].even+1;
						visit[x][y].odd=visit[row][col].odd;
					}
					else{
						visit[x][y].even=visit[row][col].even;
						visit[x][y].odd=visit[row][col].odd+1;
					}
					q_row.push(x);
					q_col.push(y);
				}
				else if(visit[x][y].odd<visit[row][col].odd){
					if(map[x][y]%2==0){
						visit[x][y].even=visit[row][col].even+1;
						visit[x][y].odd=visit[row][col].odd;
					}
					else{
						visit[x][y].even=visit[row][col].even;
						visit[x][y].odd=visit[row][col].odd+1;
					}
					q_row.push(x);
					q_col.push(y);
				}
			}
		}
	}
	}
}

int main(){
	int T;
	int temp,temp1,temp2;

	scanf("%d",&T);
	for(temp=0;temp<T;temp++){
		scanf("%d",&N);
		for(temp1=0;temp1<N;temp1++){
			for(temp2=0;temp2<N;temp2++){
				scanf("%d",&map[temp1][temp2]);
			}			
		}
		for(temp1=0;temp1<N;temp1++){
			for(temp2=0;temp2<N;temp2++){
				visit[temp1][temp2].odd=0;
				visit[temp1][temp2].even=0;
			}
		}
		q_row.push(0);
		q_col.push(0);
		if(map[0][0]%2==0){
			visit[0][0].even=1;
		}
		else{
			visit[0][0].odd=1;
		}
		even_odd();
		printf("even: %d, odd: %d \n",visit[N-1][N-1].even,visit[N-1][N-1].odd);

	}
}
