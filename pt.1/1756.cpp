#include <iostream>
#include <stdio.h>

using namespace std;

int bake(int* b_oven, int b_p_size, int* b_cur){
	int b_temp,b_temp1,b_temp2;

	if(*b_cur<=1){
		return 0;
	}
	else{
		for(b_temp=1;b_temp<*b_cur;b_temp++){
			if(b_oven[b_temp]<b_p_size){
				*b_cur=b_temp-1;
				//printf("2= %d : %d\n",b_p_size,*b_cur);
				return 1;
			}
			else if(b_temp==*b_cur-1){	// meet the bottom.
				*b_cur=*b_cur-1;
				//printf("1= %d : %d\n",b_p_size,*b_cur);
				return 1;
			}
		}
	}
}

int main(){
	int D,N;
	int temp,temp1,cur;

	scanf("%d %d",&D,&N);
	int *oven=new int[D+2];
	int *pizza=new int[N];
	for(temp=1;temp<=D;temp++){
		scanf("%d",&oven[temp]);
	}
	for(temp=0;temp<N;temp++){
		scanf("%d",&pizza[temp]);
	}

	for(temp=0,cur=D+1;temp<N;temp++){
		if(bake(oven,pizza[temp],&cur)==0){
			printf("0");
			return 0;
		}
	}
	printf("%d\n",cur);
}