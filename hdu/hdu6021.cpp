//shjj-hdu6021

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[30];
int a[30],sl[30],len[7],g[7],h[100];
long long sum[100];
int n,ls,m;
long long ans;

const int mod=1000000007;

long long Pow(long long x,long long w)
{
	long long y=1;
	for (;w;w>>=1,(x*=x)%=mod)
		if (w&1) (y*=x)%=mod;
	return y;
}

long long gcd(long long a,long long b)
{
   if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
	int T;scanf("%d",&T);
	for (;T--;)
	{
		scanf("%d",&n);
		scanf("%s",s);
		for (int i=1;i<=26;i++) sl[i]=0;
		for (int i=0;i<26;i++) a[i]=s[i]-'a';
		for (int i=0;i<26;i++)
		{
			int _s=1;
			for (int w=a[i];w!=i;w=a[w]) _s++;
			sl[_s]++;
		}
		
		//for (int i=1;i<=26;i++) sl[i]/=i;
		
		ls=0;
		for (int i=1;i<=26;i++)
			if (sl[i]) len[ls]=i,g[ls++]=sl[i];
		/*
		for (int i=0;i<ls;i++)
			if (len[i]==0) for (;;);
		*/
		m=1<<ls;
		
		ans=0;
		for (int i=1;i<m;i++)
		{
			sum[i]=0;
			h[i]=0;
			long long lcm=1;
			for (int j=0;j<ls;j++)
				if (i>>j&1)
				{
					sum[i]+=g[j],h[i]++;
					lcm=lcm/__gcd(lcm,1ll*len[j])*len[j];
				}
			sum[i]=Pow(sum[i],n);
			for (int j=(i-1)&i;j;j=(j-1)&i)
			{
				//if ((h[i]-h[j])&1) sum[i]-=sum[j];
					//else sum[i]+=sum[j];
				sum[i]-=sum[j];
				((sum[i]%=mod)+=mod)%=mod;
			}
			
			(ans+=lcm*sum[i]%mod)%=mod;
		}
		printf("%lld\n",ans);
	}
	
}