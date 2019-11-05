#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N,K;
	int arr[501];
	int temp,temp1,temp2;
	int m;
	long double v,d_m;
	long double small;

	scanf("%d %d",&N,&K);
	for(temp=0;temp<N;temp++){
		scanf("%d",&arr[temp]);
	}

	for(temp=0;temp<=N-K;temp++){
		for(temp2=K;temp+temp2<=N;temp2++){
			for(temp1=0,m=0;temp1<temp2;temp1++){
				m+=arr[temp+temp1];
			}
			d_m=((long double)m/temp2);
			for(temp1=0,v=0;temp1<temp2;temp1++){
				v+=((long double)(arr[temp+temp1]-d_m))*((long double)(arr[temp+temp1]-d_m));
			}
			v=v/temp2;
			if(temp==0 || small>v){
				small=v;
			}
		}
	}
	small=sqrt(small);
	printf("%.11Lf\n",small);
}