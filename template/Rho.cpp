const int Pl=10,pri[10]={2,3,5,7,11,13,17,19,23,29};
long long P_i[60],ls;

long long Chenge(long long x,long long y,long long oo)
{
long long ss=0;
for (;y;(x<<=1)%=oo,y>>=1) if (y&1) (ss+=x)%=oo;
return ss;
}
long long pow(long long x,long long w,long long oo)
{
long long ss=1;
for (;w;x=Chenge(x,x,oo),w>>=1) if (w&1) ss=Chenge(ss,x,oo);
return ss;
}
bool Miller_Rabin(long long p)
{
if (p<2) return 0;
if (p==2) return 1;
if (!(p&1)) return 0; 
long long q=p-1,r=0;
for (;!(q&1);q>>=1,r++);
for (int i=0;i<Pl;i++)
  {
  if (!(p%pri[i])) continue;
  long long x=pow(pri[i],q,p);
  if (x==1) continue;bool rp=1;
  for (int j=0;j<=r;j++)
    {
	if (x==p-1) {rp=0;break;}
	x=Chenge(x,x,p);
	}
  if (rp) return 0;
  }
return 1;
}

long long rho(long long C,long long n)
{
long long t1=1,t2=2,x1=rand()%n,x2=0;
for (;;)
  {
  t1++;
  long long _x=__gcd((n+x2-x1)%n,n);
  if (_x>1&&_x<n) return _x;
  if (t1==t2) x2=x1,t2<<=1;
  x1=(Chenge(x1,x1,n)+C)%n;
  if (x1==x2) break;
  }
return 0;
}

void Rho(long long n)
{
if (n==1||Miller_Rabin(n)) {P_i[++ls]=n;return;}
long long x=0;
for (;!x;) x=rho(rand()%n,n);
Rho(x),Rho(n/x);
}
