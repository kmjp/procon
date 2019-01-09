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
UF<2020*2020> uf;

int H,W;
int N;
int X1[1001],Y1[1001],X2[1001],Y2[1001];
vector<int> Xs,Ys;

int dp[2040][2040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	Xs.push_back(0);
	Xs.push_back(W);
	Ys.push_back(0);
	Ys.push_back(H);
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		Xs.push_back(X1[i]);
		Xs.push_back(X2[i]);
		Ys.push_back(Y1[i]);
		Ys.push_back(Y2[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	FOR(i,N) {
		X1[i]=lower_bound(ALL(Xs),X1[i])-Xs.begin();
		X2[i]=lower_bound(ALL(Xs),X2[i])-Xs.begin();
		Y1[i]=lower_bound(ALL(Ys),Y1[i])-Ys.begin();
		Y2[i]=lower_bound(ALL(Ys),Y2[i])-Ys.begin();
		dp[X1[i]][Y1[i]]++;
		dp[X2[i]][Y1[i]]--;
		dp[X1[i]][Y2[i]]--;
		dp[X2[i]][Y2[i]]++;
	}
	
	FOR(x,Xs.size()-1) FOR(y,Ys.size()-1) {
		if(x) dp[x][y]+=dp[x-1][y];
		if(y) dp[x][y]+=dp[x][y-1];
		if(x && y) dp[x][y]-=dp[x-1][y-1];
	}
	
	FOR(x,Xs.size()-1) FOR(y,Ys.size()-1) {
		if(x && dp[x][y]==0 && dp[x-1][y]==0) uf(y*2010+x,y*2010+x-1);
		if(y && dp[x][y]==0 && dp[x][y-1]==0) uf(y*2010+x,(y-1)*2010+x);
	}
	int ret=0;
	FOR(x,Xs.size()-1) FOR(y,Ys.size()-1) if(dp[x][y]==0 && uf[y*2010+x]==y*2010+x) ret++;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
