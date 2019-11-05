#include <stdio.h>
#include <iostream>

using namespace std;

int map[101][101];
int map1[101][101];
int L;
int N;
int total;

void dfs(int row,int col_index, int past_block_height, int count){
	int temp,temp1,dif;
	if(col_index==N+1){
		if(count>=0){
			total++;
		}
		return;
	}


	dif=map[row][col_index]-past_block_height;
	if(dif==1){
		if(count<L){
			return;
		}
		else{
			dfs(row,col_index+1,map[row][col_index],1);
			return;
		}
	}
	else if(dif==-1){
		if(count<0){
			return;
		}
		else{
			dfs(row,col_index+1,map[row][col_index],-(L-1));
		}
	}
	else if(dif==0){
		dfs(row,col_index+1,map[row][col_index],count+1);
	}
	else{
		return;
	}
}

int main(){
	int temp,temp1,temp2;
	int dif,flag;

	scanf("%d %d",&N,&L);
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	for(temp=1;temp<=N;temp++){
		dfs(temp,1,map[temp][1],0);
	}
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			map1[temp1][temp]=map[temp][temp1];
		}
	}
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			map[temp][temp1]=map1[temp][temp1];
		}
	}
	for(temp=1;temp<=N;temp++){
		dfs(temp,1,map[temp][1],0);
	}
	printf("%d\n",total);
}