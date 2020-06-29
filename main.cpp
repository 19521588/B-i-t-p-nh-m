#include<bits/stdc++.h>
using namespace std;
struct NODE
{
    int data;
   struct NODE *pNext;
};
typedef struct NODE NODE;
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct LIST LIST;
void KhoiTao(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
bool IsEmpty(LIST l)
{
    if(l.pHead==NULL)
        return true;
    return false;
}
NODE *GetNode(int x)
{
    NODE *p=new NODE;
    if(p==NULL)
        return NULL;
    p->data=x;
    p->pNext=NULL;
    return p;
}
void AddHead(LIST &l,NODE *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
void AddTail(LIST &l,NODE *p)
{
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void output(LIST l)
{
    for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
    {
        cout<<p->data<<"\t";
    }
    cout<<"\n";
}
#define M 1001
LIST L[M];

 vector <int> a;

void InitL()
{
    for(int i=0;i<M;i++)
    {
        KhoiTao(L[i]);
    }
}
void InsertL(int i,int x)
{
    NODE*p;
    p=GetNode(x);
    if(p!=NULL)
        AddTail(L[i],p);
}

bool check(LIST l,int x)
{
    for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
        if(p->data==x)
            return false;
    return true;
}
void Push(LIST l,queue <int> &k)
{
     for(NODE*p=l.pHead;p!=NULL;p=p->pNext)
        if(a[p->data]==0)
     {
        a[p->data]=1;
         k.push(p->data);
     }

}
int main()
{
    InitL();
    int n,m,u,v;
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
            if(check(L[u],v))
            InsertL(u,v);
            if(check(L[v],u))
            InsertL(v,u);


    }
    for(int i=0;i<n;i++)
        a[i]=0;
    int d=0;
        queue <int> k;
        for(int i=0;i<n;i++)
            if(a[i]==0)
        {
            a[i]=1;
            Push(L[i],k);

            while(!k.empty())
            {
                int h=k.front();
                k.pop();
                Push(L[h],k);
            }
        d++;
        }
    cout<<d;
}
