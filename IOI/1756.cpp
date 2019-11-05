#include <iostream>
#include <stdio.h>
using namespace std;

int put(int *p_oven, int p_pizza, int p_bottom){
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

}

int main(){
	int D,N;
	int temp,temp1,pizza,bottom;
	int oven[300001];
	//int pizza_arr[300000];
	scanf("%d %d",&D,&N);
//	int *oven=new int[D+1];
	for(temp=0;temp<D;temp++){
		scanf("%d",&oven[temp+1]);
	}

	for(temp=0;temp<N;temp++){
		scanf("%d",&pizza);
		if(temp==0){
			bottom=put(oven,pizza,D+1);
			//printf("%dth=%d\n",temp,bottom);
		}
		else{
			temp1=put(oven,pizza,bottom);
			bottom=temp1;
			//printf("%dth=%d\n",temp,bottom);
		}
	}
	printf("%d",bottom);

}