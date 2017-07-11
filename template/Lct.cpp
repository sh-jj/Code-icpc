
const int N=10000;
class splay{public:int lx,rx,fa,s;bool root,g;} Q[N+3];

void getsnew(int w){Q[w].s=Q[Q[w].lx].s+Q[Q[w].rx].s+1;}
void change(int w){swap(Q[w].lx,Q[w].rx);if (Q[w].s>1) Q[w].g^=1;}
void relax(int w){if (Q[w].g) {if (Q[w].lx) change(Q[w].lx);if (Q[w].rx) change(Q[w].rx);Q[w].g=0;}}
void lc(int x)
{
int y=Q[x].fa,z=Q[y].fa;
Q[y].rx=Q[x].lx;Q[Q[y].rx].fa=y;
Q[x].lx=y;Q[y].fa=x;Q[x].fa=z;
swap(Q[x].root,Q[y].root);
getsnew(y);getsnew(x);
if (Q[x].root) return;
if (Q[z].lx==y) Q[z].lx=x;else Q[z].rx=x;
}
void rc(int x)
{
int y=Q[x].fa,z=Q[y].fa;
Q[y].lx=Q[x].rx;Q[Q[y].lx].fa=y;
Q[x].rx=y;Q[y].fa=x;Q[x].fa=z;
swap(Q[x].root,Q[y].root);
getsnew(y);getsnew(x);
if (Q[x].root) return;
if (Q[z].lx==y) Q[z].lx=x;else Q[z].rx=x;
}
void splay(int x)
{
int ll=0,w=x;for (;!Q[w].root;w=Q[w].fa) REL[++ll]=w;REL[++ll]=w;
for (int i=ll;i>=1;i--) relax(REL[i]);
int y,z;
for (;!Q[x].root;)
  {
  y=Q[x].fa;z=Q[y].fa*(!Q[y].root);
  if (!z) {if (Q[y].lx==x) rc(x);else lc(x);break;}
  if (Q[z].lx==y){if (Q[y].lx==x) rc(y),rc(x);else lc(x),rc(x);}
    else if (Q[y].rx==x) lc(y),lc(x);else rc(x),lc(x);
  }
}
void access(int x)
{
splay(x);relax(x);if (Q[x].rx) {Q[Q[x].rx].root=1;Q[x].rx=0;getsnew(x);}
for (;Q[x].fa;)
  {
  int y=Q[x].fa;splay(y);if (Q[y].rx) Q[Q[y].rx].root=1;
  Q[x].root=0;Q[y].rx=x;getsnew(y);x=y;
  }
}
void changeroot(int x){access(x);splay(x);change(x);}
void Insert(int x,int y){changeroot(x);Q[x].fa=y;}
void Del(int x,int y){changeroot(x);access(y);splay(y);Q[y].lx=0;Q[x].fa=0;Q[x].root=1;getsnew(y);}
int findf(int w){for (;Q[w].fa;w=Q[w].fa);return w;}

