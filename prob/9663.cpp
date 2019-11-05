#include <stdio.h>
#include <iostream>

using namespace std;

int N,M;
int test(int map[][15], int row, int col){
	int temp,temp1,temp2;
	for(temp=0;temp<row;temp++){
		if(map[temp][col]==1){
			return 0;
		}
	}
	for(temp=row,temp1=col,temp2=col;temp>=0;temp--,temp1--,temp2++){
		if(temp1>=0 && map[temp][temp1]==1){
			return 0;
		}
		if(temp2<N && map[temp][temp2]==1){
			return 0;
		}
	}
	return 1;
}
int dfs(int map[][15],int count){
	int temp,temp1,temp2;
	if(count==N){
		M+=1;
		return 0;
	}
	for(temp=0;temp<N;temp++){
		if(test(map,count,temp)){
			int map1[15][15];
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			map1[count][temp]=1;
			dfs(map1,count+1);
		}

	}
	return 0;
}
int main(){
	int temp,temp1,temp2;
	int map[15][15];

	scanf("%d",&N);
	dfs(map,0);
	printf("%d",M);

}