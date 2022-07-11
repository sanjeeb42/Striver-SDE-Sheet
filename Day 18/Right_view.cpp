class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            vector<int> ans;
            queue<TreeNode*> q;
            if (root == NULL) return ans;

            q.push(root);
            q.push(NULL);
            int last_val = root->val;
            while (q.size() > 0)
            {
                auto node = q.front();
                q.pop();

                if (node == NULL)
                {
                    ans.push_back(last_val);
                    if (q.size() == 0)
                    {
                        break;
                    }
                    q.push(NULL);
                    continue;
                }

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                last_val = node->val;
            }

            return ans;
        }
};
