//shjj-hdu6040

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

unsigned a[10000003],ans[103];
int b[103],xh[103];
int n,m,A,B,C;
unsigned x, y, z;

unsigned rng61() {
  
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

bool comp(const int &A,const int &B)
{
	return b[A]>b[B];
}

int main()
{
	int Tt=0;
	for (;scanf("%d%d%d%d%d",&n,&m,&A,&B,&C)==5;)
	{
		x = A, y = B, z = C;
		for (int i=0;i<n;i++) a[i]=rng61();
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		
		for (int i=1;i<=m;i++) xh[i]=i;
		sort(xh+1,xh+m+1,comp);
		int r=n;
		for (int i=1;i<=m;i++)
		{
			if (b[xh[i]]==r&&i>1)
			{
				ans[xh[i]]=ans[xh[i-1]];
				continue;
			}
			nth_element(a,a+b[xh[i]],a+r);
			r=b[xh[i]];
			ans[xh[i]]=a[r];
		}
		printf("Case #%d:",++Tt);
		for (int i=1;i<=m;i++) printf(" %u",ans[i]);
		puts("");
	}
}