#include <iostream>

using namespace std;

// 多项式结构体
struct PolyNode;
typedef PolyNode* pPolyNode;
struct PolyNode{
    int expon;
    int coef;
    pPolyNode next;
    PolyNode():next(nullptr){}
    PolyNode(int c,int e):coef(c),expon(e),next(nullptr){}
};

// 读入多项式
pPolyNode ReadPoly()
{
    int n = 0;
    scanf("%d",&n);
    pPolyNode pHead = new PolyNode();
    pPolyNode head = pHead;
    for(int i =0;i<n;++i)
    {
        pPolyNode p = new PolyNode();
        scanf("%d %d",&(p->coef),&(p->expon));
        head->next = p;
        head=head->next;
    }
    return pHead->next;
}

// 多项式相加
pPolyNode AddPoly(pPolyNode p1,pPolyNode p2)
{
    pPolyNode head = new PolyNode();
    pPolyNode pHead = head;
    while(p1&&p2)
    {
        if(p1->expon==p2->expon)
        {
            int sum = p1->coef+p2->coef;
            if(sum)
            {
                pHead->next = new PolyNode(sum,p1->expon);
                pHead=pHead->next;
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expon>p2->expon)
        {
            pHead->next = new PolyNode(p1->coef,p1->expon);
            p1=p1->next;
            pHead=pHead->next;
        }
        else
        {
            pHead->next = new PolyNode(p2->coef,p2->expon);
            p2=p2->next;
            pHead=pHead->next;
        }
    }
    pHead->next = p1?p1:p2;
    return head;
}

// 多项式相乘
pPolyNode MultiPoly(pPolyNode p1,pPolyNode p2)
{
    pPolyNode pp1 = p1;
    pPolyNode head = new PolyNode();
    while(pp1)
    {
        pPolyNode p = new PolyNode();
        pPolyNode pp = p;
        pPolyNode pp2 = p2;
        while(pp2)
        {
            int sum = pp1->coef*pp2->coef;
            if(sum)
            {
                p->next = new PolyNode(sum,pp1->expon+pp2->expon);
                p = p->next;
            }
            pp2=pp2->next;
        }
        pp1=pp1->next;
        head = AddPoly(head,pp);
    }
    return head;
}

// 打印多项式
void Print(pPolyNode poly)
{
    if(!poly)
    {
        printf("0 0");
    }
    else
    {
        while(poly)
        {
            printf("%d %d",poly->coef,poly->expon);
            poly=poly->next;
            if(poly)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}

// main
int main()
{
    pPolyNode p1 = ReadPoly();
    pPolyNode p2 = ReadPoly();
    
    pPolyNode pMul = MultiPoly(p1,p2);
    
    Print(pMul->next);
    
    pPolyNode pAdd = AddPoly(p1,p2);
    
    Print(pAdd->next);
    
    return 0;
}
