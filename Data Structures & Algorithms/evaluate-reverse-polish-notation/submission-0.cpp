class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<int> s;

        for(int i=0;i<n;i++){
            if(t[i]=="+" || t[i]=="-" || t[i]=="*"|| t[i]=="/"){
                if(t[i]=="+"){
                    int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int ans = left + right;
                s.push(ans);
                }
                else if(t[i]=="-"){
                    int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int ans = left - right;
                s.push(ans);
                }
                else if(t[i]=="*"){
                    int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int ans = left * right;
                s.push(ans);
                }
                else if(t[i]=="/"){
                    int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                int ans = left / right;
                s.push(ans);
                }
            }
            else{
                s.push(stoi(t[i]));
            }
        }
    return s.top();
    }
};
