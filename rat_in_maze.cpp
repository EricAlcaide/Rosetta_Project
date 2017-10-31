#include <iostream>
using namespace std;

bool solveMaze(char maze[][10],int sol[][10],int i,int j,int n,int m){

	if(i==n-1&& j==m-1){
		sol[i][j]=1;

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	///rec call 
	//assume that rat passes through current cell
	sol[i][j]=1;
	//travel in X axis

	if(sol[i][j+1]!='X' && j+1<=m){
		bool rightse=solveMaze(maze,sol,i,j+1,n,m);

		if(rightse){
			return true;
		}
	}

	if(sol[i+1][j]!='X' && i+1<=n){
		bool downse=solveMaze(maze,sol,i+1,j,n,m);
		if(downse){
			return true;
		}
	}
//nahi rakh paye
	sol[i][j]=0;
//backtrack is need to be done	
return false;
}

int main(){

	int sol[10][10]={0};

	char maze[10][10]={
		"00000",
		"00X0X",
		"0X00X",
		"0X000",
		"X0X00"
	};

	solveMaze(maze,sol,0,0,4,3);
}