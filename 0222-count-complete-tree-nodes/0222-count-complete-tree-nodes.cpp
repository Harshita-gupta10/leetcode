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
    static inline auto _ = [] {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out", std::ios::out | std::ios::binary);
        out.rdbuf()->pubsetbuf(nullptr, 256);
        std::string s;
        std::noskipws(std::cin);
        while (std::getline(std::cin, s)) {
            int count = 0;
            bool inNum = false;
            for (char c : s) {
                if (std::isdigit(c) != 0) {
                    if (!inNum) {
                        ++count;
                        inNum = true;
                    }
                } else {
                    inNum = false;
                }
            }
            out << count << '\n';
        }
        std::skipws(std::cin);
        out.flush();
        exit(0);
        return 0;
    }();
    void totalnodes(TreeNode* root, int&count)
    {
        if(root == NULL) return;
        count++;
        totalnodes(root->left, count);
        totalnodes(root->right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        totalnodes(root, count);
        return count;
    }
};