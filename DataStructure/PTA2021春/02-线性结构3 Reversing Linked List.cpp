#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
struct Node;
typedef Node* pNode;
struct Node{
    int address;
    int val;
    int next;
    Node *nex;
    Node():nex(nullptr){}
    Node(int _address,int _val,int _next):address(_address),val(_val),next(_next),nex(nullptr){}
};

// 处理
pair<pNode,pNode> reverseK(pNode head,pNode tail)
{
    pNode prev = tail->nex,cur = head;
    while(prev!=tail)
    {
        pNode temp = cur->nex;
        cur->nex = prev;
        if(prev)
        {
            cur->next = prev->address;
        }
        else
        {
            cur->next = -1;
        }
        prev = cur;
        cur = temp;
    }
    return {tail,head};
}

pNode solve(int k,pNode head)
{
    pNode pHead = new Node();
    pNode pp = pHead;
    int count = 1;
    while(head)
    {
        pNode p = head;
        while(p&&count<k)
        {
            p=p->nex;
            ++count;
        }
        if(!p||count!=k)
        {
            break;
        }
        pair<pNode,pNode>result = reverseK(head,p);
        pp->next = result.first->address;
        pp->nex = result.first;
        pp=result.second;
        head = pp->nex;
        count = 1;
    }
    return pHead;
}

// 读入
pNode Read(int n,int start)
{
    pNode head = new Node();
    pNode pHead = head;
    unordered_map<int,pNode> um;
    for(int i =0;i<n;++i)
    {
        int _address,_val,_next;
        scanf("%d %d %d",&_address,&_val,&_next);
        pNode p = new Node(_address,_val,_next);
        um[_address]=p;
    }
    while(pHead->next!=-1)
    {
        pHead->nex = um[start];
        pHead=pHead->nex;
        start = um[start]->next;
    }
    pHead->nex = nullptr;
    return head->nex;
}

// 打印
void Print(pNode p)
{
    while(p)
    {
        printf("%05d %d",p->address,p->val);
        if(p->next!=-1)
        {
            printf(" %05d",p->next);
        }
        else
        {
            printf(" -1");
        }
        p = p->nex;
        printf("\n");
    }

}

int main()
{
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    
    pNode p = Read(n,start);
    
    p = solve(k,p);
    
    Print(p->nex);
    
    return 0;
}
