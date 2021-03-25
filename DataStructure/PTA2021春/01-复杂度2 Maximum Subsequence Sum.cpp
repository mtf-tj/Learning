#include <iostream>
#include <vector>

using namespace std;

int main(int argc,char*argv[])
{
    int n = 0;
    int start=0,end=0,tem = 0;
    int max = -1000000,cur = 0;
    vector<int> vec;
    scanf("%d",&n);
    for(int i =0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        cur+=num;
        if(cur<0)
        {
            cur = 0;
            tem = i+1;
        }
        else if(cur>max)
        {
            max = cur;
            end = i;
            start = tem;
        }
        vec.push_back(num);
    }
    if(max<0)
    {
        printf("0 %d %d",vec[0],vec[n-1]);
    }
    else
    {
        printf("%d %d %d",max,vec[start],vec[end]);
    }
    return 0;
}
