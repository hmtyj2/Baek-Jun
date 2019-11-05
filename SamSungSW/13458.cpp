#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int N;
	int map[1000001];
	int B,C;
	int temp,temp1;
	long long count=0;
	scanf("%d",&N);
	for(temp=1;temp<=N;temp++){
		scanf("%d",&map[temp]);
	}
	scanf("%d %d",&B,&C);
	for(temp=1;temp<=N;temp++){
		temp1=map[temp]-B;
		count+=1;
		if(temp1>0){
			if(temp1%C==0){
				count+=(temp1/C);
			}
			else{
				temp1-=(temp1%C);
				count+=((temp1/C)+1);
			}
		}
	}
	printf("%lld",count);
}