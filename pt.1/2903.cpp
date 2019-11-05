#include <iostream>
#include <stdio.h>
using namespace std;

int rec(int n){
	if(n==0){
		return 4;
	}
	else if(n==1){
		return 9;
	}
	else{
		return 3*rec(n-1)-rec(n-2);
	}
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%d\n",rec(N));
}