#include <iostream>
#include <stdio.h>
using namespace std;

int rec_pib(int *arr, int n, int t){
	if(n==0){
		return 0;
	}
	if(t==n){
		return arr[n%3];
	}
	else{
		arr[t%3]=arr[(t+1)%3]+arr[(t+2)%3];
	}
	return rec_pib(arr,n,t+1);
}

int main(){
	int n,temp;
	int arr[3]={2,1,1};

	scanf("%d",&n);
	printf("\n%d\n",rec_pib(arr,n,1));

}