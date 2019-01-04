#include<bits/stdc++.h>

using namespace std;

bool canPlace(int mat[][9], int i, int j,  int n ,int number){
	// checking across the row and column
	for(int x = 0; x<n; x++){
		if(mat[i][x]==number || mat[x][j]==number)
			return false;
	}

	// checking in the subgrid
	// row index = i/root(n) * root(n)
	// col index = j/root(n) * root(n)
	// each subgrid is root(n)Xroot(n)

	int rn = sqrt(n);
	int sx = (i/rn)*sqrt(n);    ///CHANGE1
	int sy = (j/rn)*sqrt(n);

	for(int x= sx; x< sx + rn ;x++){
		for(int y = sy; y< sy+rn; y++){
			if(mat[x][y]==number)
				return false;
		}
	}

	return true;
}

bool soduku_solver(int mat[][9], int i, int j, int n){
	// if we reach n in rows , our job is done
    //cout<<i<<" "<<j<<endl;
	if(i==n){

		for(int r= 0; r<n; r++){
			for(int c=0; c<n; c++){
				cout<<mat[r][c]<<" ";
			}
			cout<<endl;
		}
		return true;
	}




	// if we have to change the row, i.e we reach the last coloumn of the row
	if(j==n)
		return soduku_solver(mat,i+1,0,n);

	// skip the filled cells
	if(mat[i][j]!=0){
		// going to the next cell in the row
		return soduku_solver(mat,i,j+1,n);
	}

	for(int num = 1; num<=n; num++){

		bool can_place_in_current_cell = canPlace(mat,i,j,n,num);

		if(can_place_in_current_cell){
			// place it if we can place
			mat[i][j]=num;
			// try to solve the remaining grid starting from next cell till n
			bool can_solveRemaining = soduku_solver(mat,i,j+1,n);

			if(can_solveRemaining)
				return true;
            else
                mat[i][j]=0;
		}

	}

	// we tried all numbers but no solution
	// backtrack

	mat[i][j]=0;
	return false;
}

int main(){
	int n=9;
	int mat[][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 

	 bool solve=soduku_solver(mat,0,0,n);
	if(!solve)
		cout<<"\n No soution exists"<<endl;

	return 0;
}