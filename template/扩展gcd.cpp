#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

//求a*x+b*y=c

using namespace std;

int A,B,C,x,y;

int Gcd(int A,int B)
{
if (!B) {x=1;y=0;return A;}
int ss=Gcd(B,A%B);int tmp=x;
x=y;y=tmp-(int)(A/B)*y;
return ss;
}

bool work(int A,int B,int C)
{
int ss=Gcd(A,B);if (C%ss) return false;
x*=C/ss;y*=C/ss;
//求非负数解
if (x<=0)
  {
  int t=abs(x)/(B/ss);
  x+=t*B/ss,y-=t*A/ss;
  if (x<=0) x+=B/ss,y-=A/ss;//正整数
  //if (x<0) x+=B/ss,y-=A/ss;//非负数
  if (x<=0||y<=0) return false;//正整数
  //if (x<0||y<0) return false;//非负数
  }
if (y<=0)
  {
  int t=abs(y)/(A/ss);
  x-=t*B/ss,y+=t*A/ss;
  if (y<=0) x-=B/ss,y+=A/ss;//正整数
  //if (y<0) x-=B/ss,y+=A/ss;//非负数
  if (x<=0||y<=0) return false;//正整数
  //if (x<0||y<0) return false;//非负数
  }
return true;
}

int main()
{
scanf("%d%d%d",&A,&B,&C);
if (!work(A,B,C)) {printf("呵呵");return 0;}
printf("%d %d",x,y);
}