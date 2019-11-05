#include <bits/stdc++.h>

using namespace std;

int N,M,H;
int ledge[31][11]={0,};	// row: 1~30 col=1~10
int mini=4;

void copy(int ledge2[][11],int ledge3[][11]){
	for(int temp=1;temp<=H;temp++){
		for(int temp1=1;temp1<=N;temp1++){
			ledge3[temp][temp1]=ledge2[temp][temp1];
		}
	}
}

int calculate(int count,int ledge2[][11]){
	int temp,temp1;
	int arr[11];
	for(temp=0;temp<11;temp++){
		arr[temp]=temp;
	}
	for(temp=1;temp<=H;temp++){
		for(temp1=1;temp1<=N;temp1++){
			if(ledge2[temp][temp1]==1){
				int temp2=arr[temp1];
				arr[temp1]=arr[temp1+1];
				arr[temp1+1]=temp2;
			}
		}
	}
	for(temp=1;temp<=N;temp++){
		if(arr[temp]!=temp){
			return 4;
		}
	}
	return count;
}


void dfs(int count, int row, int col, int ledge2[][11]){
	if(count==3 || (row>=H && col >=N-1)){
		int ans=calculate(count,ledge2);
		if(ans<mini){
			mini=ans;
		}
		return;
	}
	int temp,temp1,temp2;
	temp1=col;
	for(temp=row;temp<=H;temp++){
		for(;temp1<N;temp1++){
			if(ledge2[temp][temp1]==0 && ledge2[temp][temp1-1]==0
				&& ledge2[temp][temp1+1]==0){
				int ledge3[31][11]={0,};
				copy(ledge2,ledge3);
				ledge3[temp][temp1]=1;
				dfs(count+1,temp,temp1+1,ledge3);
			}
		}
		temp1=1;
	}
	int ledge3[31][11]={0,};
	copy(ledge2,ledge3);
	dfs(count,temp,temp1+1,ledge3);
}

int main(){
	int row,col;
	scanf("%d %d %d",&N,&M,&H);
	for(int temp=0;temp<M;temp++){
		scanf("%d %d",&row,&col);
		ledge[row][col]=1;
	}

	dfs(0,1,1,ledge);
	if(mini==4){
		mini=-1;
	}
	printf("%d",mini);

}