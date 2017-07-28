//shjj-hdu6038

#include <iostream>
#include <cstring>

using namespace std;

const int N=100003;
const int Mod=1e9+7;
int a[N],b[N];
int g[N],sl[N];
int ls,n,m;
long long ans;

int main()
{
	int Tt=0;
	for (;scanf("%d%d",&n,&m)==2;)
	{
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<m;i++) scanf("%d",&b[i]);
		ls=0;
		memset(sl,0,sizeof(sl));
		
		
		for (int i=0;i<n;i++)
		{
			if (a[i]<0) continue;
			int w=a[i],_s=1;
			for (;w!=i;)
			{
				int tmp=a[w];
				a[w]=-1;
				w=tmp;
				_s++;
			}
			a[w]=-1;
			g[++ls]=_s;
		}
		
		for (int i=0;i<m;i++)
		{
			if (b[i]<0) continue;
			int w=b[i],_s=1;
			for (;w!=i;)
			{
				int tmp=b[w];
				b[w]=-1;
				w=tmp;
				_s++;
			}
			b[w]=-1;
			sl[_s]++;
		}
		ans=1;
		for (int i=1;i<=ls;i++)
		{
			long long ss=0;
			for (int j=1;j*j<=g[i];j++)
			{
				if (g[i]%j) continue;
				if (j*j==g[i]) ss+=1ll*sl[j]*j;
					else ss+=1ll*sl[j]*j+1ll*sl[g[i]/j]*g[i]/j;
				ss%=Mod;
			}
			ans*=ss;
			ans%=Mod;
		}
		printf("Case #%d: %lld\n",++Tt,ans);
		
	}
}