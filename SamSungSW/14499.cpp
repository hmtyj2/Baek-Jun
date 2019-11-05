#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int N,M,K;
int map[21][21];
int order[1001];
int dir[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
struct dice{
	int up,north,east,south,west,down;
};
void roll(struct dice *d,int comm){
	int temp,temp1,temp2;
	struct dice t_d;
	if(comm==1){		//east
		t_d.east=d->up;
		t_d.north=d->north;
		t_d.down=d->east;
		t_d.south=d->south;
		t_d.up=d->west;
		t_d.west=d->down;
	}
	else if(comm==2){		//north
		t_d.north=d->up;
		t_d.down=d->north;
		t_d.east=d->east;
		t_d.up=d->south;
		t_d.west=d->west;
		t_d.south=d->down;
	}
	memcpy(d,&t_d,sizeof(struct dice));
}

int main(){
	int temp,temp1,temp2;
	int row,col,cur_row,cur_col;
	dice d;
	d.up=0;
	d.north=0;
	d.east=0;
	d.south=0;
	d.west=0;
	d.down=0;

	scanf("%d %d",&N,&M);
	scanf("%d %d",&row,&col);
	scanf("%d",&K);
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=M;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	for(temp=1;temp<=K;temp++){
		scanf("%d",&order[temp]);
	}
	row++;
	col++;
	for(temp=1;temp<=K;temp++){
		cur_row=row+dir[order[temp]][0];
		cur_col=col+dir[order[temp]][1];
		if(cur_row<1 || cur_col<1 || cur_row>N || cur_col>M){	//check boundary
			continue;
		}
		if(order[temp]==1 || order[temp]==2){		// spin the dice
			if(order[temp]==1){
				roll(&d,1);
			}
			else{
				roll(&d,1);
				roll(&d,1);
				roll(&d,1);
			}
		}
		else{
			if(order[temp]==3){
				roll(&d,2);
			}
			else{
				roll(&d,2);
				roll(&d,2);
				roll(&d,2);
			}
		}
		row=cur_row;		// move the dice
		col=cur_col;

		if(map[row][col]==0){
			map[row][col]=d.down;
		}
		else{
			d.down=map[row][col];
			map[row][col]=0;
		}
		printf("%d\n",d.up);
	}
}