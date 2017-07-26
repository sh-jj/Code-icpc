//shjj-hdu6035
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200003;

int go[N*2],t[N*2],last[N],en;
int a[N],size[N],sum[N];
bool use[N];
long long ans;
int n;

void add(int u,int v)
{
	go[++en]=v;t[en]=last[u];last[u]=en;
}

void dfs(int w,int ff)
{
	use[a[w]]=1;
	int dets=0;
	size[w]=1;
	for (int i=last[w];i;i=t[i])
		if (go[i]!=ff)
		{
			int to = go[i];
			int pre = sum[a[w]];
			
			dfs(go[i],w);
			
			
			int det = sum[a[w]] - pre;
			dets += size[to] - det;
			ans += 1ll*(size[to]-det) * (size[to]-det-1);

			size[w] += size[to];
		}
	
	sum[a[w]] += dets + 1;
}

int main()
{
	int Tt=0;
	for (;scanf("%d",&n)==1;)
	{
		for (int i=1;i<=n;i++) last[i] = 0;
		en = 0;
		for (int i=1;i<=n;i++) sum[i] = 0;
		for (int i=1;i<=n;i++) use[i] = 0;
		
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		for (int i=1;i<n;i++)
		{
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		ans=0;
		dfs(1,0);
		
		for (int i=1;i<=n;i++)
			if (use[i]) ans += 1ll*(n-sum[i]) * (n-sum[i]-1);
		int ss=0;
		for (int i=1;i<=n;i++) ss+=use[i];
		ans=1ll*n*(n-1)*ss-ans;
		ans/=2;
		printf("Case #%d: %lld\n",++Tt,ans);
	}
}