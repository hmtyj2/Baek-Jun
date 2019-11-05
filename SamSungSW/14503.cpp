#include <stdio.h>
#include <iostream>

using namespace std;

int map[52][52];
int N,M;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

struct robot{
	int row;
	int col;
	int head;
};


void move(robot *rt, int count){
	int left;
	left=(rt->head)-1;
	if(left==-1){
		left=3;
	}
	if(map[rt->row][rt->col]==0){
		map[rt->row][rt->col]=-1;
		move(rt,count+1);
		return;
	}
	int flag,temp;
	for(flag=0,temp=0;temp<4;temp++){
		if(map[rt->row+dir[temp][0]][rt->col+dir[temp][1]]!=0){
			flag++;
		}
	}
	if(flag==4){
		if(map[rt->row-dir[rt->head][0]][rt->col-dir[rt->head][1]]!=1){
			rt->row-=dir[rt->head][0];
			rt->col-=dir[rt->head][1];
			move(rt,count);
			return;
		}
		else{
			printf("%d\n",count);
			return;
		}
	}
	else if(map[rt->row+dir[left][0]][rt->col+dir[left][1]]==0){
		rt->head=left;
		rt->row+=dir[left][0];
		rt->col+=dir[left][1];
		move(rt,count);
		return;
	}
	else if(map[rt->row+dir[left][0]][rt->col+dir[left][1]]!=0){
		rt->head=left;
		move(rt,count);
		return;
	}
}

int main(){
	int temp,temp1,temp2;
	robot t;
	robot *rt=&t;

	scanf("%d %d",&N,&M);
	scanf("%d %d %d",&t.row,&t.col,&t.head);
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=M;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	rt->row+=1;
	rt->col+=1;
	move(rt,0);

}