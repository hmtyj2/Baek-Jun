#include <stdio.h>

int map[500][500];
int T,N;
int dfs(int row,int col,int count, int &max){
	int cur=map[row][col];
	if(max<count){
		max=count;
	}
	while(1){
		if(row-1>=0 && map[row-1][col]<cur){
			dfs(row-1,col,count+1,max);
		}
		if(row+1<N && map[row+1][col]<cur){
			dfs(row+1,col,count+1,max);
		}
		if(col-1>=0 && map[row][col-1]<cur){
			dfs(row,col-1,count+1,max);
		}
		if(col+1<N && map[row][col+1]<cur){
			dfs(row,col+1,count+1,max);
		}
		return 0;
	}
}
int main(){
	int temp,temp1,temp2,temp3;
	int max;
	scanf("%d",&T);
	for(temp=0;temp<T;temp++){
		scanf("%d",&N);
		max=0;
		for(temp1=0;temp1<N;temp1++){
			for(temp2=0;temp2<N;temp2++){
				scanf("%d",&map[temp1][temp2]);
			}
		}
		for(temp1=0;temp1<N;temp1++){
			for(temp2=0;temp2<N;temp2++){
				dfs(temp1,temp2,1,max);
			}
		}
		printf("#%d %d\n",temp+1,max);
	}
}
