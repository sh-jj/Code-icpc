
void read(int &ss){bool zf=false;for (;ch!='-'&&!isdigit(ch);ch=getchar());ss=0;if (ch=='-'){zf=true;ch=getchar();}for (;isdigit(ch);ss=ss*10+ch-'0',ch=getchar());if (zf) ss=-ss;}



void read(int &ss){bool zf=false;for (;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());if (ch=='-'){zf=true;ch=getchar();}ss=0;for (;ch>='0'&&ch<='9';ss=ss*10+ch-'0',ch=getchar());if (zf) ss=-ss;}

void read(int &ss){for (;!isdigit(ch);ch=getchar());ss=0;for (;isdigit(ch);ss=ss*10+ch-'0',ch=getchar());}
void read(int &ss){bool zf=false;for (;ch!='-'&&!isdigit(ch);ch=getchar());ss=0;if (ch=='-'){zf=true;ch=getchar();}for (;isdigit(ch);ss=ss*10+ch-'0',ch=getchar());if (zf) ss=-ss;}
