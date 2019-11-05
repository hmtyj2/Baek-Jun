#include <stdio.h>
#include <iostream>

using namespace std;

int N,M;

int test(int *map,int row, int col){
	int temp,temp1,temp2;
	for(temp=0;temp<col;temp++){
		if(map[temp]==row){
			return 0;
		}
		else if(((map[temp]-row)==temp-col) || ((map[temp]-row)==(-1)*(temp-col))){
			return 0;
		}
	}
	return 1;
}
void dfs(int *map,int count){
	int temp,temp1,temp2;
	if(count==N){
		M+=1;
		return;
	}
	for(temp=0;temp<N;temp++){
		if(test(map,temp,count)){
			int map1[15];
			for(temp1=0;temp1<count;temp1++){
				map1[temp1]=map[temp1];
			}
			map1[count]=temp;
			dfs(map1,count+1);
		}
	}
	return;
}
int main(){
	int temp,temp1,temp2;
	int map[15];
	scanf("%d",&N);
	dfs(map,0);
	printf("%d",M);
}