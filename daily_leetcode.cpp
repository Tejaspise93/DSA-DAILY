#include <bits/stdc++.h>
using namespace std;

/*
    ---------map syntax---------
        unordered_map<char, char> wordToPattern;

        iterator for a map
        map<char,char> m;
        map<char, char> :: iterator it = m.begin();

        while(it != m.end()){
            cout<< it->first << " "<< it->second <<endl;
            it++;
        }

        this will print the whole map in the same order as inserted (given its a map not an unordered map)

        for(auto i: m){
            cout<<i->first << " "<< i->second<<endl;
        }                               // for each in a map
        }                               // for each in a map


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

    --------- declare two variables in one line ---------
        int ext = p, ref = q;

    --------- sorting an vector using func ---------
        sort(vector.begin(), vector.end());

    --------- vector functions ---------

        --------- Insert element 6 at position 2 ---------
        v.insert(v.begin() + 2, 6);

        --------- Insert elements 7, 8, 9 at position 4 ---------
        v.insert(v.begin() + 4, {7, 8, 9});

        --------- Erase element at position 2 ---------
        v.erase(v.begin() + 2);

        --------- Erase elements from position 2 to position 4 (exclusive) ---------
        v.erase(v.begin() + 2, v.begin() + 4);

    --------- ---------
    --------- ---------
    --------- ---------
*/

/*
    1.
    890. Find and Replace Pattern
    https://leetcode.com/problems/find-and-replace-pattern/description/
*/

class Solution
{
public:
    bool domatch(string word, string pattern)
    {

        if (word.length() != pattern.length())
        {
            return false;
        }

        unordered_map<char, char> wordToPattern;
        unordered_map<char, char> patternToWord;

        for (int i = 0; i < word.length(); i++)
        {
            char w = word[i];
            char p = pattern[i];
            if (wordToPattern.count(w) == 0 && patternToWord.count(p) == 0)
            {
                // mapping the letters if both are unmapped
                wordToPattern[w] = p;
                patternToWord[p] = w;
            }
            else if (wordToPattern[w] != p || patternToWord[p] != w)
            {
                // if they are not mapped to same letter
                return false;
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;

        for (string word : words)
        { // same as foreach in other languages
            if (domatch(word, pattern))
            {
                result.push_back(word);
            }
        }
        return result;
    }
};

/*
    2.
    916. Word Subsets
    https://leetcode.com/problems/word-subsets/description/
*/

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> result;
        int ans[26] = {0};
        for (string word : words2)
        {
            int sub[26] = {0};
            // --------- mapping word ---------
            for (int i = 0; i < word.length(); i++)
            {
                sub[word[i] - 'a']++;
            }
            // --------- checking the max as we only need to check the maximum occurance of a certain letter ---------
            for (int i = 0; i < 26; i++)
            {
                ans[i] = max(ans[i], sub[i]);
            }
        }

        // --------- checking if the pattern is same or not ---------
        for (string word : words1)
        {
            int main[26] = {0};
            for (int i = 0; i < word.length(); i++)
            {
                main[word[i] - 'a']++;
            }
            int i;
            for (i = 0; i < 26; i++)
            {
                if (main[i] < ans[i])
                {
                    break;
                }
            }
            if (i == 26)
            {
                result.push_back(word);
            }
        }
        return result;
    }
};

/*
    3.
    62. Unique Paths
    https://leetcode.com/problems/unique-paths/description/
    --------- dynamic programming ---------

*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> path(m, vector<int>(n, 1));

        // --------- we are counting all the possible ways to come to the current block ---------
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        // --------- finally we get total number of possible ways to come to the last block ---------
        return path[m - 1][n - 1];
    }
};

/*
    4.
    378. Kth Smallest Element in a Sorted Matrix
    https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
*/
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int low = matrix[0][0];
        int size = matrix.size();
        int high = matrix[size - 1][size - 1];

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;

            // --------- returns the number of small elements than mid element ---------
            for (int i = 0; i < size; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

/*
    5.
    729. My Calendar I
    https://leetcode.com/problems/my-calendar-i/description/
*/

class MyCalendar
{
public:
    MyCalendar()
    {
    }
    map<int, int> m;
    bool book(int start, int end)
    {
        m[start]++;
        m[end]--;

        int sum = 0;
        for (auto elem : m)
        {
            sum += elem.second;
            if (sum > 1)
            {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/*
    6.
    2. Add Two Numbers
    https://leetcode.com/problems/add-two-numbers/description/
*/

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // ---------making new node and making it the start pointer  ---------
        ListNode *ans = new ListNode();
        // --------- new pointer for opreation ---------
        ListNode *temp = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            // --------- making new node and adding the digit value ---------
            ListNode *newnode = new ListNode(sum % 10);
            // --------- pointing next to the new node ---------
            temp->next = newnode;
            // ---------pointing new the pointer to the new note created ---------
            temp = temp->next;
        }
        // --------- as we add every new node to next pointer so staring point is pointing to the first digit and it has no value stored ---------
        return ans->next;
    }
};

/*
    7.
    9. Palindrome Number
    https://leetcode.com/problems/palindrome-number/description/

*/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // --------- if x is negative || x is not zero and ends with zero ---------
        // --------- if it ends with zero it cant be a palindrome ---------
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        if (x % 10 == x)
        {
            return true;
        }
        int real = x;
        // --------- for cases where INT gets overflowed ---------
        long long sum = 0;

        // --------- reverse a digit ---------
        while (x)
        {
            sum = (sum * 10) + x % 10;
            x = x / 10;
        }

        if (sum == real)
        {
            return true;
        }
        return false;
    }
};

