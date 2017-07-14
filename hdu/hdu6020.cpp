//shjj-hdu6020

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

//a+b+c=n-k
//b+c*2%3=0

char s[100003];
int n,K;
int Count0;
int count[3];
bool P00,P0,P1,P2;

bool check()
{
	
	for (int i=0;i<=count[2];i++)
	{
		int x=3-i*2%3;
		x%=3;
		int c=i,b=x,a=n-K-b-c;
		if (a>count[0])
		{
			int det=a-count[0];
			if (det%3) det+=3-det%3;
			a-=det;
			b+=det;
		}
		for (;a>=0&&b<=count[1];b+=3,a-=3)
		{
			if (count[0]-a>=Count0) return 1;
			if (b&&P1) return 1;
			if (c&&P2) return 1;
		}
	}
	return false;
}

int main()
{
	int Test;scanf("%d",&Test);
	for (;Test--;)
	{
		scanf("%d%d",&n,&K);
		scanf("%s",s+1);
		memset(count,0,sizeof(count));
		Count0=0;
		P0=1;
		P00=0;
		P1=0,P2=0;
		for (int i=1;i<=n;i++)
		{
			count[(s[i]-'0')%3]++;
			if ((s[i]-'0')%3==0)
			{
				if (s[i]-'0'==0&&P0) Count0++;
					else P0=0;
				if (s[i]-'0'==0) P00=1;
			}
			int x=(s[i]-'0')%3;
			if (x&&(!P00))
			{
				if (x==1) P1=1;
				if (x==2) P2=1;
			}
		}
		if (check()||(n==K+1&&count[0])) puts("yes");
			else puts("no");
		
	}
}