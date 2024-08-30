/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int findPosition(vector<int>& inorder, int element, int n)
    // {
    //     for(int i = 0; i < n; i++)
    //         if(inorder[i] == element) 
    //             return i;
    //     return -1;
    // }
    void createMapping(unordered_map<int, int>& mp, vector<int>& inorder)
    {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int inStart, int inEnd, int n, unordered_map<int, int>& mp)
    {
        if(index >= n || inStart > inEnd) return NULL;

        int element = preorder[index++];
        TreeNode* node = new TreeNode(element);

        // int position = findPosition(inorder, element, n);
        int position = mp[element];

        node->left = solve(preorder, inorder, index, inStart, position - 1, n, mp);
        node->right = solve(preorder, inorder, index, position + 1, inEnd, n, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int index = 0;

        unordered_map<int, int>mp;
        createMapping(mp, inorder);

        TreeNode* ans = solve(preorder, inorder, index, 0, n-1, n, mp);
        return ans;
    }
};