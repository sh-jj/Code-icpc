
void lc(int x)
{
int y=q[x].fa,z=q[y].fa;
q[y].rx=q[x].lx;q[q[y].rx].fa=y;
q[x].lx=y;q[y].fa=x;q[x].fa=z;if (q[z].lx==y) q[z].lx=x;else q[z].rx=x;
getsnew(y);getsnew(x);
}
 
void rc(int x)
{
int y=q[x].fa,z=q[y].fa;
q[y].lx=q[x].rx;q[q[y].lx].fa=y;
q[x].rx=y;q[y].fa=x;q[x].fa=z;if (q[z].lx==y) q[z].lx=x;else q[z].rx=x;
getsnew(y);getsnew(x);
}

void splay(int x)
{
//int ll=0,w=x;for (;!Q[w].root;w=Q[w].fa) REL[++ll]=w;REL[++ll]=w;
//for (int i=ll;i>=1;i--) relax(REL[i]);
int y,z;
for (;q[x].fa;)
  {
  y=q[x].fa,z=q[y].fa;
  if (!z) {if (q[y].lx==x) rc(x);else lc(x);break;}
  if (q[z].lx==y)
    {if (q[y].lx==x) rc(y),rc(x);else lc(x),rc(x);}
    else {if (q[y].lx==x) rc(x),lc(x);else lc(y),lc(x);}
  }
root=x;
}
void insert(int x)
{
if (!root) {root=x;q[x].s=1;return;}
int w=root;
for (;3<33;)
  {
  if (q[x].hs>q[w].hs)
    {if (!q[w].lx) {q[w].lx=x;break;}else w=q[w].lx;}
	else if (!q[w].rx) {q[w].rx=x;break;}else w=q[w].rx;
  }
q[x].fa=w;q[x].s=1;splay(x);
}
void search(int ss)
{
int w=root;
for (;3<33;)
  {
  if (ss==q[q[w].lx].s+1) break;
  if (ss<=q[q[w].lx].s) w=q[w].lx;else {ss-=q[q[w].lx].s+1;w=q[w].rx;}
  }
splay(w);
}
int seall(int w){for (;q[w].lx;w=q[w].lx);return w;}
int searr(int w){for (;q[w].rx;w=q[w].rx);return w;}