#include <bits/stdc++.h>

using namespace std;

int N,M;
int map1[8][8];
int cctv[8][3];
int cctv_count=0;
int mini=1000000000;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void copy(int map1[][8],int map2[][8]){
	for(int temp=0;temp<N;temp++){
		for(int temp1=0;temp1<M;temp1++){
			map2[temp][temp1]=map1[temp][temp1];
		}
	}
	return;
}

void see(int map1[][8], int row, int col, int comm){
	int cur_row=row+dir[comm][0];
	int cur_col=col+dir[comm][1];
	for(;cur_row>=0 && cur_row<N && cur_col>=0 && cur_col<M;){
		if(map1[cur_row][cur_col]==0){
			map1[cur_row][cur_col]=7;
		}
		else if(map1[cur_row][cur_col]==6){
			return;
		}
		cur_row+=dir[comm][0];
		cur_col+=dir[comm][1];
	}
	return;
}

void dfs(int count, int map2[][8]){
	if(count==cctv_count){
		int temp,temp1,temp2;
		for(temp=0,temp2=0;temp<N;temp++){
			for(temp1=0;temp1<M;temp1++){
				if(map2[temp][temp1]==0){
					temp2++;
				}
			}
		}
		if(temp2<mini){
			mini=temp2;
		}
		return;
	}
	if(cctv[count][0]==1){
		for(int temp=0;temp<4;temp++){
			int map3[8][8];
			copy(map2,map3);
			see(map3,cctv[count][1],cctv[count][2],temp);
			dfs(count+1,map3);
		}
	}
	else if(cctv[count][0]==2){
		for(int temp=0;temp<2;temp++){
			int map3[8][8];
			copy(map2,map3);
			see(map3,cctv[count][1],cctv[count][2],temp);
			see(map3,cctv[count][1],cctv[count][2],temp+2);
			dfs(count+1,map3);			
		}
	}
	else if(cctv[count][0]==3){
		for(int temp=0;temp<4;temp++){
			int map3[8][8];
			copy(map2,map3);
			see(map3,cctv[count][1],cctv[count][2],temp);
			see(map3,cctv[count][1],cctv[count][2],(temp+1)%4);
			dfs(count+1,map3);
		}
	}
	else if(cctv[count][0]==4){
		for(int temp=0;temp<4;temp++){
			int map3[8][8];
			copy(map2,map3);
			see(map3,cctv[count][1],cctv[count][2],temp);
			see(map3,cctv[count][1],cctv[count][2],(temp+1)%4);
			see(map3,cctv[count][1],cctv[count][2],(temp+2)%4);
			dfs(count+1,map3);
		}
	}
	else if(cctv[count][0]==5){
		int temp=0;
		int map3[8][8];
		copy(map2,map3);
		see(map3,cctv[count][1],cctv[count][2],temp);
		see(map3,cctv[count][1],cctv[count][2],temp+1);
		see(map3,cctv[count][1],cctv[count][2],temp+2);
		see(map3,cctv[count][1],cctv[count][2],temp+3);
		dfs(count+1,map3);
	}
	return;
}
int main(){
	int temp,temp1,temp2;
	scanf("%d %d",&N,&M);
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			scanf("%d",&map1[temp][temp1]);
			if(map1[temp][temp1]>=1 && map1[temp][temp1]<=5){
				cctv[cctv_count][0]=map1[temp][temp1];
				cctv[cctv_count][1]=temp;
				cctv[cctv_count][2]=temp1;	
				cctv_count++;			
			}
		}
	}
	dfs(0,map1);
	printf("%d\n",mini);
}