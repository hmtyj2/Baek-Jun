#include <iostream>
using namespace std;

int main(){
	int n,temp,temp1,temp2,temp3,count,ans=0;

	scanf("%d",&n);
	int *arr=new int[n+1]{0,};
	for(temp=0;temp<n;temp++){
		scanf("%d",&arr[temp]);
	}
	for(temp=0;temp<n;temp++){
		for(temp1=0,count=0;temp1<n-1;temp1++){
			temp2=arr[temp1+1];
			if(temp1==temp){
				
			}
			else if(arr[temp1]>temp2){
			 	break;
			}
			else {
					count++;
			}
		}
		printf("%d ",count);
		if(count==n-2){
			ans++;
		}
	}
	printf("\n%d",ans);
}