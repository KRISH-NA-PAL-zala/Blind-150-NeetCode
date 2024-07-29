#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> subset = {};

void dfs(vector<int>& candidates, int target, int index){
    int sum = 0;
    for(auto element: subset){
        sum += element;
    }
    if(index >= candidates.size() || sum >= target){
        result.push_back(subset);
        return;
    }

    subset.push_back(candidates[index]);
    dfs(candidates, target, index + 1);

    subset.pop_back();
    dfs(candidates, target, index + 1);
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    cout<<"nothing is done"<<endl;
    dfs(candidates, target, 0);
    cout<<"Something is done"<<endl;
    for(auto combinations: result){
        cout<<"[";
        for(auto combination : combinations){
            cout<< combination << " ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}