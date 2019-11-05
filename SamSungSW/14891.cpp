#include <bits/stdc++.h>

using namespace std;

int sawtooth[5][8];

void rotate(int number,int comm){
	int temp,temp1;
	int copy_sawtooth[8];
	for(temp=0;temp<8;temp++){
		copy_sawtooth[temp]=sawtooth[number][temp];
	}
	if(comm==1){
		for(temp=0;temp<8;temp++){
			sawtooth[number][(temp+1)%8]=copy_sawtooth[temp];
		}
	}
	else if(comm==-1){
		for(temp=0;temp<8;temp++){
			sawtooth[number][(temp+7)%8]=copy_sawtooth[temp];
		}
	}
}

int main(){
	int temp,temp1,temp2;
	int n;
	int input_n,input_r;
	int point=0;

	for(temp=1;temp<=4;temp++){
		for(temp1=0;temp1<8;temp1++){
			scanf("%1d",&sawtooth[temp][temp1]);
		}
	}
	scanf("%d",&n);
	for(temp=0;temp<n;temp++){
		int comm[5]={0,};
		scanf("%d %d",&input_n,&input_r);
		comm[input_n]=input_r;
		for(temp1=input_n;temp1<4;temp1++){
			if(sawtooth[temp1][2]==sawtooth[temp1+1][6]){
				break;
			}
			else{
				comm[temp1+1]=-1*comm[temp1];
			}
		}
		for(temp1=input_n;temp1>1;temp1--){
			if(sawtooth[temp1][6]==sawtooth[temp1-1][2]){
				break;
			}
			else{
				comm[temp1-1]=-1*comm[temp1];
			}
		}
		rotate(1,comm[1]);
		rotate(2,comm[2]);
		rotate(3,comm[3]);
		rotate(4,comm[4]);
	}
	for(int score=1,temp=1;temp<=4;temp++,score*=2){
		if(sawtooth[temp][0]==1){
			point+=score;
		}
	}
	printf("%d\n",point);

}