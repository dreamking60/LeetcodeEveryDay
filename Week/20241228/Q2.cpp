#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) {
            return word;
        }
        int size = word.length();
        char *w_char = new char[size+1];
        strcpy(w_char, word.c_str());
        int max_len = (size-numFriends)+1;
        char lgst_char = 'a';
        vector<string> res;

        for(int i = 0; i < size; i++) {
            if(w_char[i] > lgst_char) {
                lgst_char = w_char[i];
            }
        }

        for(int i = 0; i < size; i++) {
            if(w_char[i] == lgst_char) {
                if(i+max_len-1 < size) {
                    string tmp(w_char+i, max_len);
                    res.push_back(tmp);
                } else {
                    string tmp(w_char+i, size-i);
                    res.push_back(tmp);
                }
            }
        }

        sort(res.begin(), res.end());

        return res.back();
    }
};