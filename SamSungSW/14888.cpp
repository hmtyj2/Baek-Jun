#include <stdio.h>
#include <iostream>

using namespace std;

int arr[12];
int N;
int maxi=-1000000000;
int mini=+1000000000;

void dfs(int count,int current,int plus,int minus,int multi,int div){
	int temp;
	if(plus<0 || minus<0 || multi<0 || div<0){
		return;
	}
	if(count==0){
		dfs(count+1,arr[1],plus,minus,multi,div);
		return;
	}
	if(count==N){
		if(current>maxi){
			maxi=current;
		}
		if(current<mini){
			mini=current;
		}
		return;
	}
	dfs(count+1,current+arr[count+1],plus-1,minus,multi,div);
	dfs(count+1,current-arr[count+1],plus,minus-1,multi,div);
	dfs(count+1,current*arr[count+1],plus,minus,multi-1,div);
	dfs(count+1,current/arr[count+1],plus,minus,multi,div-1);
	return;
}
int main(){
	int temp,temp1,temp2;
	int plus,minus,multi,div;

	scanf("%d",&N);
	for(temp=1;temp<=N;temp++){
		scanf("%d",&arr[temp]);
	}
	scanf("%d %d %d %d",&plus,&minus,&multi,&div);

	dfs(0,0,plus,minus,multi,div);
	printf("%d\n%d\n",maxi,mini);
}