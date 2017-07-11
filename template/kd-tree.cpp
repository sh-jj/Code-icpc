最近点对
//shjj-429d

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N=100000;
struct Dot{int x,y,fa,lx,rx,Lx,Rx,Ly,Ry;}Q[N+3];
int a[N+3],sum[N+3],n,X,Y,Now,root;long long dist1,dist2,ans;
bool comp(const Dot &A,const Dot &B){if (Now&1) return A.y<B.y;return A.x<B.x;}
bool Comp(const Dot &A,const Dot &B){if (A.x==B.x) return A.y<B.y;return A.x<B.x;}
void getsnew(int w)
{
int lw=Q[w].lx,rw=Q[w].rx;
if (lw)
  {
  Q[w].Lx=min(Q[w].Lx,Q[lw].Lx);
  Q[w].Rx=max(Q[w].Rx,Q[lw].Rx);
  Q[w].Ly=min(Q[w].Ly,Q[lw].Ly);
  Q[w].Ry=max(Q[w].Ry,Q[lw].Ry);
  }
if (rw)
  {
  Q[w].Lx=min(Q[w].Lx,Q[rw].Lx);
  Q[w].Rx=max(Q[w].Rx,Q[rw].Rx);
  Q[w].Ly=min(Q[w].Ly,Q[rw].Ly);
  Q[w].Ry=max(Q[w].Ry,Q[rw].Ry);
  }
}

int Build(int l,int r,int ff)
{
if (l>r) return 0;
int mid=(l+r)>>1;
nth_element(Q+l,Q+mid,Q+r+1,comp);
Q[mid].fa=ff;
Now^=1;
Q[mid].lx=Build(l,mid-1,mid);
Q[mid].rx=Build(mid+1,r,mid);
Now^=1;
getsnew(mid);
return mid;
}

void Relax(int w)
{
long long xs=Q[w].x-X;
long long ys=Q[w].y-Y;
xs*=xs;ys*=ys;
long long _s=xs+ys;
if (_s<dist1) dist2=dist1,dist1=_s;
  else if (_s<dist2) dist2=_s;
}

long long check(int w)
{
long long xs=0;
if (X<Q[w].Lx) xs=Q[w].Lx-X;
if (X>Q[w].Rx) xs=Q[w].Rx-X;
long long ys=0;
if (Y<Q[w].Ly) ys=Q[w].Ly-Y;
if (Y>Q[w].Ry) ys=Q[w].Ry-Y;
return xs*xs+ys*ys;
}

void Get(int w)
{
if (check(w)>=ans) return;
Relax(w);
if (Q[w].lx) Get(Q[w].lx);
if (Q[w].rx) Get(Q[w].rx);
}

int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++) scanf("%d",&a[i]);
for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
for (int i=1;i<=n;i++) Q[i].x=Q[i].Lx=Q[i].Rx=i,Q[i].y=Q[i].Ly=Q[i].Ry=sum[i];
sort(Q+1,Q+n+1,Comp);
for (int i=2;i<=n;i++)
  if (Q[i].x==Q[i-1].x&&Q[i].y==Q[i-1].y) {puts("0");return 0;}
root=Build(1,n,0);ans=2e16;
for (int i=1;i<=n;i++)
  {
  X=i;Y=sum[i];dist1=dist2=2e16;
  Get(root);
  ans=min(ans,dist2);
  }
printf("%I64d",ans);
}