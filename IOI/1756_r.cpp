#include <iostream>
#include <stdio.h>
using namespace std;

/*int put(int *p_oven, int p_pizza, int p_bottom){
	int p_temp;
	if(p_bottom==0){
		return 0;
	}
	for(p_temp=1;p_temp<p_bottom;p_temp++){
		if(p_oven[p_temp]<p_pizza){
			return p_temp-1;
		}
	}
	if(p_temp=p_bottom-1){
		return p_temp;
	}

}*/

int main(){
	int D,N;
	int temp,temp1,pizza,bottom;
	int oven[300001];
	int pizza_arr[300000];
	scanf("%d %d",&D,&N);
	for(temp=0;temp<D;temp++){
		scanf("%d",&oven[temp+1]);
	}
	for(temp=0;temp<N;temp++){
		scanf("%d",&pizza_arr[temp]);
	}

/*	for(temp=0;temp<N;temp++){
		if(temp==0){
			bottom=put(oven,pizza_arr[temp],D+1);
			printf("%dth=%d\n",temp,bottom);
		}
		else{
			temp1=put(oven,pizza_arr[temp],bottom);
			bottom=temp1;
			printf("%dth=%d\n",temp,bottom);
		}
	}*/
	for(temp=0,bottom=D+1;temp<N;temp++){
		if(bottom==0){
			printf("%d",bottom);
			return 0;
		}
		for(temp1=1;temp1<bottom;temp1++){
			if(oven[temp1]<pizza_arr[temp]){
				bottom=temp1-1;
			}
		}
	}
	printf("%d",bottom);

}