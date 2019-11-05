#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int N;
	int cur,max,min;
	int temp;

	scanf("%d",&N);
	scanf("%d",&cur);
	min=cur;
	max=cur;
	for(temp=0;temp<N-1;temp++){
		scanf("%d",&cur);
		if(cur<min){
			min=cur;
		}
		else if(cur>max){
			max=cur;
		}
	}
	printf("%d",max-min);
}