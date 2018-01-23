#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C,N;
int MAX;
int* fences;
int getMax(int A,int B){
	if(A>B)return A;
	return B;
}
void updateMax(int A){
	MAX = getMax(A,MAX);
}
int check(int mid){
	int sum = fences[mid];
	for(int i = mid+1; i < N; i++){
		if(fences[i] >= fences[mid]){
			sum += fences[mid];
		}else{
			break;
		}
	}
	for(int i = mid-1; i >= 0; i--){
		if(fences[i] >= fences[mid]){
			sum += fences[mid];
		}else{
			break;
		}
	}
	return sum;
}
int devide(int start,int end){
	if(end - start == 0){
		return fences[end];
	}else{
		int mid = (start + end) / 2;
		int left_sum = devide(start,mid); // case 1: highest in left side
		int right_sum = devide(mid+1,end);// case 2: highest in right side
		int mid_sum = 0;				  // case 3: highest with middle area
		if(fences[mid] < fences[mid+1]){
			mid_sum = check(mid);
		}else{
			mid_sum = check(mid+1);
		}
		return getMax(mid_sum,getMax(left_sum,right_sum));
	}
}

int main(){
	C = 0; N = 0;
	cin >> C;
	
	for(int c = 0; c < C; c++){
		cin >> N;
		MAX = -1;
		fences = new int[N];
		for(int i = 0 ; i < N; i++){
			cin >> fences[i];
		}
		updateMax(devide(0,N-1));
		cout << MAX << endl;
		
	}
	return 0;
}