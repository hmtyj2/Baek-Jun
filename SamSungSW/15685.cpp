#include <bits/stdc++.h>

using namespace std;

int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
int map1[101][101]={0,};


void dragon(int count, int g, std::vector<int> &v){
	int temp,temp1,temp2;
	if(count==g){
		return;
	}
	for(temp=v.size()-1;temp>=0;temp--){
		v.push_back((v[temp]+1)%4);
	}
	dragon(count+1,g,v);
	return ;
}

void print(int row, int col, std::vector<int> &v){
	int temp,temp1,temp2;

	map1[row][col]=1;
	for(temp=0;temp<v.size();temp++){
		row+=dir[v[temp]][0];
		col+=dir[v[temp]][1];
		if(row>=0 && row<=100 && col>=0 && col<=100){
			map1[row][col]=1;
		}
	}
}

int counter(){
	int temp,temp1;
	int count=0;
	for(temp=0;temp<100;temp++){
		for(temp1=0;temp1<100;temp1++){
			if(map1[temp][temp1]==1 && map1[temp][temp1+1]==1 && map1[temp+1][temp1]==1
				&& map1[temp+1][temp1+1]==1){
				count++;
			}
		}
	}
	return count;
}

int main(){
	int N;
	int row,col,d,g;
	int temp,temp1,temp2;

	scanf("%d",&N);
	for(temp=1;temp<=N;temp++){
		scanf("%d %d %d %d",&col,&row,&d,&g);
		std::vector<int> v;
		v.push_back(d);
		dragon(0,g,v);
		print(row,col,v);
	}
	printf("%d\n",counter());
}