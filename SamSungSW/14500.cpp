#include <stdio.h>
#include <iostream>

using namespace std;

int map[500][500];
int N,M,total;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int list[][2],int count,int sum){
	int temp,temp1,temp2;
	if(count==3){
		if(sum>total){
			total=sum;
		}
		return;
	}
	for(temp=0;temp<=count;temp++){
		for(temp1=0;temp1<4;temp1++){
			int cur_row=list[temp][0]+dir[temp1][0];
			int cur_col=list[temp][1]+dir[temp1][1];
			int cur_list[4][2];
			int flag=1;
			for(temp2=0;temp2<4;temp2++){
				cur_list[temp2][0]=list[temp2][0];
				cur_list[temp2][1]=list[temp2][1];
			}
			for(temp2=0;temp2<=count;temp2++){
				if(cur_row==list[temp2][0] && cur_col==list[temp2][1]){
					flag=0;
					break;
				}
			}
			if(flag){
				if(cur_row>=0 && cur_row<N && cur_col>=0 && cur_col<M){
					cur_list[count+1][0]=cur_row;
					cur_list[count+1][1]=cur_col;
					dfs(cur_list,count+1,sum+map[cur_row][cur_col]);
				}
			}
		}
	}
}
int main(){
	int temp,temp1,temp2;
	int list[4][2];

	scanf("%d %d",&N,&M);
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			list[0][0]=temp;
			list[0][1]=temp1;
			dfs(list,0,map[temp][temp1]);
		}
	}
	printf("%d\n",total);
}