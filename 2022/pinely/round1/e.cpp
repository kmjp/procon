#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
string S[4040];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<4020> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	cin>>N;
	uf.reinit(N);
	
	FOR(i,N) {
		cin>>S[i];
	}
	cin>>k;
	FOR(i,k) {
		cin>>y;
		FOR(x,N) S[x][y]^=1;
		FOR(x,N) S[y][x]^=1;
	}
	FOR(y,N) cout<<S[y]<<endl;
	
	FOR(y,N) FOR(x,N) if(S[y][x]=='1') uf(x,y);
	FOR(x,N) cout<<uf[x];
	cout<<endl;
	return;
	*/
	cin>>T;
	while(T--) {
		cin>>N;
		uf.reinit(N);
		
		FOR(i,N) {
			cin>>S[i];
			FOR(x,N) if(S[i][x]=='1') uf(i,x);
		}
		if(uf.count(0)==N) {
			cout<<0<<endl;
			continue;
		}
		x=-1;
		FOR(i,N) if(uf.count(i)==1) x=i;
		if(x!=-1) {
			cout<<1<<endl;
			cout<<x+1<<endl;
			continue;
		}
		
		x=-1;
		int ma=1;
		FOR(i,N) {
			y=uf.count(i);
			FOR(j,N) if(S[i][j]=='1') y--;
			if(y>ma) x=i, ma=y;
		}
		if(x!=-1) {
			cout<<1<<endl;
			cout<<x+1<<endl;
			continue;
		}
		vector<int> C;
		FOR(i,N) if(uf[i]==i) C.push_back(i);
		if(C.size()>=3) {
			cout<<2<<endl;
			cout<<C[0]+1<<" "<<C[1]+1<<endl;
			continue;
		}
		
		ma=N;
		x=-1;
		FOR(i,N) if(uf.count(i)<ma) x=i, ma=uf.count(i);
		cout<<ma<<endl;
		FOR(i,N) if(uf[i]==uf[x]) cout<<i+1<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
