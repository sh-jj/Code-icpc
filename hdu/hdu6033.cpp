
#include <iostream>
#include <cmath>

using namespace std;

int m;

int main()
{
	int Tt=0;
	for (;scanf("%d",&m)==1;)
	{
		printf("Case #%d: %d\n",++Tt,int(1.*m/log2(10)));
	}
}
