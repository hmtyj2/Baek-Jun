#include <bits/stdc++.h>

using namespace std;


int map1[13][13];
int core[12][2]={0,};
int T,T1,N,m_count;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int mini=987654321;
int c_maxi=0;

int check(int map2[][13],int row, int col, int comm){
	int count=0;
	for(row+=dir[comm][0],col+=dir[comm][1]
		;row>0 && row<=N && col>0 && col<=N;row+=dir[comm][0],col+=dir[comm][1]){
		count++;
		if(map2[row][col]!=0){
			return -1;
		}
	}
	return count;
}

void connect(int map2[][13],int row, int col, int comm){
	for(row+=dir[comm][0],col+=dir[comm][1]
		;row>0 && row<=N && col>0 && col<=N;row+=dir[comm][0],col+=dir[comm][1]){
		map2[row][col]=2;
	}
}

void copy(int map2[][13], int map3[][13]){
	int temp,temp1;
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			map3[temp][temp1]=map2[temp][temp1];
		}
	}
}

void print(int map2[][13]){
	int temp,temp1;
	printf("map is:\n");
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			printf("%d ",map2[temp][temp1]);
		}
		printf("\n");
	}
}

void dfs(int c_count ,int count , int line_count, int map2[][13]){
	int temp,temp1,temp2;

	if(count==m_count){
		if(c_count>c_maxi){
			c_maxi=c_count;
			mini=line_count;
		}
		else if(c_count==c_maxi){
			if(line_count<mini){
				mini=line_count;
			}
		}
		return;
	}
	for(temp=0;temp<4;temp++){
		temp2=check(map2,core[count][0],core[count][1],temp);
		if(temp2!=-1){
			int map3[13][13];
			copy(map2,map3);
			connect(map3,core[count][0],core[count][1],temp);
			dfs(c_count+1,count+1,line_count+temp2,map3);
		}
	}
	int map3[13][13];
	copy(map2,map3);
	dfs(c_count,count+1,line_count,map3);
}

int main(){
	int temp,temp1,temp2;
	std::vector<int> ans;

	scanf("%d",&T);
	for(T1=1;T1<=T;T1++){
		mini=987654321;
		c_maxi=0;
		scanf("%d",&N);
		for(m_count=0,temp=1;temp<=N;temp++){
			for(temp1=1;temp1<=N;temp1++){
				scanf("%d",&map1[temp][temp1]);
				if(map1[temp][temp1]==1){
					core[m_count][0]=temp;
					core[m_count][1]=temp1;
					m_count++;
				}
			}
		}
		dfs(0,0,0,map1);
		ans.push_back(mini);
	}
	for(temp=0;temp<T;temp++){
		printf("#%d %d\n",temp+1,ans[temp]);
	}
}