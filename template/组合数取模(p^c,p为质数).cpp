//shjj-C(n,m)%P(P=p^c) pÎªÖÊÊý

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long n,m;
int p,c,P,G[3000000+3];

long long Gcd(long long A,long long B,long long &x,long long &y)
{
if (!B) {x=1;y=0;return A;}
long long ss=Gcd(B,A%B,x,y);long long tmp=x;
x=y;y=tmp-(long long)(A/B)*y;
return ss;
}
bool ExGcd(long long A,long long B,long long C,long long &x,long long &y)
{
long long ss=Gcd(A,B,x,y);if (C%ss) return 0;
x*=C/ss;y*=C/ss;
if (x<=0)
  {
  long long t=abs(x)/(B/ss);
  x+=t*B/ss,y-=t*A/ss;
  if (x<=0) x+=B/ss,y-=A/ss;
  }
long long t=x/(B/ss);
if (t*(B/ss)==x) t--;
x-=t*(B/ss);y+=t*(A/ss);
return 1;
}
long long inverse(long long X,long long p){long long x,y;ExGcd(X,p,1,x,y);return x;}
long long Pow(long long x,long long w,int P)
{
if (!w) return 1;long long ss=1,W=abs(w);
for (;W;)
  {
  if (W&1) ss=(ss*x)%P;
  W>>=1;x=(x*x)%P;
  }
if (w>0) return ss;
return inverse(ss,P);
}
void Factorial(long long n,int &ps,int P,int p,long long &ans,int typ)
{
if (n<=1) return;
Factorial(n/p,ps,P,p,ans,typ);
ps+=n/p*typ;
ans=ans*Pow(G[n%P],typ,P)%P;
ans=ans*Pow(G[P-1],n/P*typ,P)%P;
}

long long combinations(long long n,long long m,int p,int c,int P)
{
int ps=0;long long ans=1;G[0]=1;
for (int i=1;i<P;i++) {G[i]=G[i-1];if (i%p) G[i]=G[i-1]*i%P;}
Factorial(n,ps,P,p,ans,1);
Factorial(m,ps,P,p,ans,-1);
Factorial(n-m,ps,P,p,ans,-1);
ans=ans*Pow(p,ps,P)%P;
return ans;
}

int main()
{
scanf("%I64d%I64d%d%d%d",&n,&m,&p,&c,&P);
printf("%I64d",combinations(n,m,p,c,P));
}