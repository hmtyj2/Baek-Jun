#include <iostream>
using namespace std;

int check(int *arr,int n){
	int temp,temp1,temp2,count=0;
	for(temp=0;temp<n-2;temp++){
		if(arr[temp]>arr[temp+1]){
			break;
		}
		else{
			count++;
		}
	}
	if(count==n-2){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int n,temp,temp1,temp2,count,ans=0;

	scanf("%d",&n);
	int *arr=new int[n];
	int *arr1=new int[n-1];

	for(temp=0;temp<n;temp++){
		scanf("%d",&arr[temp]);
	}
	for(temp=0;temp<n;temp++){
		for(temp1=0,temp2=0;temp1<n;temp1++){
			if(temp==temp1){
				continue;
			}
			else{
				arr1[temp2]=arr[temp1];
			}
			temp2++;
		}
		if(check(arr1,n)==1){
			ans++;
		}
	}
	printf("%d\n",ans);		
}
	