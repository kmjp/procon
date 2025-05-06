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
int A[404][404];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
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

const ll mo=998244353;

ll split(vector<int> C);
ll top(vector<int> C) {
	if(C.size()<=1) return 1;
	
	int num[404]={};
	int cnt=0;
	vector<int> D;
	FORR(a,C) {
		FORR(b,C) num[a]+=A[a][b];
		if(num[a]==C.size()) {
			cnt++;
		}
		else {
			D.push_back(a);
		}
	}
	
	if(cnt<=0) return 0;
	if(C.size()==N) {
		if(num[0]!=N) return 0;
		cnt--;
	}
	ll ret=1;
	int i;
	FOR(i,cnt) (ret*=i+1)%=mo;
	(ret*=split(D))%=mo;
	return ret;
	
	
}
ll split(vector<int> C) {
	if(C.size()==0) return 1;
	UF<404> uf;
	FORR(a,C) FORR(b,C) if(A[a][b]) uf(a,b);
	vector<int> D[404];
	FORR(a,C) D[uf[a]].push_back(a);
	ll ret=1;
	int i;
	FOR(i,N) (ret*=top(D[i]))%=mo;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(y,N) FOR(x,N) cin>>A[y][x];
		
		vector<int> C;
		FOR(i,N) C.push_back(i);
		cout<<top(C)<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
