#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=20003;
int a[N+3],Rank[N*2+3],tRank[N*2+3],sa[N+3],tsa[N+3],Tmp[N+3],lcp[N];
char S1[N],S2[N];
int n,m,nn,len;
int A_B[N],B_A[N];
int F[16][N];
long long ans;
int sl[30];

void Sa(int len)
{
    for (int ll=1;ll<len;ll<<=1)
    {
        memset(Tmp,0,sizeof(Tmp));
        for (int i=1;i<=len;i++) Tmp[Rank[i+ll]]++;
        for (int i=1;i<=len;i++) Tmp[i]+=Tmp[i-1];
        for (int i=len;i>=1;i--) tsa[Tmp[Rank[i+ll]]--]=i;
        memset(Tmp,0,sizeof(Tmp));
        for (int i=1;i<=len;i++) Tmp[Rank[i]]++;
        for (int i=1;i<=len;i++) Tmp[i]+=Tmp[i-1];
        for (int i=len;i>=1;i--) sa[Tmp[Rank[tsa[i]]]--]=tsa[i];
        int tmp=1;tRank[sa[1]]=1;
        for (int i=2;i<=len;i++)
        {
            tmp+=(Rank[sa[i]]!=Rank[sa[i-1]]||Rank[sa[i]+ll]!=Rank[sa[i-1]+ll]);
            tRank[sa[i]]=tmp;
        }
        memcpy(Rank,tRank,sizeof(Rank));
        if (Rank[sa[len]]==len) return;
    }
}


void GetLcp()
{
    int h=0;
    for (int i=1;i<=len;i++)
        if (Rank[i]>1)
        {
            int w=sa[Rank[i]-1];
            h=max(0,h-1);
            for (;w+h<=len&&i+h<=len&&S1[w+h]==S1[i+h];h++);
            lcp[Rank[i]]=h;
        }
        else h=lcp[Rank[i]]=0;
}

void St()
{
    int LL=log2(len);
    for (int i=1;i<=len;i++) F[0][i]=lcp[i];
    for (int i=1;i<=LL;i++)
        for (int j=1;j+(1<<i)-1<=len;j++)
            F[i][j]=min(F[i-1][j],F[i-1][j+(1<<(i-1))]);
}

int Get(int x,int y)
{
    x=Rank[x],y=Rank[y];
    if (x>y) swap(x,y);
    x++;
    int dd=log2(y-x+1);
    return min(F[dd][x],F[dd][y-(1<<dd)+1]);
}

int main()
{
  for(;scanf("%s%s",S1+1,S2+1)==2;)
  {
    
    memset(a,0,sizeof(a));
    memset(Rank,0,sizeof(Rank));
    memset(tRank,0,sizeof(tRank));
    memset(sa,0,sizeof(sa));
    memset(tsa,0,sizeof(tsa));
    memset(Tmp,0,sizeof(Tmp));
    memset(lcp,0,sizeof(lcp));
    memset(sl,0,sizeof(sl));
    
    n=strlen(S1+1);
    m=strlen(S2+1);
    
    len=n;
    S1[++len]='#';
    for (int i=1;i<=m;i++) S1[++len]=S2[i];
    S1[++len]='$';
    
    
    nn=300;
    memset(Tmp,0,sizeof(Tmp));
    for (int i=1;i<=len;i++) Tmp[S1[i]]=1;
    for (int i=1;i<=nn;i++) Tmp[i]+=Tmp[i-1];
    for (int i=len;i>=1;i--) a[i]=Tmp[S1[i]];
    int Maxx=0;
    for (int i=1;i<=len;i++) 
        Maxx=max(Maxx,a[i]);
    
    memset(Rank,0,sizeof(Rank));
    for (int i=1;i<=len;i++) Rank[i]=a[i];
    
    
    
    Sa(len);
    GetLcp();
    St();
    
    for (int i=1;i<=n;i++)
        A_B[i]=Get(i,n+2);
    
    for (int i=1;i<=m;i++)
        B_A[i]=Get(n+1+i,1);
    for (int i=1;i<=n;i++)
    {
        sl[S1[i]-'a']++;
        sl[S2[i]-'a']--;
        bool pp=1;
        for (int j=0;j<26;j++)
        {
            if (sl[j])
            {
                pp=0;
                break;
            }
        }
        if (!pp) 
        {
            putchar('0');
            continue;
        }
        bool P=0;
        for (int j=1;j<=i;j++)
        {
            int ll=i-j+1;
            if (A_B[j]>=ll&&B_A[ll+1]>=j-1)
            {
                P=1;
                break;
            }
        }
        if (P) putchar('1');
            else putchar('0');
    }
    puts("");
  }
}