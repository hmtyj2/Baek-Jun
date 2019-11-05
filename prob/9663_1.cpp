#include <stdio.h>
#include <iostream>

using namespace std;

int N,M;
int test(int map[][17], int row, int col){
	int temp,temp1,temp2;
	for(temp=0;temp<col;temp++){
		if(map[row][temp]==1){
			return 0;
		}
	}
	for(temp=col,temp1=row;temp>=0 && temp1>=0;temp--,temp1--){
		if(map[temp1][temp]==1){
			return 0;
		}
	}
	for(temp=col,temp1=row;temp>=0 && temp1<N;temp--,temp1++){
		if(map[temp1][temp]==1){
			return 0;
		}
	}
	return 1;
}
void dfs(int map[][17],int count){
	int temp,temp1,temp2;
	if(count==N){
		M+=1;
		return;
	}
	for(temp=0;temp<N;temp++){
		if(test(map,temp,count)){
			int map1[17][17];
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			map1[temp][count]=1;
			dfs(map1,count+1);
		}

	}
	return;
}
int main(){
	int temp,temp1,temp2;
	int map[17][17];

	scanf("%d",&N);
	dfs(map,0);
	printf("%d",M);

}