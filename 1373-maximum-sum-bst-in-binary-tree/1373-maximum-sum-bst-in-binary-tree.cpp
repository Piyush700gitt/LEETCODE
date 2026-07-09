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
struct datatype{
    int mini;
    int maxi;
    int sum;
    bool isbst;

};
int ans=0;
datatype solve(TreeNode *root){
    if(root==nullptr)return {
        INT_MAX,INT_MIN,0,true
    };
    datatype left=solve(root->left);
    datatype right=solve(root->right);
    if(left.isbst && right.isbst && left.maxi<root->val && right.mini >root->val){
        int currsum=left.sum + right.sum + root->val;
        ans=max(ans,currsum);
        return {
            min(root->val,left.mini),max(root->val,right.maxi),currsum,true
        };
    }
    return {INT_MAX,INT_MIN,0,false}; 

}
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;

        
    }
};