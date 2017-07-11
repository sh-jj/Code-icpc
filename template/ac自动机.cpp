
void insert()
{
int w=0,w3=1;
for (;w3<=len;)
  {
  if (g[w]) return;
  if (Tire[w][s[w3]-'A']) w=Tire[w][s[w3]-'A'];
    else {Tire[w][s[w3]-'A']=++Tn;w=Tn;}
  w3++;
  }
g[w]=true;
}
 
void Mak()
{
q[1]=0;
for (int l=0,r=1;l<r;)
  {
  int x=q[++l];g[x]|=g[fail[x]];
  if (g[x]) continue;
  for (int i=0;i<26;i++)
    if (Tire[x][i])
      {q[++r]=Tire[x][i];if (x) fail[Tire[x][i]]=Tire[fail[x]][i];}
      else Tire[x][i]=Tire[fail[x]][i];
  }
}
