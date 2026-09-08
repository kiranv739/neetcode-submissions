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

class Codec {
public:

    string serialize(TreeNode* root) {
        string ans = "";
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto temp = q.front();
                if(temp == nullptr) {
                    ans += "N,";
                    q.pop();
                    continue;
                }

                ans += to_string(temp->val);
                ans.push_back(',');
                q.pop();
                
                if(temp->left!=nullptr) q.push(temp->left);
                else if(temp!=nullptr && temp->left==nullptr) q.push(nullptr);

                if(temp->right!=nullptr) q.push(temp->right);
                else if(temp!=nullptr && temp->right==nullptr) q.push(nullptr);
            }
        }
    return ans;
    }

    string getToken(string& data,int& index){
        string token = "";

    while(index < data.length() && data[index] != ',') {
        token += data[index];
        index++;
    }

    index++; 

    return token;
    }

    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int index = 0;

        string token = getToken(data, index);

        if(token == "N")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto temp = q.front();
                q.pop();
                
                token = getToken(data,index);       
                
                if(token=="N") temp->left = nullptr;
                else{
                    temp->left = new TreeNode(stoi(token));
                    q.push(temp->left);
                }
                
                token = getToken(data,index);
                
                if(token=="N") temp->right = nullptr;
                else{
                    temp->right = new TreeNode(stoi(token));
                    q.push(temp->right);
                }
            }
        }
    return root;
    }
};
