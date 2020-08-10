#include <bits/stdc++.h>
using namespace std;

/*
             (0)
              1
            /   \
     (1) 2      3 (-1)
        /   \   / \
  (2) 4      5  6  7 (-2)
        \  (0) (0)
         8 (1)  
        /
  (2) 9 
  
  [4,2,8,1,5,6,3,7]

vertical level: 
1. [4], 
2. [2,8] or [8,2] 
3. [1,5,6],  => [5,1,6] is ok as well
4. [3], 
5. [7]
*/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

struct TreeNode{
  int val;
  TreeNode* left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SlowSolution {
public:
    vector<int> solution(TreeNode* root){
        if (root==nullptr)
            return {};
        
        unordered_map<TreeNode*,int> tag;
        
        dfs(root,0,tag); // tag the nodes
        
        int minTag = INT_MAX;
        int maxTag = INT_MIN;
        for (auto e:tag){
            minTag = min(minTag,e.second);
            maxTag = max(maxTag,e.second);
        }
        
        vector<int> ans;
        for (int i=minTag;i<=maxTag;i++)
            dfs(root,ans,i,tag);
        
        return ans;
    }
    // Time: O(n^2)
    // Space: O(n^2)

    void dfs(TreeNode *root, int counter, unordered_map<TreeNode*,int>& tag){ // preorder 
        if (root==nullptr)
            return;
        
        tag[root]=counter; // O(1)
        dfs(root->left,counter-1,tag);
        dfs(root->right,counter+1,tag);
    }
    // Time: O(n)
    // Space: O(n)

    void dfs(TreeNode *root, vector<int>& ans, int lookingTag, unordered_map<TreeNode*,int>& tag){ // preorder
        if (root==nullptr)
            return;
        
        if (tag[root]==lookingTag)
            ans.push_back(root->val);
        
        dfs(root->left,ans,lookingTag,tag);
        dfs(root->right,ans,lookingTag,tag);
    }
};
// Time: O(n^2)
// Space: O(n^2)


class OKSolution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root==nullptr)
            return {};
        
        unordered_map<int,vector<int>> tag;
        
        dfs(root,0,tag); // tag the nodes
        
        int minTag = INT_MAX;
        for (auto e:tag) // O(n)
            minTag = min(minTag,e.first);
        
        vector<vector<int>> ans;
        int key = minTag;
        while (tag.find(key)!=tag.end()){
            ans.push_back(tag[key]);
            key++;
        }
        
        return ans;
    }
    // Time: O(n^2)
    // Space: O(n^2)

    void dfs(TreeNode *root, int counter, unordered_map<int,vector<int>>& tag){ // preorder 
        if (root==nullptr)
            return;
        
        tag[counter].push_back(root->val); // O(1)
        dfs(root->left,counter-1,tag);
        dfs(root->right,counter+1,tag);
    }
    // Time: O(n)
    // Space: O(n)
};
// Time: O(n)
// Space: O(n)

struct myComparator {
  bool operator() (pair<int,int>& e1, pair<int,int>& e2){ // 
      if (e1.first!=e2.first) // different level
          return e1.first>e2.first; // first element is greater than the second
      else return e1.second>e2.second; // same level, first element is greater than the second
  }  
};

