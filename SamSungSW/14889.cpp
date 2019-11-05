#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int s[21][21];
int mini=1000000000;

void dfs(int count,int arr[21],int index){
	int temp,temp1,temp2;
	if(count==N/2){
		int start,link,dif;
		for(temp=1,start=0,link=0;temp<=N;temp++){
			if(arr[temp]==1){
				for(temp1=1;temp1<=N;temp1++){
					if(arr[temp1]==1){
						start+=s[temp][temp1];
					}
				}
			}
			else{
				for(temp1=1;temp1<=N;temp1++){
					if(arr[temp1]==0){
						link+=s[temp][temp1];
					}
				}
			}
		}
		dif=start-link;
		if(dif<0){
			dif*=-1;
		}
		if(dif<mini){
			mini=dif;
		}
		return;
	}
	for(temp=index+1;temp<=N;temp++){
		int copy_arr[21];
		for(temp1=1;temp1<=20;temp1++){
			copy_arr[temp1]=arr[temp1];
		}
		copy_arr[temp]=1;
		dfs(count+1,copy_arr,temp);
	}
	return;
}

int main(){
	int temp,temp1,temp2;
	int arr[21]={0,};
	scanf("%d",&N);
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			scanf("%d",&s[temp][temp1]);
		}
	}
	dfs(0,arr,0);
	printf("%d\n",mini);

}