#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_set<char> substring;
    int result = 0, left_pointer = 0, right_pointer = 0;

    while(right_pointer < s.size()){

        while(substring.find(s[right_pointer]) != substring.end()){
            substring.erase(s[left_pointer]);
            left_pointer++;
        }

        substring.insert(s[right_pointer]);
        result = max(result, right_pointer - left_pointer + 1);
        right_pointer++;
    }

    return result;
}

int main(){
    cout<<lengthOfLongestSubstring("pwwkew");
    return 0;
}