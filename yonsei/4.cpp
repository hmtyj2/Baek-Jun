#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,m,k,temp,temp1,temp2;
	int c1,c2,r1,r2;
	int total,curent;
	int map[50][50];
	int arr[50][50];

	scanf("%d %d %d",&n,&m,&k);
	for(temp=0;temp<n;temp++){
		for(temp1=0;temp1<m;temp1++){
			scanf("%d",&arr[temp][temp1]);
		}
	}

	for(r1=0;r1<n;r1++){
		for(c1=0;c1<m;c1++){
			for(r2=r1;r2<n;r2++){
				for(c2=c1;c2<m;c2++){
					for(temp1=r1;temp1<=r2;temp1++){
						for(temp2=c1;temp2<=c2;temp2++){
							map[temp1][temp2]++;
						}
					}
				}
			}
		}
	}
	for(temp=0;temp<n;temp++){
		for(temp1=0;temp1<m;temp1++){
			map[temp][temp1]=map[temp][temp1]%k;
		}
	}
	for(temp=0;temp<n;temp++){
		for(temp1=0;temp1<m;temp1++){
			if(arr[temp][temp1]==1){
				curent+=map[temp][temp1];
			}
			else if(arr[temp][temp1]==-1){
				total+=map[temp][temp1];
			}
		}
	}

	for(temp=0;temp<n;temp++){
		printf("\n");
		for(temp1=0;temp1<m;temp1++){
			printf("%d ",map[temp][temp1]);
		}
	}
	printf("\ntotal: %d, total mod k: %d \n",total,total%k);


}