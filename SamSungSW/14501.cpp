#include <stdio.h>
#include <iostream>

using namespace std;

int N,total;
int T[20];
int P[20];

void dfs(int day,int sum){
	int temp,temp1,temp2;
	if(day<=N+1){
		if(sum>total){
			total=sum;
		}
		if(day==N+1){
			return;
		}
	}
	else{
		return;
	}
	dfs(day+T[day],sum+P[day]);
	dfs(day+1,sum);
}
int main(){
	int temp,temp1,temp2;

	scanf("%d",&N);
	for(temp=1;temp<=N;temp++){
		scanf("%d %d",&T[temp],&P[temp]);
	}
	dfs(1,0);
	printf("%d\n",total);
}