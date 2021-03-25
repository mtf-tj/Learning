#include <iostream>

using namespace std;

int main(int argc,char*argv[])
{
    int n = 0;
    int max = 0,cur = 0;
    scanf("%d",&n);
    for(int i =0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        if(cur+num>0)
        {
            cur+=num;
        }
        else
        {
            cur = 0;
        }
        if(cur>max)
        {
            max=cur;
        }
    }
    printf("%d",max);
    return 0;
}
