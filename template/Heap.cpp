
//小根堆
void relax(int w)
{
int w3;
for (;w>>1;)
  {
  w3=w>>1;
  if (W[Heap[w3]]<=W[Heap[w]]) break;
  swap(Heap[w],Heap[w3]);w=w3;
  }
for (;w<<1<=hn;)
  {
  w3=w<<1;
  if (w3<hn&&W[Heap[w3+1]]<W[Heap[w3]]) w3++;
  if (W[Heap[w]]<=W[Heap[w3]]) break;
  swap(Heap[w],Heap[w3]);w=w3;
  }
}



//大根堆
void relax(int w)
{
int w3;
for (;w>>1;)
  {
  w3=w>>1;
  if (W[Heap[w3]]>=W[Heap[w]]) break;
  swap(Heap[w],Heap[w3]);w=w3;
  }
for (;w<<1<=hn;)
  {
  w3=w<<1;
  if (w3<hn&&W[Heap[w3+1]]>W[Heap[w3]]) w3++;
  if (W[Heap[w]]>=W[Heap[w3]]) break;
  swap(Heap[w],Heap[w3]);w=w3;
  }
}