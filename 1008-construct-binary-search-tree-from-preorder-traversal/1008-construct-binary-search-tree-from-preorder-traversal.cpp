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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)return NULL;
        TreeNode *root=new TreeNode(preorder[0]);
        stack<TreeNode*>st;
        st.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode *curr=new TreeNode(preorder[i]);
            if(curr->val<st.top()->val){
                st.top()->left=curr;
            }
            else{
                TreeNode *temp=nullptr;
              
                while(!st.empty() && curr->val>st.top()->val){
                    temp=st.top();
                    st.pop();
                    }
                    temp->right=curr;
                }
                st.push(curr);
            }
        return root;

        
    }
};