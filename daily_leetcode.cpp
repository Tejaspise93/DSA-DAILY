#include<bits/stdc++.h>
using namespace std;

/*
    ---------map syntax---------
    unordered_map<char, char> wordToPattern;

    ---------initialize all values to zero---------
    int a[26] = {0}    

    ---------find size--------- 
        string ==>   string.lenght()
        vector ==>   vector.size()
        array  ==>   int size = sizeof(arr)/ sizeof(arr[0])
    
    ---------for each in cpp ---------
    for(string word : words2){
    
    }

    --------- 2d vector with all values intiziles to zero ---------
    vector<vector<int>> path(m,vector<int>(n,1))

    --------- ---------
    --------- ---------
    --------- ---------
*/



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

/*
    916. Word Subsets
    https://leetcode.com/problems/word-subsets/description/
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        int ans[26] = {0};
        for(string word : words2){
            int sub[26] ={0};
            // --------- mapping word ---------
            for(int i=0; i<word.length(); i++){        
                sub[word[i] - 'a']++;
            }
            // --------- checking the max as we only need to check the maximum occurance of a certain letter ---------
            for(int i =0; i<26; i++){
                ans[i] = max(ans[i], sub[i]);
            }
        }

        // --------- checking if the pattern is same or not ---------
        for(string word : words1){
            int main[26] = {0};
            for(int i=0; i<word.length(); i++){
                main[word[i] - 'a']++;
            }
            int i;
            for(i=0; i<26; i++){
                if(main[i] < ans[i]){
                    break;
                }
            }
            if(i == 26){
                result.push_back(word);
            }
        }
        return result;
    }

};

/*
    62. Unique Paths
    https://leetcode.com/problems/unique-paths/description/
    --------- dynamic programming ---------

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m,vector<int>(n,1));

        // --------- we are counting all the possible ways to come to the current block ---------
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                path[i][j] = path[i-1][j] + path[i][j-1]; 
            }
        }
        // --------- finally we get total number of possible ways to come to the last block ---------
        return path[m-1][n-1];
    }
};

// --------- ---------
// --------- ---------
// --------- ---------
