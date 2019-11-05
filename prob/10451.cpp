#include <stdio.h>
#include <iostream>

using namespace std;

int arr[1001];
int visit[1001];
int T,N;
int M[1000];

void dfs(int count,int index){
	int temp,temp1,temp2;
	if(visit[count]==1){
		M[index]+=1;
		return;
	}
	else{
		visit[count]=1;
		return dfs(arr[count],index);
	}
}
int main(){
	int temp,temp1,temp2;

	scanf("%d",&T);
	for(temp=0;temp<T;temp++){
		scanf("%d",&N);
		for(temp1=1;temp1<=N;temp1++){
			scanf("%d",&arr[temp1]);
		}
		for(temp2=1;temp2<=N;temp2++){
			if(visit[arr[temp2]]==0){
				dfs(arr[temp2],temp);
			}
		}
		for(temp2=1;temp2<=N;temp2++){
			visit[temp2]=0;
		}
	}
	for(temp=0;temp<T;temp++){
		printf("%d\n",M[temp]);
	}
}