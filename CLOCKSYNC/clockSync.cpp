#include <iostream>
#include <vector>
#define CLOCK_SIZE 16
#define BTN_SIZE 10
#define INF 987654321
using namespace std;
vector<int>* button_connect;
vector<int> clock_state;
int min_clicks;
const int connections[52] = {
	0,1,2,-1,//4
	3,7,9,11,-1,//9
	4,10,14,15,-1,//14
	0,4,5,6,7,-1,//20
	6,7,8,10,12,-1,//26
	0,2,14,15,-1,//31
	3,14,15,-1,//35
	4,5,7,14,15,-1,//41
	1,2,3,4,5,-1,//47
	3,4,5,9,13//52
	};

void init_connection(){
	int btn = 0;
	for(int i = 0 ; i < 52 ; i++){
		if(connections[i] == -1){
			btn++;
		}else{
			button_connect[btn].push_back(connections[i]);
		}
	}
}
void print_clock_state(){
	cout << "Clock > ";
	for(int i = 0 ; i < CLOCK_SIZE ; i++){
		cout << clock_state[i] << " ";
	}
	cout << endl;
}
void rollback_clock(int num,int num_of_click){
	int new_state = clock_state[num] - 3 * num_of_click;
	if(new_state <= 0)new_state += 12;
	clock_state[num] = new_state;
}
void update_clock(int num,int num_of_click){
	int new_state = clock_state[num] + 3 * num_of_click;
	if(new_state > 12)new_state -= 12;
	clock_state[num] = new_state;
}
void rollback_button(int btn,int num_of_click){
	//cout << "> RollBack " << btn << " Click!" << endl;
	for(int i = 0 ; i < button_connect[btn].size(); i++){
		rollback_clock(button_connect[btn][i],num_of_click);
	}
	//print_clock_state();
}
void click_button(int btn,int num_of_click){
	//cout << "> Button " << btn << " Click!" << endl;
	for(int i = 0 ; i < button_connect[btn].size(); i++){
		update_clock(button_connect[btn][i],num_of_click);
	}
	//print_clock_state();
}
void search(int next_btn,int clicks){
	if(next_btn == 10){
		// The End is nigh!
		//print_clock_state();
		for(int i = 0; i < CLOCK_SIZE; i++){
			if(clock_state[i] != 12)return;
		}
		// If.. All clock states are '12' Then compare current clicks with min_clicks
		if(min_clicks > clicks){
			//cout << "min clicks update " << min_clicks << " to " << clicks << endl;
			min_clicks = clicks;
		}
		return;
	}

	for(int cur_click = 0; cur_click < 4; cur_click++){
		//cout << cur_click << " > ";
		click_button(next_btn,cur_click);
		search(next_btn+1,clicks+cur_click);
		rollback_button(next_btn,cur_click);
	}
}

int main(){
	// Initialize Button Conntection
	button_connect = new vector<int>[BTN_SIZE];
	init_connection();
	int test_cases = 0;
	cin >> test_cases;
	for(int t = 0; t < test_cases ; t++){
		// Init global variables
		min_clicks = INF;
		clock_state.clear();
		// Get clock states
		for(int i = 0 ; i < CLOCK_SIZE; i++){
			int state = 0;
			cin >> state;
			clock_state.push_back(state);
		}
		// Search Minimum clicks
		search(0,0);
		if(min_clicks == INF){
			cout << -1 << endl;
		}else{
			cout << min_clicks << endl;
		}
	}
	
	return 0;
}