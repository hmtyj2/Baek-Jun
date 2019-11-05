#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,w;
	int count=0,temp,temp1,temp2;
	double ans;

	scanf("%d %d",&n,&w);
	int *tree=new int[n+1]{0,};

	for(temp=0;temp<n-1;temp++){
		scanf("%d %d",&temp1,&temp2);
		tree[temp1]++;
		tree[temp2]++;
	}
	for(temp=2;temp<n+1;temp++){
		if(tree[temp]==1){
			count++;
		}
	}
	printf("\n%f\n",(double)w/(double)count);



}