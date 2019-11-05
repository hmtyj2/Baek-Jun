#include <bits/stdc++.h>

using namespace std;

int mini;

int distance(std::vector<pair<int,int>> shop,std::vector<pair<int,int>> house){
	int mini_d,dist;
	for(int temp=0;temp<house.size();temp++){
		for(int temp1=0;temp1<shop.size();temp1++){
			
		}
	}
}

void dfs(int M, int index, vector<pair<int,int>> shop, vector<pair<int,int>> house){
	if(shop.size()==M){
		int m=distance(shop,house);
		if(m<mini){
			mini=m;
		}
		return;
	}
	else if(index>=shop.size()){
		return;
	}

	std::vector<pair<int,int>> shop_c;
	copy(shop.begin(),shop.end(),shop_c.begin());
	shop_c.erase(shop.begin()+index);
	dfs(M,index,shop_c,house);

	std::vector<pair<int,int>> shop_d;
	copy(shop.begin(),shop.end(),shop_d.begin());
	dfs(M,index+1,shop_d,house);
}

int main(){
	int temp,temp1,temp2;
	int N,M;
	std::vector<pair<int,int>> house;
	std::vector<pair<int,int>> shop;
	for(temp=1;temp<=N;temp++){
		for(temp1=1;temp1<=N;temp1++){
			scanf("%d",&temp2);
			if(temp2==1){
				house.push_back(make_pair(temp,temp1));
			}
			else if(temp2==2){
				shop.push_back(make_pair(temp,temp1));
			}
		}
	}
}