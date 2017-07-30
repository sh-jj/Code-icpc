//shjj-hdu6053

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100003;
const int Mod=1e9+7;
int mu[N],s[N];
int n,minx,maxx;
long long ans;

long long power(long long x,long long w)
{
	long long y=1;
	for (;w;w>>=1,(x*=x)%=Mod) if (w&1) (y*=x)%=Mod;
	return y;
}

void mobius(long long mn)  
{  
    mu[1]=1;  
    for(long long i=1;i<=mn;i++){  
        for(long long j=i+i;j<=mn;j+=i){  
            mu[j]-=mu[i];  
        }  
    }  
} 

int main()
{
	int T,Tt=0;scanf("%d",&T);
	mobius(100000);
	for (;T--;)
	{
		scanf("%d",&n);
		minx=2e9;
		maxx=0;
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			s[x]++;
			minx=min(minx,x);
			maxx=max(maxx,x);
		}
		for (int i=1;i<=maxx;i++) s[i]+=s[i-1];
		ans=0;
		for (int i=2;i<=minx;i++)
		{
			long long x=1;
			for (int j=1;j*i<=maxx;j++)
			{
				int ss=s[min(maxx,(j+1)*i-1)]-s[j*i-1];
				x*=power(j,ss);
				x%=Mod;
			}
			ans-=x*mu[i];
			ans%=Mod;
			(ans+=Mod)%=Mod;
		}
		printf("Case #%d: %lld\n",++Tt,ans);
		for (int i=1;i<=maxx;i++) s[i]=0;
	}
}