#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
	int n,m;
	int temp,temp1;
	int R,B,G;
	int total;

	scanf("%d %d",&n,&m);
	for(temp=0;temp<n;temp++){
		if(temp!=0){
			printf("\n");
		}
		for(temp1=0;temp1<m;temp1++){
			scanf("%d %d %d",&R,&G,&B);
			total=2126*R + 7152*G + 722*B;
			if(total<510000){
				printf("#");
			}
			else if(total<1020000){
				printf("o");
			}
			else if(total<1530000){
				printf("+");
			}
			else if(total<2040000){
				printf("-");
			}
			else{
				printf(".");
			}
		}
	}
	return 0;
}
