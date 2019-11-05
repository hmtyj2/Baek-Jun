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
	int temp,row,col,cur_row,cur_col;
	while(!q_row.empty()){
		cur_row=q_row.front();
		cur_col=q_col.front();
		q_row.pop();
		q_col.pop();
		if(cur_row==N-1 && cur_col==N-1){
		}
		else{
			for(temp=0;temp<4;temp++){
				row=cur_row+direct[temp][0];
				col=cur_col+direct[temp][1];
				if(0<=row<N && 0<=col<N){
					if(visit[row][col].odd==0 && visit[row][col].even==0){
						if(map[row][col]%2==0){
							visit[row][col].even=visit[cur_row][cur_col].even+1;
							visit[row][col].odd=visit[cur_row][cur_col].odd;	
						}
						else{
							visit[row][col].even=visit[cur_row][cur_col].even;
							visit[row][col].odd=visit[cur_row][cur_col].odd+1;
						}
						q_row.push(row);
						q_col.push(col);
					}
					else if(visit[row][col].odd>visit[cur_row][cur_col].odd){
						if(map[row][col]%2==0){
							visit[row][col].odd=visit[cur_row][cur_col].odd;
							visit[row][col].even=visit[cur_row][cur_col].even+1;
						}
						else{
							visit[row][col].odd=visit[cur_row][cur_col].odd+1;
							visit[row][col].even=visit[cur_row][cur_col].even;
						}
						q_row.push(row);
						q_col.push(col);
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
