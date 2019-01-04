#include<iostream>
using namespace std;

bool ratinamaze(char maze[10][10], int soln[][10], int i, int j, int m, int n){
	// if we reach end of maze, our job is done
	if(i==m && j==n){
		// updating the value of soln array
		soln[m][n]=1;

		for(int i=0; i<=m; i++){
			for(int j=0; j<=n; j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}



// rat must stay inside the maze
	if(i>m || j>n){
		return false;
	}
//  if a cell is blocked, we can't find a path from there
	if(maze[i][j]=='X') {
		return false;
	}

// assuming that solution exists through curretn cell as we checked already
	soln[i][j]=1;

	bool right_success = ratinamaze(maze, soln, i, j+1, m, n); //checking for right side
	bool down_success = ratinamaze(maze, soln, i+1, j, m, n); //checking for down side

// backtracking after a call completes
    soln[i][j]=0;

// if either is possible, a apth exists and return true
	if(right_success || down_success )
		return true;

	return false;


}


int main(){

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int soln[10][10]={0};
	int m=4,n=4;

	bool ans = ratinamaze(maze,soln, 0, 0, m-1, n-1);
	if(!ans){
		cout<<"\n No path !!";
	}
}