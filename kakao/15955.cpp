#include <stdio.h>
#include <iostream>

using namespace std;

int N,Q,max_x,max_y,min_x,min_y;
struct cp{
	int x;
	int y;
};
int main(){
	int temp,temp1,temp2;
	struct cp check_points[250001];
	struct cp questions[250001];
	int hps[250001];
	struct cp* current;

	scanf("%d %d",&N,&Q);
	for(temp=1;temp<=N;temp++){
		scanf("%d %d",&check_points[temp].x,&check_points[temp].y);
		if(check_points[temp].x>max_x){
			max_x=check_points[temp].x;
		}
		else if(check_points[temp].x<min_x){
			min_x=check_points[temp].x;
		}
		if(check_points[temp].y>max_y){
			max_y=check_points[temp].y;
		}
		else if(check_points[temp].y<min_y){
			min_y=check_points[temp].y;
		}
	}
	for(temp=1;temp<=Q;temp++){
		scanf("%d %d %d",&questions[temp].x,&questions[temp].y,&hps[temp]);

	}
}