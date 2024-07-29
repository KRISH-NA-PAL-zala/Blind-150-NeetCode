#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k){
    int left_pointer = 0;
    int result = 0;
    int max_frequency = 0;
    vector<int> char_frequency(26);

    for(int right_pointer = 0;right_pointer < s.size();right_pointer++){
        char_frequency[s[right_pointer] - 'A']++;
        max_frequency = max(char_frequency[s[right_pointer] - 'A'], max_frequency);

        if(right_pointer - left_pointer + 1 - max_frequency > k){ // leght of substring = righ_pointer - left_pointer + 1
            char_frequency[s[left_pointer] - 'A']--;
            left_pointer++;
        }

        result = max(right_pointer - left_pointer + 1, result);
    }

    return result;
}

int main(){
    cout<<characterReplacement("AABAA", 1);
    return 0;
}