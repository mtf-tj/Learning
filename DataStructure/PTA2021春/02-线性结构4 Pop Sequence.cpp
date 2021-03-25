#include <iostream>
#include <stack>

using namespace std;

void check(int m,int n)
{
    stack<int> stk;
    bool res = true;
    int count = 1;
    while(n--)
    {
        int num = 0;
        scanf("%d",&num);
        if(res)
        {
            while(stk.empty()||stk.top()!=num)
            {
                stk.push(count++);
                if(stk.size()>m)
                {
                    res = false;
                    break;
                }
            }
        }
        if(res&&stk.size()>=1&&stk.top()==num)
        {
            stk.pop();
        }
    }
    printf("%s\n",res?"YES":"NO");
}

int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    for(int i =0;i<k;++i)
    {
        check(m,n);
    }
    return 0;
}
