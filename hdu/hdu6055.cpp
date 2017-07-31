//shjj-hdu6055

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int X[503],Y[503],n,ans;
bool vis[203][203];

bool check(int x,int y)
{
	if (x<0||y<0||x>202||y>202) return 0;
	return vis[x][y];
}

int main()
{
	for (;scanf("%d",&n)==1;)
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&X[i],&Y[i]);
			X[i]+=100;
			Y[i]+=100;
		}
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) vis[X[i]][Y[i]]=1;
		ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j)
				{
					int tx=X[j]-X[i],ty=Y[j]-Y[i];
					
					int _tx=-ty,_ty=tx;
					
					if (check(X[i]+_tx,Y[i]+_ty)&&check(X[j]+_tx,Y[j]+_ty)) ans++;
				}
		printf("%d\n",ans/4);
	}
}