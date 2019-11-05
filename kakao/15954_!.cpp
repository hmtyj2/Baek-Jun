#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N,K;
	long long arr[501];
	int temp,temp1,temp2;
	long long avg,sqr_avg;
	long double v,d_m,d_sa;
	long double small;
	long long x,y;

	scanf("%d %d",&N,&K);
	for(temp=0;temp<N;temp++){
		scanf("%lld",&arr[temp]);
	}

	for(temp=0;temp<=N-K;temp++){
		for(temp2=K;temp+temp2<=N;temp2++){
			for(temp1=0,avg=0,sqr_avg=0;temp1<temp2;temp1++){
				avg+=(long long)arr[temp+temp1];
				sqr_avg+=((long long)arr[temp+temp1])*((long long)arr[temp+temp1]);
			}
			d_m=((long double)avg/(long double)temp2);
			d_sa=((long double)sqr_avg/(long double)temp2);
			v=d_sa-((d_m)*(d_m));

			if(temp==0 || small>v){
				small=v;
			}
		}
	}
	small=sqrt(small);
	printf("%.11Lf\n",small);
}