/*
    Kadane's Algorithm
*/

int maxsum(vector<int> a)
{
    int maxsum = 0;
    int cursum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        cursum = cursum + a[i];
        if (cursum > maxsum)
        {
            maxsum = cursum;
        }
        if (cursum < 0)
        {
            cursum = 0;
        }
    }
    return maxsum;
}

/*
    8.
    14. Longest Common Prefix
    https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&id=top-interview-150
*/
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        string ans = "";

        // --------- needs to be done so we can avoid certain test cases ---------
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];

        for (int i = 0; i < min(first.length(), last.length()); i++)
        {
            if (last[i] != first[i])
            {
                return ans;
            }
            ans += first[i];
        }

        return ans;
    }
};

/*
    9.
    28. Find the Index of the First Occurrence in a String
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&id=top-interview-150
*/
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            // --------- to use it as a varaiable later ---------
            int j = 0;
            for (; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};

/*
    10.
    167. Two Sum II - Input Array Is Sorted
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&id=top-interview-150

*/
class Solution
{
public:
    /*
      time: o(n) space: o(n)
    */
    vector<int> twoSum1(vector<int> &numbers, int target)
    {
        // --------- to map the previous elements in the array ---------
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
        {
            // --------- target = num1 + num2   so  num1 = target - num2  ---------
            int c = target - numbers[i];

            // --------- checking if there is already an element in the array as the array is sorted we know the number will not repeat  ---------
            if (m[c])
            {
                ans.push_back(m[c]);
                ans.push_back(i + 1);
            }
            // --------- after checking its not the ans we push it in the map ---------
            m[numbers[i]] = i + 1;
        }
        return ans;
    }

    /*
        time:o(n) space:o(1)
    */
    vector<int> twoSum2(vector<int> &numbers, int target)
    {
        // --------- two pointer approach ---------
        vector<int> ans;
        int s = 0, e = numbers.size() - 1;

        while (s < e)
        {
            if ((numbers[s] + numbers[e]) == target)
            {
                ans.push_back(s + 1);
                ans.push_back(e + 1);
                break;
            }
            else if ((numbers[s] + numbers[e]) > target)
            {
                e--;
            }
            else
            {
                s++;
            }
        }

        return ans;
    }
};

/*
    11.
    11. Container With Most Water
    https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&id=top-interview-150
*/
class Solution
{
public:
    /*
        time:o(n**2) space:o(1)
    */
    int maxArea1(vector<int> &height)
    {
        // --------- we have to find area of the largest rectangle ---------
        int max = INT_MIN;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = height.size() - 1; j > i; j--)
            {
                int area = min(height[i], height[j]) * (j - i);
                if (area > max)
                {
                    max = area;
                }
            }
        }
        return max;
    }

    /*
        time:o(n) space:o(1)
    */

    int maxArea2(vector<int> &height)
    {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }
        return water;
    }
};

/*
    12.
    15. 3Sum
    https://leetcode.com/problems/3sum/description/
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            // --------- here ans needs to be  "a+b+c = 0"  so we need to find "b+c = -a" ---------
            int target = -nums[i];

            // ---------  double pointer---------
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];

                if (sum < target)
                {
                    front++;
                }
                else if (sum > target)
                {
                    back--;
                }

                else
                {
                    vector<int> aa = {nums[i], nums[front], nums[back]};
                    ans.push_back(aa);
                    // --------- to point it to next front element where its not same as the previous front ---------
                    while (front < back && nums[front] == aa[1])
                        front++;
                    // --------- to point it to next back element where its not same as the previous back ---------
                    while (front < back && nums[back] == aa[2])
                        back--;
                }
            }
            // --------- to point it to next first element where its not same as the previous frist ---------
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return ans;
    }
};

/*
    13.
    209. Minimum Size Subarray Sum
    https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&id=top-interview-150
*/

class Solution
{
public:
    /*
        time: o(n)
    */
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int total = 0;
        int mini = INT_MAX;
        int last = 0;

        // --------- here 'i' goes forword and last is the leftmost elements ---------
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            while (total >= target)
            {
                mini = min(mini, i + 1 - last);
                total -= nums[last++];
            }
        }
        return (mini == INT_MAX ? 0 : mini);
    }
};

