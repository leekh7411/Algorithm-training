#include <iostream>
#include <cstdio>
using namespace std;
int* merge(int* arr,int start,int end){
	if(end - start < 2){
		// stop dividing	
		cout << "last dividing > ";
		cout << "START : " << start << " / END : " << end << endl;
		int temp = 0;
		if(arr[start]>arr[end]){
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
		int* temp_arr = new int[end-start+1];
		cout << ">>>> End-Start+1  : " << end-start+1 << endl;
		cout << ">>>> Temp_Arr size: " << int(sizeof(temp_arr)/sizeof(temp_arr[0])) << endl;;
		for(int i = 0; i < end-start+1 ; i++){
			temp_arr[i] = arr[start+i];
			cout << "[i:" << i << "]: ";
			cout << temp_arr[i] << " ";
		}cout << endl;
		return temp_arr;
	}else{

		int half = start + (end-start)/2;
		cout << "START : " << start << " / HALF : " << half << " / END : " << end << endl;
		// keep dividing
		// ex. 3,4,5
		int* left_arr = merge(arr,start,half);
		int* right_arr = merge(arr,half+1,end);
		int* temp_arr = new int[end-start+1];

		int idx_temp = 0; 
		int temp_size = sizeof(temp_arr)/sizeof(int);

		int left_size = sizeof(left_arr)/sizeof(int);
		int idx_left = 0; 

		int right_size = sizeof(right_arr)/sizeof(int);
		int idx_right = 0;

		cout << "LEFT : " << left_size << " / RIGHT : " << right_size << " / TEMP : " << temp_size << endl;

		while(true){

			if((idx_temp == temp_size) || (idx_left == left_size && idx_right == right_size)){

				break;

			}else if(idx_left == left_size){

				temp_arr[idx_temp] = right_arr[idx_right];
				idx_right++;idx_temp++;

			}else if(idx_right == right_size){

				temp_arr[idx_temp] = left_arr[idx_left];
				idx_left++;idx_temp++;

			}else{

				if(right_arr[idx_right] > left_arr[idx_left]){
					temp_arr[idx_temp] = left_arr[idx_left];
					idx_left++;idx_temp++;
				}else{
					temp_arr[idx_temp] = right_arr[idx_right];
					idx_right++;idx_temp++;
				}

			}

			

		}
		cout << "SORTING.. > ";
		for(int i = 0 ; i < temp_size ; i++){
			cout << temp_arr[i] << " ";
		}cout << endl;	

		return temp_arr;
	}

}
int main(){
	int arr[5] = {30,54,23,555,12};
	int* new_arr = merge(arr,0,(sizeof(arr)/sizeof(int)) - 1);
	cout << "FINAL > ";
	for(int i = 0 ; i < (sizeof(new_arr)/sizeof(int)) ; i++){
		cout << new_arr[i] << " ";
	}cout << endl;
	return 0;
}