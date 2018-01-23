#include <iostream>
using namespace std;
int ans;
char** board;
int W,H;
int T;
int* getFisrt(){
	int* point = new int[2];
	point[0] = -1;
	point[1] = -1; 
	for(int h = 0; h < H; h++){ 
		for(int w = 0; w < W; w++){
			if(board[h][w] == '.'){
 				point[0] = h;
 				point[1] = w;
				return point;  
			}
		} 
	}  
	return point; // No more space!
}
void print_board(){
	for(int h = 0; h < H; h++){
		for(int w = 0; w < W; w++){
			cout << board[h][w];
		}cout << endl;
	}cout << "========================" << endl;
}
bool search(){
	int* sp = getFisrt();
	int h = sp[0];
	int w = sp[1];
	if(w == -1){
		ans++;
		return true;
	}

	if((w+1 < W) && (h+1 < H) && (board[h][w+1]=='.') && (board[h+1][w]=='.')){
		board[h][w+1] = '#';
		board[h+1][w] = '#';
		board[h][w] = '#';
		search();
		board[h][w+1] = '.';
		board[h+1][w] = '.';
		board[h][w] = '.';
	}

	if((w+1 < W) && (h+1 < H) && (board[h][w+1]=='.') && (board[h+1][w+1]=='.')){
		board[h][w+1] = '#';
		board[h+1][w+1] = '#';
		board[h][w] = '#';
		search();
		board[h][w+1] = '.';
		board[h+1][w+1] = '.';
		board[h][w] = '.';
	}

	if((w+1 < W) && (h+1 < H) && (board[h+1][w]=='.') && (board[h+1][w+1]=='.')){
		board[h+1][w] = '#';
		board[h+1][w+1] = '#';
		board[h][w] = '#';
		search();
		board[h+1][w] = '.';
		board[h+1][w+1] = '.';
		board[h][w] = '.';
	}

	if((w-1 >= 0) && (h+1 < H) && (board[h+1][w]=='.') && (board[h+1][w-1]=='.')){
		board[h+1][w] = '#';
		board[h+1][w-1] = '#';
		board[h][w] = '#';
		search();
		board[h+1][w] = '.';
		board[h+1][w-1] = '.';
		board[h][w] = '.';
	}
	
	return false;
}

int main(){
	cin >> T;
	for(int testcase = 0; testcase < T; testcase++){
		ans = 0;
		cin >> H >> W;
		board = new char*[H];
		int score = 0;
		for(int h = 0 ; h < H; h++){
			board[h] = new char[W];
			for(int w = 0 ; w < W; w++){
				cin >> board[h][w];
				//cout << board[h][w];
				if(board[h][w] == '.')score++;
			}//cout << endl;	
		}
		if(score % 3 != 0){
			cout << 0 << endl;
			ans = 0;
		}else{
			search();
			cout << ans << endl;
			ans = 0;
		}
		
	}
	return 0;
}