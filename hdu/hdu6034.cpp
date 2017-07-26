//shjj-hdu6033
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int Mod = 1e9+7;

char s[100003];
int sum[100003][26];
int maxhead[26],xh[26],f[26];
int len,maxlen;
bool head[26];
int n,ans;

bool comp(const int &A,const int &B)
{
	if (maxhead[A]>maxhead[B]) return 1;
	if (maxhead[A]<maxhead[B]) return 0;
	for (int i=maxhead[A];i>=0;i--)
	{
		if (sum[i][A]>sum[i][B]) return 1;
		if (sum[i][A]<sum[i][B]) return 0;
	}
	return A<B;
}

int main()
{
	int Tt=0;
	for (;scanf("%d",&n)==1;)
	{
		
		memset(sum,0,sizeof(sum));
		memset(head,0,sizeof(head));
		maxlen=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			for (int j=0;j<len;j++) sum[len-j-1][s[j]-'a']++;
			maxlen=max(len,maxlen);
			head[s[0]-'a']=true;
		}
		for (int i=0;i<maxlen-1;i++)
			for (int j=0;j<26;j++) sum[i+1][j]+=sum[i][j]/26,sum[i][j]%=26;
		
		for (int i=0;i<26;i++)
		{
			maxhead[i]=-1;
			for (int j=maxlen-1;j>=0;j--)
				if (sum[j][i])
				{
					maxhead[i]=j;
					break;
				}
		}
		for (int i=0;i<26;i++) xh[i]=i;
		sort(xh,xh+26,comp);
		for (int i=0;i<26;i++)
			f[xh[i]]=25-i;
		if (head[xh[25]])
		{
			for (int j=24;j>=0;j--)
				if (!head[xh[j]])
				{
					for (int k=24;k>=j;k--) f[xh[k+1]]=f[xh[k]];
					f[xh[j]]=0;
					break;
				}
		}
		ans=0;
		long long Jc=1;
		for (int i=0;i<maxlen;i++)
		{
			for (int j=0;j<26;j++)
				(ans+=Jc*sum[i][j]%Mod*f[j]%Mod)%=Mod;
			(Jc*=26)%=Mod;
		}
		printf("Case #%d: %d\n",++Tt,ans);
	}
	
}