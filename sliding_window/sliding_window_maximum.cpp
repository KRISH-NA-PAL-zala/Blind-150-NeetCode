#include<bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> nums, int k){
    deque<int> dq;
    vector<int> result;

    int left_pointer = 0, right_pointer = 0;

    while(right_pointer < nums.size()){
        while(!dq.empty() && nums[dq.back()] < nums[right_pointer]){
            dq.pop_back();
        }
        
        dq.push_back(right_pointer);

        if(left_pointer > dq.front()){
            dq.pop_front();
        }

        if(right_pointer + 1 >= k){
            result.push_back(nums[dq.front()]);
            left_pointer++;
        }
        right_pointer++;
    }

    return result;
}

int main(){
    
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    for(int i : maxSlidingWindow(nums, k)){
        cout<<i<<" ";
    }
    return 0;
}