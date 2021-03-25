#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// 树结构
struct Node;
typedef Node* pNode;
struct Node{
    int val;
    pNode left,right;
};

unordered_map<int,int> hashMap;

// 后序遍历
void Postorder(pNode root,vector<int>&postorder)
{
    stack<pNode>stk;
    pNode prev = nullptr;
    while(root||!stk.empty())
    {
        while(root)
        {
            stk.push(root);
            root=root->left;
        }
        root = stk.top();
        stk.pop();
        if(root->right == nullptr || root->right == prev)
        {
            postorder.push_back(root->val);
            prev = root;
            root = nullptr;
        }
        else
        {
            stk.push(root);
            root = root->right;
        }
    }
}

// 根据先序遍历和中序遍历构建树
pNode createTree(const vector<int>&preorder,const vector<int>&inorder,int preLeft,int preRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
    {
        return nullptr;
    }
    pNode root = new Node();
    
    root->val = preorder[preLeft];
    
    int inMid = hashMap[preorder[preLeft]];
    
    int length = inMid - inLeft;
    
    root->left = createTree(preorder,inorder,preLeft+1,preLeft+length,inLeft,inMid-1);
    
    root->right = createTree(preorder,inorder,preLeft+length+1,preRight,inMid+1,inRight);
    
    return root;
}

// 读入树
int Read(vector<int>&preorder,vector<int>&inorder)
{
    int n = 0;
    scanf("%d",&n);
    stack<int> stk;
    
    for(int i =0;i<2*n;++i)
    {
        string op;
        cin>>op;
        if(op[1]=='u')
        {
            int num;
            scanf("%d",&num);
            preorder.push_back(num);
            stk.push(num);
        }
        else
        {
            inorder.push_back(stk.top());
            stk.pop();
        }
    }
    
    for(int i =0;i<n;++i)
    {
        hashMap[inorder[i]]=i;
    }
    
    return n;
}

// 打印序列
void Print(vector<int>vec)
{
    int n = vec.size();
    for(int i =0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    
    int n = Read(preorder,inorder);

    pNode root = createTree(preorder,inorder,0,n-1,0,n-1);

    Postorder(root,postorder);
    
    Print(postorder);
    
    return 0;
}
