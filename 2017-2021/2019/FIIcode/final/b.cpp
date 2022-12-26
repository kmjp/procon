#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[1010];
int D[1010][1010];
int SX,SY,FX,FY;

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1010000> uf;
vector<int> cand[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	queue<int> Q;
	FOR(y,H) FOR(x,W) D[y][x]=101010;
	
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='P') {
				D[y][x]=0;
				Q.push(y*1000+x);
			}
			if(S[y][x]=='S') SX=x,SY=y;
			if(S[y][x]=='F') FX=x,FY=y;
			
		}
	}
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0 || tx<0 || ty>=H || tx>=W) continue;
			if(D[ty][tx]>D[cy][cx]+1) {
				D[ty][tx]=D[cy][cx]+1;
				Q.push(ty*1000+tx);
			}
		}
	}
	FOR(y,H) FOR(x,W) cand[D[y][x]].push_back(y*1000+x);
	
	for(i=2010;i>=1;i--) {
		FORR(c,cand[i]) {
			y=c/1000;
			x=c%1000;
			if(y&&D[y-1][x]>=i) uf(y*1000+x,(y-1)*1000+x);
			if(y+1<H&&D[y+1][x]>=i) uf(y*1000+x,(y+1)*1000+x);
			if(x&&D[y][x-1]>=i) uf(y*1000+x,y*1000+x-1);
			if(x+1<W&&D[y][x+1]>=i) uf(y*1000+x,y*1000+x+1);
		}
		if(uf[SY*1000+SX]==uf[FY*1000+FX]) return _P("%d\n",i);
	}
	cout<<"impossible"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
