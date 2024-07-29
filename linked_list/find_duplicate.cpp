#include<bits/stdc++.h>

using namespace std;

int find_duplicate(vector<int> nums){
    int slow = 0;
    int fast = 0;

    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];

        if(slow == fast){
            break;
        }
    }

    fast = 0;

    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector<int> nums = {3,1,3,4,2};

    cout<<find_duplicate(nums);
    return 0;
}