class ComparatorSolution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root==nullptr)
            return {};
        
        unordered_map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, myComparator >> tag;
        
        bfs(root,tag); // tag the nodes
        
        int minTag = INT_MAX;
        for (auto e:tag) // O(n)
            minTag = min(minTag,e.first);
        
        vector<vector<int>> ans;
        int key = minTag;
        int index = 0;
        while (tag.find(key)!=tag.end()){
            ans.push_back({});
            while (!tag[key].empty()){
                int val = tag[key].top().second;    
                ans[index].push_back(val);
                tag[key].pop();
            }
            key++;
            index++;
        }
        
        return ans;
    }
    // Time: O(n)
    // Space: O(n)

    void bfs(TreeNode *root, unordered_map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, myComparator >>& tag){ // preorder 
        if (root==nullptr)
            return;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int currLevel = -1;
        while (!q.empty()){
            int size = q.size();
            currLevel++;
            for (int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int counter = q.front().second;
                tag[counter].push({currLevel,node->val}); // O(1)
                q.pop();
                if (node->left!=nullptr)
                    q.push({node->left,counter-1});
                if (node->right!=nullptr)
                    q.push({node->right,counter+1});   
            }
        }
    }
    // Time: O(nlog n)
    // Space: O(n)
    
};
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root==nullptr)
            return {};
        
        unordered_map<int, priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>>> tag;
        
        bfs(root,tag); // tag the nodes
        
        int minTag = INT_MAX;
        for (auto e:tag) // O(n)
            minTag = min(minTag,e.first);
        
        vector<vector<int>> ans;
        int key = minTag;
        int index = 0;
        while (tag.find(key)!=tag.end()){
            ans.push_back({});
            while (!tag[key].empty()){
                int val = tag[key].top()[1];    
                ans[index].push_back(val);
                tag[key].pop();
            }
            key++;
            index++;
        }
        
        return ans;
    }
    // Time: O(n)
    // Space: O(n)

    void bfs(TreeNode *root, unordered_map<int, priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>>>& tag){ // preorder 
        if (root==nullptr)
            return;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int currLevel = -1;
        while (!q.empty()){
            int size = q.size();
            currLevel++;
            for (int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int counter = q.front().second;
                tag[counter].push({currLevel,node->val}); // O(1)
                q.pop();
                if (node->left!=nullptr)
                    q.push({node->left,counter-1});
                if (node->right!=nullptr)
                    q.push({node->right,counter+1});   
            }
        }
    }
    // Time: O(nlog n)
    // Space: O(n)
    
};
// Time: O(n)
// Space: O(n)

class SimpleSolution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        unordered_map<int,set<pair<int,int>>> tag;
        int min_tag = INT_MAX;
        int max_tag = INT_MIN;
        tagNodes(root,tag,min_tag,max_tag,0,0); // O(n)
        
        vector<vector<int>> ans;
        for (int i=min_tag;i<=max_tag;i++){// O(n)
            vector<int> tmp;
            for (auto e:tag[i])
                tmp.push_back(e.second);
            ans.push_back(tmp);
        }
        
        
        return ans;
    }
    
    void tagNodes(TreeNode* root, unordered_map<int,set<pair<int,int>>>& tag, int& min_tag, int& max_tag, int curr, int level){
        if (root == nullptr)
            return;
        
        min_tag = min(min_tag,curr);
        max_tag = max(max_tag,curr);
        tag[curr].insert({level,root->val});
        tagNodes(root->left,tag,min_tag,max_tag,curr-1,level+1);
        tagNodes(root->right,tag,min_tag,max_tag,curr+1,level+1);
    }
};
// Time: O(n)
// Space: O(n)

class FastestSolution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        unordered_map<int,set<pair<int,int>>> tag;
        int min_tag = INT_MAX;
        int max_tag = INT_MIN;
        tagNodes(root,tag,min_tag,max_tag); // O(n)
        
        vector<vector<int>> ans;
        for (int i=min_tag;i<=max_tag;i++){// O(n)
            vector<int> tmp;
            for (auto e:tag[i])
                tmp.push_back(e.second);
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
    void tagNodes(TreeNode* root, unordered_map<int,set<pair<int,int>>>& tag, int& min_tag, int& max_tag){
        if (root == nullptr)
            return;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int curr = q.front().second;
                q.pop();
                min_tag = min(min_tag,curr);
                max_tag = max(max_tag,curr);
                tag[curr].insert({level,node->val});
                
                if (node->left) q.push({node->left,curr-1});
                if (node->right) q.push({node->right,curr+1});            
            }
            level++;
        }
    }
};
// Time: O(n)
// Space: O(n)

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.verticalTraversal(root);

    cout << "[ ";
    for (auto row:ans){
        cout << "[ ";
        for (int e:row)
            cout << e << " ";
        cout << "] ";
    }
    cout << "] ";
  
    return 0;
}
