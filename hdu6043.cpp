//shjj-hdu6043
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long K;

int Calc(int n,long long k)
{
	if (k<=n) return k;
	k-=n;
	if (k%(n-1)) return k%(n-1);
	k/=n-1;
	if (k&1) return n-1;
	return n;
}

int main()
{
	int Tt=0;
	for (;scanf("%d%lld",&n,&K)==2;)
	{
		printf("Case #%d: %d\n",++Tt,Calc(n,K));
	}
}