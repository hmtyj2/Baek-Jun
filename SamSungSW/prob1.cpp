#include <stdio.h>
#include <iostream>
using namespace std;

int max(int *p_aper, int* c_ount, int n, int k){
    int temp,temp1;
    int cur,stack;
    int zero=0;
    
    for(temp=0;temp<=k;temp++){
        c_ount[temp]=0;
    }
    
    for(temp=0,stack=0,cur=1;temp<n;temp++){
        if(p_aper[temp]==0){
            stack++;
            zero=1;
        }
        else if(p_aper[temp]!=cur){
            if(zero==1){
                c_ount[cur]+=((stack-(p_aper[temp]-cur-1)));
                c_ount[p_aper[temp]]+=((stack-(p_aper[temp]-cur-1))+1);
                cur=p_aper[temp];
                stack=0;
                zero=0;
            }
            else{
                cur=p_aper[temp];
                c_ount[cur]++;
            }
        }
        else if(p_aper[temp]==cur){
            c_ount[cur]++;
        }
        if(temp==n-1){
            c_ount[cur]+=(stack-(k-cur));
        }
    }
    for(temp=0;temp<=k;temp++){
        printf("%dth = %d ",temp,c_ount[temp]);
    }
    printf("\n");
}


int main() {
    int T,N,K;
    int paper[10000]={0,};
    int count[10001]={0,};
    int temp,temp1;
    
    scanf("%d",&T);
    for(temp=0;temp<T;temp++){
        scanf("%d %d",&N,&K);
        for(temp1=0;temp1<N;temp1++){
            scanf("%d",&paper[temp1]);
        }
        max(paper,count,N,K);
    }
    
    
    
    
    return 0;
}
