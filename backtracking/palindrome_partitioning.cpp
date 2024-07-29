#include<iostream>
#include<vector>
using namespace std;
  
bool isPalindrome(string s, int left, int right){
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
} 
void dfs(string& s, int index, vector<string>& subset, vector<vector<string>>& result){
    if(index == s.size()){
        result.push_back(subset);
        return;
    }

    for(int i = index;i < s.size();i++){
        string subString = s.substr(index, i - index + 1);
        if(isPalindrome(subString, index, i)){
            subset.push_back(subString);
            dfs(s, i + 1, subset, result);
            subset.pop_back();
        }
    }
}

int main(){
    string s = "aab";
    vector<string> subset;
    vector<vector<string>> result; 
    dfs(s, 0, subset, result);
    for(auto subset: result){
        cout<<"[";
        for(auto element : subset){
            cout<< element << " ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}