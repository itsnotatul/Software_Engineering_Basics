#include<iostream>
using namespace std;
#include<vector>
#include<queue>


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

vector<string> v;
class Codec {
private:
    static TreeNode* buildtree(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            if(nums[i] != 1002) 
            {
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            }
            i++;
        }
        if (i < nums.size()) {
            if(nums[i] != 1002) 
            {
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}
    
public:

    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        string ret="";
        if(!root) return ret;

        v.clear();
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            if(!tmp){
                v.push_back("null");
                v.push_back(",");
                continue;
            }
            v.push_back( to_string(tmp->val) );
            v.push_back(",");

            if(tmp->left) que.push(tmp->left);
            else que.push(nullptr);
            if(tmp->right) que.push(tmp->right);
            else que.push(nullptr);

        }

        v.pop_back();
        int i = v.size()-1;
        while(true){
            if(v[i]!="null") break;
            v.pop_back();
            v.pop_back();
            i = v.size()-1;
        }

        for(int i=0;i<v.size();i++) ret+= v[i];
        return ret;
    }

    // Decodes your encoded data to tree.
    static TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        vector<int> ret;

        int prev =0;
        int i ;
        cout<<v.size()<<endl;
       for(i=0;i<v.size();i++){
           if(v[i] == "null") ret.push_back(1002);
           else ret.push_back(stoi(v[i]));
           i++;
       }

        return buildtree(ret);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
    string str = "1,2,3,null,null,4,5";
    auto node = Codec::deserialize(str);
    str = Codec::serialize(node);
    cout<<str<<endl;
    return 0;
}