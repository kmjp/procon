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
string S[1515];
int A[1515][1515];
vector<int> V[1515];
int L[1515][1515];

int Q;
int Y[202020],X[202020],M[202020];
vector<int> qs[1515];
int ret[151500];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<4030303> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			A[y+1][x+1]=A[y][x+1]+A[y+1][x]-A[y][x]+(S[y][x]=='.');
		}
	}
	FOR(y,H) FOR(x,W) {
		r=0;
		for(i=11;i>=0;i--) if(y+r+(1<<i)<=H && x+r+(1<<i)<=W) {
			k=A[y+r+(1<<i)][x+r+(1<<i)]-A[y][x+r+(1<<i)]-A[y+r+(1<<i)][x]+A[y][x];
			if(k==(r+(1<<i))*(r+(1<<i))) r+=1<<i;
		}
		L[y][x]=r;
		V[r].push_back(y*10000+x);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>Y[i]>>X[i]>>M[i];
		Y[i]--;
		X[i]--;
		qs[M[i]].push_back(i);
	}
	
	for(i=1500;i>=1;i--) {
		FORR(r,V[i]) {
			y=r/10000;
			x=r%10000;
			
			if(y && L[y-1][x]>=i) uf(y*2000+x,(y-1)*2000+x);
			if(y+1<H && L[y+1][x]>=i) uf(y*2000+x,(y+1)*2000+x);
			if(x && L[y][x-1]>=i) uf(y*2000+x,y*2000+x-1);
			if(x+1<W && L[y][x+1]>=i) uf(y*2000+x,y*2000+x+1);
		}
		FORR(q,qs[i]) ret[q]=uf.count(Y[q]*2000+X[q]);
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
