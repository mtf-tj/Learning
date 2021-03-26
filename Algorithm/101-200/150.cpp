class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i =0;i<tokens.size();++i)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(tokens[i]=="+")
                {
                    num2+=num1;
                }
                else if(tokens[i]=="-")
                {
                    num2-=num1;
                }
                else if(tokens[i]=="*")
                {
                    num2*=num1;
                }
                else
                {
                    num2/=num1;
                }
                stk.push(num2);
            }
            else
            {
                stk.push(stoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};
