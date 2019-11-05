#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int T,a,b,total;
	int temp,temp1;
	int arr[1001]={0,};
	scanf("%d",&T);
	for(temp=0;temp<T;temp++){
		scanf("%d %d",&a,&b);
		total=0;
		if(a==0){}
		else if(a==1){
			total+=5000000;
		}
		else if(a<=3){
			total+=3000000;
		}
		else if(a<=6){
			total+=2000000;
		}
		else if(a<=10){
			total+=500000;
		}
		else if(a<=15){
			total+=300000;
		}
		else if(a<=21){
			total+=100000;
		}
		if(b==0){}
		else if(b==1){
			total+=5120000;
		}
		else if(b<=3){
			total+=2560000;
		}
		else if(b<=7){
			total+=1280000;
		}
		else if(b<=15){
			total+=640000;
		}
		else if(b<=31){
			total+=320000;
		}
		arr[temp]=total;
	}
	for(temp=0;temp<T;temp++){
		printf("%d\n",arr[temp]);
	}
	return 0;
}