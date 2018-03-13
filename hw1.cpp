#include <iostream>
using namespace std;
int jump[10][10] = {0};

int countWay(bool visit[10], int now, int otherNode){
	//when reach last Node
	if(otherNode <= 0){
		return 1;
	}

	int way = 0;
	visit[now] = true;

	for(int i = 1; i < 10; ++i){
		//if not visited && (not across another node || the acrossed node has been visited)
		if(visit[i] == 0 && (jump[i][now] == 0 || visit[jump[i][now]])){
			way += countWay(visit, i, otherNode - 1);
		}
	}


	visit[now] = false;

	return way;
}

int theWayOfNode(int a,int b){
	int way = 0;
	bool visit[10] = {0};

	//between two node exist:
	jump[1][3] = jump[3][1] = 2;
	jump[4][6] = jump[6][4] = 5;
	jump[7][9] = jump[9][7] = 8;
	jump[1][7] = jump[7][1] = 4;
	jump[2][8] = jump[8][2] = 5;
	jump[3][9] = jump[9][3] = 6;
	jump[1][9] = jump[9][1] = 5;
	jump[3][7] = jump[7][3] = 5;

	for(int i = a; i <= b; ++i){
		// begin at 1 3 7 9
		way += 4 * countWay(visit, 1, i-1);
		// begin at 2 4 6 8
		way += 4 * countWay(visit, 2, i-1);
		// begin at 5
		way += 1 * countWay(visit, 5, i-1);
	}

	return way;
}

int main(){
	int min = 4;
	int max = 6;

	cout << theWayOfNode(4,6);
	cout << "\n";
	cout << theWayOfNode(4,4);
	cout << "\n";
	cout << theWayOfNode(5,5);
	cout << "\n";
	cout << theWayOfNode(6,6);
	cout << "\n";
	cout << theWayOfNode(7,7);
	cout << "\n";
	cout << theWayOfNode(8,8);
	cout << "\n";
	cout << theWayOfNode(9,9);
	cout << "\n";
	cout << theWayOfNode(4,9);
	return 0;
}
