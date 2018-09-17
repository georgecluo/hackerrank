#include <iostream>
#include <deque> 
using namespace std;

int findMax(deque<int> deq) {
    int max = 1; //min value
    for (auto &i : deq) {
            if (i > max) {
            max = i;
        }
    }
    return max;
}

void printKMax(int arr[], int n, int k){
    deque<int> cur_deq;
    int cur_deq_max = 1; //min value
    
    //populate current deque
    for (int i = 0; i < k; i++) {
        cur_deq.push_back(arr[i]);
    }
    cur_deq_max = findMax(cur_deq);
    cout << cur_deq_max << " ";
    
    for (int i = k; i < n; i++) {
        int popped = cur_deq[0];
        int pushed = arr[i];
        cur_deq.pop_front();
        cur_deq.push_back(pushed);
        if (pushed >= cur_deq_max) {
            cur_deq_max = pushed;
        } else {
            if (popped == cur_deq_max) {
                cur_deq_max = findMax(cur_deq);
            }
        }
        cout << cur_deq_max << " ";
    }
    cout << endl;
    return;
}



int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
