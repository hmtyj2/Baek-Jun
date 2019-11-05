#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int m=0;

int find(int map[][20]){
	int temp,temp1;
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp][temp1]>m){
				m=map[temp][temp1];
			}
		}
	}
	return m;
}
int u_move(int map[][20]){
	int temp,temp1,temp2;
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp][temp1]!=0){
				for(temp2=temp;temp2>0 && map[temp2-1][temp1]==0;temp2--){
					map[temp2-1][temp1]=map[temp2][temp1];
					map[temp2][temp1]=0;
				}
			}
		}
	}
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp][temp1]!=0){
				if(map[temp-1][temp1]==map[temp][temp1]){
					map[temp-1][temp1]*=2;
					map[temp][temp1]=0;
				}
			}
		}
	}
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp][temp1]!=0){
				for(temp2=temp;temp2>0 && map[temp2-1][temp1]==0;temp2--){
					map[temp2-1][temp1]=map[temp2][temp1];
					map[temp2][temp1]=0;
				}
			}
		}
	}	
}
int d_move(int map[][20]){
	int temp,temp1,temp2;
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[N-temp][temp1]!=0){
				for(temp2=temp;temp2>1 && map[N-temp2+1][temp1]==0;temp2--){
					map[N-temp2+1][temp1]=map[N-temp2][temp1];
					map[N-temp2][temp1]=0;
				}
			}
		}
	}
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[N-temp][temp1]!=0){
				if(map[N-temp+1][temp1]==map[N-temp][temp1]){
					map[N-temp+1][temp1]*=2;
					map[N-temp][temp1]=0;
				}
			}
		}
	}
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[N-temp][temp1]!=0){
				for(temp2=temp;temp2>1 && map[N-temp2+1][temp1]==0;temp2--){
					map[N-temp2+1][temp1]=map[N-temp2][temp1];
					map[N-temp2][temp1]=0;
				}
			}
		}
	}	
}
int r_move(int map[][20]){
	int temp,temp1,temp2;
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][N-temp]!=0){
				for(temp2=temp;temp2>1 && map[temp1][N-temp2+1]==0;temp2--){
					map[temp1][N-temp2+1]=map[temp1][N-temp2];
					map[temp1][N-temp2]=0;
				}
			}
		}
	}
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][N-temp]!=0){
				if(map[temp1][N-temp+1]==map[temp1][N-temp]){
					map[temp1][N-temp+1]*=2;
					map[temp1][N-temp]=0;
				}
			}
		}
	}
	for(temp=2;temp<=N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][N-temp]!=0){
				for(temp2=temp;temp2>1 && map[temp1][N-temp2+1]==0;temp2--){
					map[temp1][N-temp2+1]=map[temp1][N-temp2];
					map[temp1][N-temp2]=0;
				}
			}
		}
	}
}
int l_move(int map[][20]){
	int temp,temp1,temp2;
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][temp]!=0){
				for(temp2=temp;temp2>0 && map[temp1][temp2-1]==0;temp2--){
					map[temp1][temp2-1]=map[temp1][temp2];
					map[temp1][temp2]=0;
				}
			}
		}
	}
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][temp]!=0){
				if(map[temp1][temp-1]==map[temp1][temp]){
					map[temp1][temp-1]*=2;
					map[temp1][temp]=0;
				}
			}
		}
	}
	for(temp=1;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			if(map[temp1][temp]!=0){
				for(temp2=temp;temp2>0 && map[temp1][temp2-1]==0;temp2--){
					map[temp1][temp2-1]=map[temp1][temp2];
					map[temp1][temp2]=0;
				}
			}
		}
	}
}
int dfs(int count,int map[][20]){
	int temp,temp1,temp2;
	if(count==5){
		for(temp=0;temp<N;temp++){
			for(temp1=0;temp1<N;temp1++){
				if(map[temp][temp1]>m){
					m=map[temp][temp1];
				}
			}
		}
		return 0;
	}
	int map1[20][20];

	for(temp=0;temp<4;temp++){
		if(temp==0){
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			u_move(map1);
			dfs(count+1,map1);
		}
		else if(temp==1){
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			d_move(map1);
			dfs(count+1,map1);

		}
		else if(temp==2){
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			l_move(map1);
			dfs(count+1,map1);
		}
		else if(temp==3){
			for(temp1=0;temp1<N;temp1++){
				for(temp2=0;temp2<N;temp2++){
					map1[temp1][temp2]=map[temp1][temp2];
				}
			}
			r_move(map1);
			dfs(count+1,map1);
		}
	}
}
void printer(int map[][20]){
	int temp,temp1,temp2;
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			printf("%3d",map[temp][temp1]);
		}
		printf("\n");
	}
}
int main(){
	int temp,temp1,temp2,temp3,temp4;
	int move;
	int map[20][20];
	int flag;

	scanf("%d",&N);
	for(temp=0;temp<N;temp++){
		for(temp1=0;temp1<N;temp1++){
			scanf("%d",&map[temp][temp1]);
		}
	}
	/*while(1){
		scanf("%d",&flag);
		if(flag==8){
			u_move(map);
			printer(map);
		}
		else if(flag==2){
			d_move(map);
			printer(map);
		}
		else if(flag==4){
			l_move(map);
			printer(map);
		}
		else if(flag==6){
			r_move(map);
			printer(map);
		}
	}*/
	dfs(0,map);
	printf("%d",m);
	return 0;
}