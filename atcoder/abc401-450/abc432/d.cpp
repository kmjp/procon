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


int N,X,Y;
template<int um> class UF {
	public:
	
	vector<ll> par,rank,cnt,G[um];
	UF() {par=rank=vector<ll>(um,0); cnt=vector<ll>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	ll count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	vector<array<ll,4>> V={{0,X,0,Y}};
	FOR(i,N) {
		vector<array<ll,4>> W;
		int A,B;
		cin>>s>>A>>B;
		FORR(v,V) {
			if(s=="X") {
				if(v[1]<=A) W.push_back({v[0],v[1],v[2]-B,v[3]-B});
				else if(v[0]>=A) W.push_back({v[0],v[1],v[2]+B,v[3]+B});
				else {
					W.push_back({v[0],A,v[2]-B,v[3]-B});
					W.push_back({A,v[1],v[2]+B,v[3]+B});
				}
			}
			else {
				if(v[3]<=A) W.push_back({v[0]-B,v[1]-B,v[2],v[3]});
				else if(v[2]>=A) W.push_back({v[0]+B,v[1]+B,v[2],v[3]});
				else {
					W.push_back({v[0]-B,v[1]-B,v[2],A});
					W.push_back({v[0]+B,v[1]+B,A,v[3]});
				}
			}
			
		}
		V=W;
	}
	N=V.size();
	FOR(i,N) {
		uf.cnt[i]=1LL*(V[i][1]-V[i][0])*(V[i][3]-V[i][2]);
	}
	map<int,vector<int>> U,D,L,R;
	FOR(i,N) {
		auto v=V[i];
		FORR(x,R[v[0]]) {
			if(min(v[3],V[x][3])-max(v[2],V[x][2])>0) uf(i,x);
		}
		FORR(x,L[v[1]]) {
			if(min(v[3],V[x][3])-max(v[2],V[x][2])>0) uf(i,x);
		}
		FORR(y,D[v[2]]) {
			if(min(v[1],V[y][1])-max(v[0],V[y][0])>0) uf(i,y);
		}
		FORR(y,U[v[3]]) {
			if(min(v[1],V[y][1])-max(v[0],V[y][0])>0) uf(i,y);
		}
		L[v[0]].push_back(i);
		R[v[1]].push_back(i);
		U[v[2]].push_back(i);
		D[v[3]].push_back(i);
	}
	vector<ll> ret;
	FOR(i,N) if(uf[i]==i) ret.push_back(uf.count(i));
	sort(ALL(ret));
	cout<<ret.size()<<endl;
	FORR(v,ret) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
