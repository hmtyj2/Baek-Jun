#include <iostream>
#include <stdio.h>
using namespace std;

int hanoi(int n, int start, int end, int empty){
	int c=0;
	if(n==1){
		printf("%d %d\n",start,end);
		return 1;
	}
	else{
		c+=hanoi(n-1,start,empty,end);
		printf("%d %d\n",start,end);
		c+=hanoi(n-1,empty,end,start);
		return c+1;
	} 
}


int main(){
	int N,temp;
	int count;
	scanf("%d",&N);
	for(temp=0,count=0;temp<N;temp++){
		count=2*count+1;
	}
	printf("%d\n",count);
	hanoi(N,1,3,2);
}