#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int left,right;
    int val;
    TreeNode():left(-1),right(-1){}
};

void LevelTraverse(vector<TreeNode>tree,vector<int>&vec,int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i =0;i<n;++i)
        {
            int s = q.front();
            q.pop();
            if(tree[s].left!=-1)q.push(tree[s].left);
            if(tree[s].right!=-1)q.push(tree[s].right);
            if(tree[s].left==-1&&tree[s].right==-1)
            {
                vec.push_back(tree[s].val);
            }
        }
    }
}

int Read(vector<TreeNode>&tree)
{
    int n = 0;
    scanf("%d",&n);
    vector<int> nums(n,1);
    for(int i =0;i<n;++i)
    {
        TreeNode t;
        char l,r;
        t.val = i;
        scanf("\n%c %c",&l,&r);
        if(l=='-')
        {
            t.left = -1;
        }
        else
        {
            t.left = l-'0';
            nums[l-'0']=0;
        }
        if(r=='-')
        {
            t.right = -1;
        }
        else
        {
            t.right = r-'0';
            nums[r-'0']=0;
        }
        tree.push_back(t);
    }
    int root = -1;
    for(int i = 0;i<n;++i)
    {
        if(nums[i])
        {
            root = i;
            break;
        }
    }
    return root;
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
    vector<TreeNode>tree;
    vector<int>result;
    
    int root = Read(tree);
    
    LevelTraverse(tree,result,root);
    
    Print(result);
    
    return 0;
}
