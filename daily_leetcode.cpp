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

    --------- binary search mid ---------
    mid = s + (end - s)/2

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

/*
    378. Kth Smallest Element in a Sorted Matrix
    https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int size = matrix.size();
        int high = matrix[size-1][size-1];

        while(low<high){
            int mid = low + (high - low)/2;
            int count = 0;
            
            // --------- returns the number of small elements than mid element ---------
            for(int i=0; i<size; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if(count < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }   
};

/*
    729. My Calendar I
    https://leetcode.com/problems/my-calendar-i/description/
*/

class MyCalendar {
public:
    MyCalendar() {
        
    }
    map <int, int> m;
    bool book(int start, int end) {
        m[start]++;
        m[end]--;

        int sum =0;
        for(auto elem: m){
            sum += elem.second;
            if(sum>1){
                m[start]--;
                m[end]++;
                return false;
            } 
        }
        return true;
    }
};

/*
    
*/

// --------- ---------
// --------- ---------
// --------- ---------

/**/