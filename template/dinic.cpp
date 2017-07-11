#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int go[3000000+3],t[3000000+3],last[30000+3],c[3000000+3];
int q[30000+3],d[30000+3],pre[30000+3];
int en,S,T,bh,sumL;

void add(int u,int v,int cc)
{
go[++en]=v;t[en]=last[u];last[u]=en;c[en]=cc;
go[++en]=u;t[en]=last[v];last[v]=en;c[en]=0;
}

bool find()
{
  memset(d,0,sizeof(d));
  d[S]=1;
  q[1]=S;
  for (int l=0,r=1;l<r;)
    for (int i=last[q[++l]];i;i=t[i])
      if (c[i]&&!d[go[i]])
      {
        d[go[i]]=d[q[l]]+1;
        if (go[i]==T) return true;
        q[++r]=go[i];
      }
return false;
}

void dinic(int w)
{
  if (w==T)
  {
    int minL=2e9;
    for (int i=T;i!=S;i=go[pre[i]^1]) minL=min(minL,c[pre[i]]);
    for (int i=T;i!=S;i=go[pre[i]^1])
    {
      c[pre[i]]-=minL;
      c[pre[i]^1]+=minL;
      if (!c[pre[i]]) bh=go[pre[i]^1];
    }
    sumL+=minL;return;
  }
  for (int i=last[w];i;i=t[i])
    if (c[i])
    {
    if (d[w]+1!=d[go[i]]) continue;
    pre[go[i]]=i;
    dinic(go[i]);
    if (d[bh]<d[w]) return;bh=T;
    }
  d[w]=-1;
}

int main()
{
en=1;
//S=3;T=33;add(S,1,1);add(1,T,1);
for (;find();bh=T,dinic(S));
printf("%d",sumL);
}