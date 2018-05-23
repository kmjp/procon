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

int T,testcase;
int H,W;
string S[20];

int ok[2][2][2][2];
int v[20][20];

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

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) S[y][x]=S[y][x]=='W';
		
	}
	
	
	if(H<=2 && W<=2) {
		_P("Case #%d: %d\n",TC,H*W);
		return;
	}
	ZERO(ok);
	FOR(y,H) FOR(x,W) {
		ok[S[y][x]][S[y][x]][S[y][x]][S[y][x]]=1;
		if(y) ok[S[y-1][x]][S[y-1][x]][S[y][x]][S[y][x]]=1;
		if(x) ok[S[y][x-1]][S[y][x]][S[y][x-1]][S[y][x]]=1;
		if(y&&x) ok[S[y-1][x-1]][S[y-1][x]][S[y][x-1]][S[y][x]]=1;
	}
	
	int ma=0;
	FOR(y,H+1) FOR(x,W+1) {
		int A[4];
		FOR(A[0],2) FOR(A[1],2) FOR(A[2],2) FOR(A[3],2) if(ok[A[0]][A[1]][A[2]][A[3]]) {
			int yy,xx;
			UF<400> uf;
			FOR(yy,H) FOR(xx,W) {
				v[yy][xx]=A[(yy>=y)*2+(xx>=x)]==S[yy][xx];
			}
			FOR(yy,H) FOR(xx,W) if(v[yy][xx]) {
				if(yy && v[yy-1][xx]) uf(yy*W+xx,(yy-1)*W+xx);
				if(xx && v[yy][xx-1]) uf(yy*W+xx,(yy)*W+xx-1);
			}
			FOR(yy,H) FOR(xx,W) if(v[yy][xx]) ma=max(ma,uf.count(yy*W+xx));
		}
	}
	
	
	_P("Case #%d: %d\n",TC,ma);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
