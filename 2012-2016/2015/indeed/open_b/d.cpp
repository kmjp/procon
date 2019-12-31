#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class UF {
	public:
	int um;
	vector<int> ufpar,ufrank,ufcnt;
	UF(int um_=100002) { um=um_; ufrank=vector<int>(um,0); ufcnt=vector<int>(um,1); for(int i=0;i<um;i++) ufpar.push_back(i);}
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int H,W;
int sy,sx,gy,gx;
ll tot;
ll P[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>sx>>sy>>gx>>gy;
	sx--; sy--;
	FOR(y,H) {
		FOR(x,W) cin>>P[y][x], tot+=P[y][x];
	}
	
	priority_queue<pair<ll,int> > Q;
	FOR(y,H) {
		FOR(x,W) {
			if(y<H-1) Q.push(make_pair(P[y][x]*P[y+1][x],(y+1)*1000000+x*10000+y*100+x));
			if(x<W-1) Q.push(make_pair(P[y][x]*P[y][x+1],y*1000000+(x+1)*10000+y*100+x));
		}
	}
	
	UF uf;
	while(Q.size()) {
		auto e=Q.top();
		Q.pop();
		x=e.second/10000,y=e.second%10000;
		if(uf[x]==uf[y]) continue;
		uf.unite(x,y);
		tot+=e.first;
	}
	
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
