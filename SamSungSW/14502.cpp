#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N,M,total;
int map[8][8];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int list[][2],int count){
	int temp,temp1,temp2,temp3;
	if(count==2){
		int dmap[8][8];
		int cur_row,cur_col;
		int fut_row,fut_col;
		int sum;
		queue<int> row;
		queue<int> col;
		for(temp=0;temp<N;temp++){
			for(temp1=0;temp1<M;temp1++){
				dmap[temp][temp1]=map[temp][temp1];
				if(dmap[temp][temp1]==2){
					row.push(temp);
					col.push(temp1);
				}
			}
		}
		for(temp=0;temp<3;temp++){
			dmap[list[temp][0]][list[temp][1]]=3;
		}

		while(!row.empty() && !col.empty()){
			cur_row=row.front();
			cur_col=col.front();
			row.pop();
			col.pop();
			for(temp=0;temp<4;temp++){
				fut_row=cur_row+dir[temp][0];
				fut_col=cur_col+dir[temp][1];
				if(fut_row>=0 && fut_row<N && fut_col>=0 && fut_col<M){
					if(dmap[fut_row][fut_col]==0){
						dmap[fut_row][fut_col]=2;
						row.push(fut_row);
						col.push(fut_col);
					}
				}
			}
		}
		for(temp=0,sum=0;temp<N;temp++){
			for(temp1=0;temp1<M;temp1++){
				if(dmap[temp][temp1]==0){
					sum++;
				}
			}
		}
		if(sum>total){
			total=sum;
/*			printf("total: %d\n",total);
			for(temp=0;temp<N;temp++){
				for(temp1=0;temp1<M;temp1++){
					printf("%d ",dmap[temp][temp1]);
				}
				printf("\n");
			}*/
		}
		return;
	}
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			if(temp*M+temp1<=list[count][0]*M+list[count][1]){
				continue;
			}
			if(map[temp][temp1]==0){
				int c_list[3][2];
				for(temp2=0;temp2<3;temp2++){
					c_list[temp2][0]=list[temp2][0];
					c_list[temp2][1]=list[temp2][1];
				}
				c_list[count+1][0]=temp;
				c_list[count+1][1]=temp1;
				dfs(c_list,count+1);
			}
		}
	}	
}
int main(){
	int temp,temp1,temp2;
	int list[3][2];

	scanf("%d %d",&N,&M);
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<M;temp1++){
			if(map[temp][temp1]==0){
				list[0][0]=temp;
				list[0][1]=temp1;
				dfs(list,0);
			}
		}
	}
	printf("%d\n",total);
}