/*
    14.
    2. Add Two Numbers
    https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // --------- created new node to return ---------
        ListNode *ans = new ListNode();
        // --------- to carry opration forward ---------
        ListNode *temp = ans;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;

            ListNode *nextnode = new ListNode(sum % 10);
            temp->next = nextnode;
            temp = temp->next;
        }
        return ans->next;
    }
};

/*
    15.
    21. Merge Two Sorted Lists
    https://leetcode.com/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution
{
public:
    ListNode *merge(ListNode *first, ListNode *second)
    {

        ListNode *curr1 = first;
        ListNode *next1 = curr1->next;
        ListNode *curr2 = second;
        ListNode *next2 = curr2->next;

        while (next1 != NULL && curr2 != NULL)
        {
            if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
            {
                // --------- inserting the curr2 node in between first ll ---------
                curr1->next = curr2;
                next2 = curr2->next;

                curr2->next = next1;
                // --------- updating the pointers ---------
                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return first;
                }
            }
        }
        if (next1 == NULL && curr2 != NULL)
        {
            curr1->next = curr2;
        }

        return first;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        int l1 = list1->val;
        int l2 = list2->val;

        // --------- so the first array always have the smallest value ---------
        if (l2 >= l1)
        {
            return merge(list1, list2);
        }
        else
        {
            return merge(list2, list1);
        }
    }
};

/*
    16.
    138. Copy List with Random Pointer
    https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // --------- to map the nodes of old with new ---------
        unordered_map<Node *, Node *> oldToNew;

        Node *originalNode = head;
        Node *copyNode = cloneHead;
        while (originalNode != NULL)
        {
            oldToNew[originalNode] = copyNode;
            originalNode = originalNode->next;
            copyNode = copyNode->next;
        }

        originalNode = head;
        copyNode = cloneHead;
        // --------- to point the randoms acc to map ---------
        while (originalNode != NULL)
        {
            copyNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            copyNode = copyNode->next;
        }
        return cloneHead;
    }
};

/*
    17.
    19. Remove Nth Node From End of List
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (n--)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

/*
    206. Reverse Linked List
    https://leetcode.com/problems/reverse-linked-list/
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

/*
    876. Middle of the Linked List
    https://leetcode.com/problems/middle-of-the-linked-list/description/
*/
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast)
        {
            fast = fast->next;
            // --------- to check if fast is at the last node if yes then return slow or increment it ---------
            if (fast)
            {
                fast = fast->next;
            }
            else
            {
                return slow;
            }
            slow = slow->next;
        }
        return slow;
    }
};

/*
    83. Remove Duplicates from Sorted List
    https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return head;
        ListNode *curr = head;
        ListNode *fow = curr->next;
        while (fow)
        {
            if (curr->val == fow->val)
            {
                fow = fow->next;
                curr->next = curr->next->next;
            }
            else
            {
                fow = fow->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

/*
    82. Remove Duplicates from Sorted List II
    https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp = head;
        unordered_map<int, int> ocurred;
        while (temp)
        {
            ocurred[temp->val]++;
            temp = temp->next;
        }

        // --------- to point the head at first the non repeating node  ---------
        temp = head;
        while (temp)
        {
            if (ocurred[temp->val] == 1)
            {
                head = temp;
                break;
            }
            temp = temp->next;

            // --------- for edge case where all the nodes are repeted  ---------
            if (temp == nullptr)
            {
                return nullptr;
            }
        }

        ListNode *prev = head;
        temp = head->next;

        while (temp)
        {
            if (ocurred[temp->val] == 1)
            {
                prev = temp;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
                prev->next = temp;
            }
        }

        return head;
    }
};

/*
    86. Partition List
    https://leetcode.com/problems/partition-list/description/
*/
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(-1);
        ListNode *large = new ListNode(-1);
        ListNode *small_head = small;
        ListNode *large_head = large;
        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
                head = head->next;
                small->next = NULL;
            }
            else
            {
                large->next = head;
                large = large->next;
                head = head->next;
                large->next = NULL;
            }
        }
        small->next = large_head->next;
        return small_head->next;
    }
};

/*
    205. Isomorphic Strings
    https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> letters;
        unordered_map<char, bool> used;

        for (int i = 0; i < s.length(); i++)
        {
            if ((!letters[s[i]]) && (!used[t[i]]))
            {
                letters[s[i]] = t[i];
                used[t[i]] = true;
            }
            else if ((!letters[s[i]]) && used[t[i]])
            {
                return false;
            }
            else if ((letters[s[i]]) && (t[i] != letters[s[i]]))
            {
                return false;
            }
        }
        return true;
    }
};

/*
    100. Same Tree
    https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // --------- base cases ---------
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;

        if (q->val != p->val)
            return false;
        // --------- recurvise call ---------
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
    226. Invert Binary Tree
    https://leetcode.com/problems/invert-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150
*/
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);
        }

        return root;
    }
};
/*

*/

// --------- ---------
// --------- ---------
// --------- ---------

/*

*/