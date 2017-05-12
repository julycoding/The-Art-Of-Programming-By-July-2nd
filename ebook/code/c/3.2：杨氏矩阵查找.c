#include <stdio.h>
#include <iostream>
using namespace std;

#define ROW 4
#define COL 4

bool YoungMatrix(int array[][COL], int searchkey){
	int i = 0, j = COL - 1;
	int var = array[i][j];
	while (true){
		if (var == searchkey)
			return true;
		else if (var < searchkey && i < ROW - 1)
			var = array[++i][j];
		else if (var > searchkey && j > 0)
			var = array[i][--j];
		else
			return false;
	}
}

int main(){
	int array[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int searchkey;
	cin >> searchkey;
	if (YoungMatrix(array, searchkey)){
		printf("存在");
	}
	else{
		printf("不存在");
	}
}
