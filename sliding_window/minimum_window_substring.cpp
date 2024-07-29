#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t){
    unordered_map<char, int> mp;
    for(char i : t){
        mp[i]++;
    }

    int left_pointer = 0, right_pointer = 0;
    int counter = t.size();
    int min_start = 0, min_length = INT_MAX;

    while(right_pointer < s.size()){
        if(mp[s[right_pointer]] > 0){
            counter--;
        }
        mp[s[right_pointer]]--;
        right_pointer++;
        
        while(counter == 0){
            if(right_pointer - left_pointer < min_length){
                min_start = left_pointer;
                min_length = right_pointer - left_pointer;
            }

            mp[s[left_pointer]]++;

            if(mp[s[left_pointer]] > 0){
                counter++;
            }
            left_pointer++;
        }
    }

    return min_length != INT_MAX ? s.substr(min_start, min_length) : "";
}

int main(){
    
    cout<<minWindow("ADOBECODEBANC", "ABC");
    return 0;
}