#include<bits/stdc++.h>

using namespace std;

bool isPermutation(vector<int> count){
    for(int i : count){
        if(i) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    if(s1.size() > s2.size()) return false;
    vector<int> count(26);

    for(int i = 0;i < s1.size();i++){
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    
    if(isPermutation(count)) return true;
    
    for(int i = s1.size();i < s2.size();i++){
        count[s2[i] - 'a']--;
        count[s2[i - s1.size()] - 'a']++;
        if(isPermutation(count)) return true;
    }
    return false;
}

int main(){

    cout<<checkInclusion("ab", "eidboaoo");
    return 0;
}