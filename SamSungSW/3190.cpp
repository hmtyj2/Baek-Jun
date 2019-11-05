#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int temp,temp1,temp2;
	int N,K,L;
	int map[101][101]={0,};
	int time[100];
	char move[100];
	int T;
	int time_index;
	int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; // up=0 right=1 down=2 left=3
	int dir_temp;
	int head_row,head_col,tail_row,tail_col;

	scanf("%d",&N);
	scanf("%d",&K);
	for(temp=0;temp<K;temp++){
		scanf("%d %d",&temp1,&temp2);
		map[temp1][temp2]=-1;
	}
	scanf("%d",&L);
	for(temp=0;temp<L;temp++){
		scanf("%d %c",&time[temp],&move[temp]);
	}
	head_row=1;
	head_col=1;
	tail_row=1;
	tail_col=1;
	map[head_row][head_col]=1;
	for(T=1,time_index=0,dir_temp=1;;T++){
		head_row+=dir[dir_temp][0];		// move head
		head_col+=dir[dir_temp][1];		//
		if((head_row<1) || (head_col<1) || (head_row>N) || (head_col>N)){		// check wall
			printf("%d",T);
			return 0;
		}																			//
		if(map[head_row][head_col]!=0 && map[head_row][head_col]!=-1){	// head hits body
			printf("%d",T);
			return 0;
		}														//
		if(map[head_row][head_col]==-1){	// check apple
			map[head_row][head_col]=T+1;
		}
		else{
			map[head_row][head_col]=T+1;
			for(temp=0;temp<4;temp++){
				if(map[tail_row+dir[temp][0]][tail_col+dir[temp][1]]==map[tail_row][tail_col]+1){
					map[tail_row][tail_col]=0;
					tail_row=tail_row+dir[temp][0];
					tail_col=tail_col+dir[temp][1];
					break;
				}
			}
		}									//
		if(time[time_index]==T){			// direction
			if(move[time_index]=='D'){
				dir_temp=(dir_temp+1)%4;
			}
			else if(move[time_index]=='L'){
				dir_temp=(dir_temp+3)%4;
			}
			time_index++;
		}	
		/*printf("%d:\n",T);
		for(temp=0;temp<=N;temp++){
			for(temp1=0;temp1<=N;temp1++){
				printf("%2d",map[temp][temp1]);
			}
			printf("\n");
		}*/
	}

}