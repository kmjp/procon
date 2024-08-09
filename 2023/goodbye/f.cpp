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

int T,A,B,M;

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

int U[5050],V[5050];
int col[5050];
vector<int> E[5050];

int hoge() {
	UF<2020> uf;
	int i;
	FOR(i,M) if(col[U[i]]==col[V[i]]) uf(U[i],V[i]);
	int ret=0;
	FOR(i,A+B) if(uf[i]==i) ret++;
	return ret==2;
		
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>M;
		FOR(i,M) {
			cin>>U[i]>>V[i];
			U[i]--;
			V[i]--;
		}
		ZERO(col);
		queue<int> Q;
		FOR(i,A+B) {
			col[i]=1;
			if(hoge()) {
				int cur=i;
				FOR(i,M) if(U[i]==cur) Q.push(V[i]);
				FOR(i,M) if(V[i]==cur) Q.push(U[i]);
				break;
			}
			col[i]=0;
		}
		
		int num=1;
		while(Q.size()&&num<A) {
			int cur=Q.front();
			Q.pop();
			if(col[cur]) continue;
			col[cur]=1;
			if(hoge()) {
				num++;
				FOR(i,M) if(U[i]==cur&&col[V[i]]==0) Q.push(V[i]);
				FOR(i,M) if(V[i]==cur&&col[U[i]]==0) Q.push(U[i]);
			}
			else {
				col[cur]=0;
			}
		}
		
		FOR(i,A+B) if(col[i]) cout<<i+1<<" ";
		cout<<endl;
		FOR(i,A+B) if(col[i]==0) cout<<i+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
