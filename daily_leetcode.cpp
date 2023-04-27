#include<bits/stdc++.h>
using namespace std;

/*
    890. Find and Replace Pattern
    https://leetcode.com/problems/find-and-replace-pattern/description/
*/

class Solution {
public:
    bool domatch(string word, string pattern){

        if(word.length() != pattern.length()){
            return false;
        }

        unordered_map<char, char> wordToPattern;
        unordered_map<char, char> patternToWord;

        for(int i =0; i< word.length(); i++ ){
            char w = word[i];
            char p = pattern[i];
            if(wordToPattern.count(w) == 0 && patternToWord.count(p) == 0 ){
                // mapping the letters if both are unmapped
                wordToPattern[w] = p;
                patternToWord[p] = w;
            }
            else if(wordToPattern[w] != p || patternToWord[p] != w){
                // if they are not mapped to same letter
                return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        for(string word: words){                                        // same as foreach in other languages
            if(domatch(word, pattern)){
                result.push_back(word);
            }
        }
        return result;
    }

};