#include <stdio.h>


int dfs(int map[][500], int visit[][500], int row, int col, int count, int N){
	int cur;
	if(visit[row][col]>count){
		return 0;
	}
	else{
		visit[row][col]=count;
		cur=map[row][col];
		if(row-1>=0 && map[row-1][col]<cur){
			dfs(map,visit,row-1,col,count+1,N);
		}
		if(row+1<N && map[row+1][col]<cur){
			dfs(map,visit,row+1,col,count+1,N);
		}
		if(col-1>=0 && map[row][col-1]<cur){
			dfs(map,visit,row,col-1,count+1,N);
		}
		if(col+1<N && map[row][col+1]<cur){
			dfs(map,visit,row,col+1,count+1,N);		
		}
		return 0;
	}
}

int main(){
	int map[500][500]={0,};
	int visit[500][500]={0,};
	int temp,temp1,temp2;
	int T,N;
	int max;

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
				dfs(map,visit,temp1,temp2,1,N);
			}
		}
		for(temp1=0,max=0;temp1<N;temp1++){
			for(temp2=0;temp2<N;temp2++){
				if(visit[temp1][temp2]>max){
					max=visit[temp1][temp2];
				}
				visit[temp1][temp2]=0;
			}
		}
		printf("%d# %d\n",temp1,max);
	}
}