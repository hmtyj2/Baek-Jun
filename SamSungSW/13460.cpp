#include <stdio.h>
#include <iostream>

using namespace std;

char map[15][15];
int m=11;
int N,M;
int u_move(int *red,int *blue){
	int temp,flag=0;
	if(red[0]<blue[0]){
		flag=1;
	}
	for(temp=red[0];temp>=0 && map[temp][red[1]]!='#';temp--){
		red[0]=temp;
		if(map[temp][red[1]]=='O'){
			red[2]=1;
		}
	}
	for(temp=blue[0];temp>=0 && map[temp][blue[1]]!='#';temp--){
		blue[0]=temp;
		if(map[temp][blue[1]]=='O'){
			blue[2]=1;
		}
	}
	if(red[0]==blue[0] && red[1]==blue[1]){
		if(flag){
			blue[0]++;
		}
		else{
			red[0]++;
		}
	}
}
int d_move(int *red,int *blue){
	int temp,flag=0;
	if(red[0]>blue[0]){
		flag=1;
	}
	for(temp=red[0];temp<N && map[temp][red[1]]!='#';temp++){
		red[0]=temp;
		if(map[temp][red[1]]=='O'){
			red[2]=1;
		}
	}
	for(temp=blue[0];temp<N && map[temp][blue[1]]!='#';temp++){
		blue[0]=temp;
		if(map[temp][blue[1]]=='O'){
			blue[2]=1;
		}
	}
	if(red[0]==blue[0] && red[1]==blue[1]){
		if(flag){
			blue[0]--;
		}
		else{
			red[0]--;
		}
	}
}
int r_move(int *red,int *blue){
	int temp,flag=0;
	if(red[1]>blue[1]){
		flag=1;
	}
	for(temp=red[1];temp<M && map[red[0]][temp]!='#';temp++){
		red[1]=temp;
		if(map[red[0]][temp]=='O'){
			red[2]=1;
		}
	}
	for(temp=blue[1];temp<M && map[blue[0]][temp]!='#';temp++){
		blue[1]=temp;
		if(map[blue[0]][temp]=='O'){
			blue[2]=1;
		}
	}
	if(red[0]==blue[0] && red[1]==blue[1]){
		if(flag){
			blue[1]--;
		}
		else{
			red[1]--;
		}
	}
}
int l_move(int *red,int *blue){
	int temp,flag=0;
	if(red[1]<blue[1]){
		flag=1;
	}
	for(temp=red[1];temp>=0 && map[red[0]][temp]!='#';temp--){
		red[1]=temp;
		if(map[red[0]][temp]=='O'){
			red[2]=1;
		}
	}
	for(temp=blue[1];temp>=0 && map[blue[0]][temp]!='#';temp--){
		blue[1]=temp;
		if(map[blue[0]][temp]=='O'){
			blue[2]=1;
		}
	}
	if(red[0]==blue[0] && red[1]==blue[1]){
		if(flag){
			blue[1]++;
		}
		else{
			red[1]++;
		}
	}
}
int dfs(int count,int *red,int *blue){
	int temp,temp1,temp2;
	if(red[2]){
		if(blue[2]){
			return 0;
		}
		else{
			if(count<m){
				m=count;
			}
			return 0;
		}
	}
	else if(count==m){
		return 0;
	}
	for(temp=0;temp<4;temp++){
		if(temp==0){
			int c_red[3];
			int c_blue[3];
			for(temp1=0;temp1<3;temp1++){
				c_red[temp1]=red[temp1];
				c_blue[temp1]=blue[temp1];
			}
			u_move(c_red,c_blue);
			dfs(count+1,c_red,c_blue);
		}
		else if(temp==1){
			int c_red[3];
			int c_blue[3];
			for(temp1=0;temp1<3;temp1++){
				c_red[temp1]=red[temp1];
				c_blue[temp1]=blue[temp1];
			}
			d_move(c_red,c_blue);
			dfs(count+1,c_red,c_blue);
		}
		else if(temp==2){
			int c_red[3];
			int c_blue[3];
			for(temp1=0;temp1<3;temp1++){
				c_red[temp1]=red[temp1];
				c_blue[temp1]=blue[temp1];
			}
			r_move(c_red,c_blue);
			dfs(count+1,c_red,c_blue);
		}
		else if(temp==3){
			int c_red[3];
			int c_blue[3];
			for(temp1=0;temp1<3;temp1++){
				c_red[temp1]=red[temp1];
				c_blue[temp1]=blue[temp1];
			}
			l_move(c_red,c_blue);
			dfs(count+1,c_red,c_blue);
		}
	}
}
int main(){
	int temp,temp1;
	char garbage;
	int red[3]={0,};
	int blue[3]={0,};

	scanf("%d %d",&N,&M);
	for(temp=0;temp<N;temp++){
		scanf("%c",&garbage);
		for(temp1=0;temp1<M;temp1++){
			scanf("%c",&map[temp][temp1]);
			if(map[temp][temp1]=='R'){
				map[temp][temp1]='.';
				red[0]=temp;
				red[1]=temp1;
			}
			else if(map[temp][temp1]=='B'){
				map[temp][temp1]='.';
				blue[0]=temp;
				blue[1]=temp1;
			}
		}
	}
/*	printf("red: %d/%d/%d  /  blue: %d/%d/%d \n",red[0],red[1],red[2],blue[0],blue[1],blue[2]);
	while(1){
		scanf("%d",&temp);
		if(temp==8){
			u_move(red,blue);
			printf("red: %d/%d/%d  /  blue: %d/%d/%d \n",red[0],red[1],red[2],blue[0],blue[1],blue[2]);
		}
		else if(temp==6){
			r_move(red,blue);
			printf("red: %d/%d/%d  /  blue: %d/%d/%d \n",red[0],red[1],red[2],blue[0],blue[1],blue[2]);
		}
		else if(temp==4){
			l_move(red,blue);
			printf("red: %d/%d/%d  /  blue: %d/%d/%d \n",red[0],red[1],red[2],blue[0],blue[1],blue[2]);
		}
		else if(temp==2){
			d_move(red,blue);
			printf("red: %d/%d/%d  /  blue: %d/%d/%d \n",red[0],red[1],red[2],blue[0],blue[1],blue[2]);
		}
	}*/
	dfs(0,red,blue);
	if(m==11){
		printf("-1");
	}
	else{
		printf("%d",m);
	}
}