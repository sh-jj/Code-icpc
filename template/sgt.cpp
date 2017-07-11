//shjj-scapegoattree

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=600000;
struct sgt{int lx,rx,s,S,hs;}Q[N+3];
int g[N+3],n,m,nn,ls,root,MaxDep;
char ss[10],ch;
const int AlphaA=62;
const int AlphaB=100;
const double LogAlpha=log((double)AlphaB)-log((double)AlphaA);
void read(int &ss){for (;!isdigit(ch);ch=getchar());ss=0;for (;isdigit(ch);ss=ss*10+ch-'0',ch=getchar());}
bool comp(const sgt &A,const sgt &B){return A.hs<B.hs;}
void clean(int w){Q[w].lx=Q[w].rx=Q[w].s=Q[w].hs=0;}
int search(int x)
{
int w=root;
for (;;)
  {
  if (Q[Q[w].lx].s+1==x) return w;
  if (x<=Q[Q[w].lx].s) w=Q[w].lx;
    else x-=Q[Q[w].lx].s+1,w=Q[w].rx;
  }
}
int small(int x)
{
int w=root,s=0;
for (;w;)
  {
  if (Q[w].hs<x) s+=Q[Q[w].lx].s+1,w=Q[w].rx;
    else w=Q[w].lx;
  }
return s;
}
void Build(int &w,int l,int r)
{
if (l>r) {w=0;return;}
int mid=(l+r)>>1;w=g[mid];
Q[w].S=Q[w].s=r-l+1;
Build(Q[w].lx,l,mid-1);
Build(Q[w].rx,mid+1,r);
}
void Binary(int w)
{
if (!w) return;
Binary(Q[w].lx);
g[++ls]=w;
Binary(Q[w].rx);
}
void ReBuild(int &w)
{
if (!w) return;
ls=0;Binary(w);
Build(w,1,ls);
}
bool insert(int &w,int x,int dep)
{
if (!w)
  {
  w=++nn;
  Q[w].hs=x;Q[w].s=Q[w].S=1;
  return dep>MaxDep;
  }
Q[w].s++;Q[w].S++;
bool NeedReBuild;
if (x<=Q[w].hs) NeedReBuild=insert(Q[w].lx,x,dep+1);
  else NeedReBuild=insert(Q[w].rx,x,dep+1);
int cut=Q[w].S*AlphaA/AlphaB;
if (NeedReBuild&&(Q[Q[w].lx].S>cut||Q[Q[w].rx].S>cut))
  {
  ReBuild(w);
  NeedReBuild=0;
  }
return NeedReBuild;
}
int DelMostRight(int &w)
{
if (!Q[w].rx)
  {
  int xx=Q[w].hs;
  w=Q[w].lx;
  return xx;
  }
Q[w].s--;
return DelMostRight(Q[w].rx);
}
bool del(int &w,int x)
{
if (!w) return 0;
if (Q[w].hs==x)
  {
  if (!Q[w].lx) {w=Q[w].rx;return 1;}
  if (!Q[w].rx) {w=Q[w].lx;return 1;}
  int xx=DelMostRight(Q[w].lx);
  Q[w].hs=xx;Q[w].s--;
  return 1;
  }
bool find;
if (x<Q[w].hs) find=del(Q[w].lx,x);
  else find=del(Q[w].rx,x);
if (find) Q[w].s--;
int cut=Q[w].S*AlphaA/AlphaB;
if (Q[Q[w].lx].S>cut||Q[Q[w].rx].S>cut) ReBuild(w);
return find;
}
void Insert(int x){MaxDep=log(Q[root].s+1)/LogAlpha;insert(root,x,1);}
void Delete(int x){if (!del(root,x)) puts("-1");}
void FindKth(int x)
{
if (x>Q[root].s){puts("-1");return;}
int w=search(x);
printf("%d\n",Q[w].hs);
}
void GetRank(int x){printf("%d\n",small(x)+1);}
void Pred(int x)
{
int y=small(x);
if (!y) puts("-1");
  else printf("%d\n",Q[search(y)].hs);
}
void Next(int x)
{
x++;int y=small(x);
if (y==Q[root].s) puts("-1");
  else printf("%d\n",Q[search(y+1)].hs);
}
int main()
{
read(n),read(m);
for (int i=1;i<=n;i++) read(Q[++nn].hs);
sort(Q+1,Q+nn+1,comp);
for (int i=1;i<=n;i++) g[i]=i;
Build(root,1,nn);
for (int i=1;i<=m;i++)
  {
  scanf("%s",ss);
  if (ss[0]=='I'){int x;read(x);Insert(x);}
  if (ss[0]=='D'){int x;read(x);Delete(x);}
  if (ss[0]=='F'){int x;read(x);FindKth(x);}
  if (ss[0]=='G'){int x;read(x);GetRank(x);}
  if (ss[0]=='P'){int x;read(x);Pred(x);}
  if (ss[0]=='N'){int x;read(x);Next(x);}
  }
}