#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int left,right;
    char element;
    TreeNode():left(-1),right(-1){}
};

int Read(vector<TreeNode>&tree)
{
    int n = 0;
    scanf("%d",&n);
    vector<int> nums(n,1);
    for(int i =0;i<n;++i)
    {
        TreeNode t;
        char l,r;
        scanf("\n%c %c %c",&(t.element),&l,&r);
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

bool Isomorphic(const vector<TreeNode>tree1,const vector<TreeNode>tree2,int root1,int root2)
{
    if((root1==-1)&&(root2==-1))
    {
        return true;
    }
    if((root1==-1&&root2!=-1)||(root1!=-1&&root2==-1))
    {
        return false;
    }
    if(tree1[root1].element!=tree2[root2].element)
    {
        return false;
    }
    if((tree1[root1].left==-1)&&(tree2[root2].left==-1))
    {
        return Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right);
    }
    if(((tree1[root1].left!=-1)&&(tree2[root2].left!=-1))&&
       ((tree1[tree1[root1].left].element)==(tree2[tree2[root2].left].element)))
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].left)&&
                Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right));
    }
    else
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].right)&&
                Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].left));
    }
}

int main()
{
    int root1,root2;
    vector<TreeNode>tree1;
    vector<TreeNode>tree2;
    
    root1 = Read(tree1);
    root2 = Read(tree2);
    
    if(Isomorphic(tree1,tree2,root1,root2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
