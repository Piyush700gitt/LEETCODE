class Solution {
public:

    int number(TreeNode *root, int total) {
        if (root == NULL)
            return total;

        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;
        int count = 0;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            sum += curr->val;
            count++;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        if (sum / count == root->val)
            total++;

        total = number(root->left, total);
        total = number(root->right, total);

        return total;
    }

    int averageOfSubtree(TreeNode* root) {
        return number(root, 0);
    }
};