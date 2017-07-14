//shjj-hdu6019

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

set<int> s;
int n,ans;

int main()
{
	int Test;scanf("%d",&Test);
	for (;Test--;)
	{
		ans=0;
		s.clear();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			
			if (s.find(x)!=s.end())
			{
				ans++;
				s.clear();
			} 
			s.insert(x);
		}
		ans++;
		printf("%d\n",ans);
	}
}