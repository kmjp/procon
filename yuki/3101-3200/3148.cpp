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

int N;
string S;
int P[202020];
ll A[101010];
ll B[101010];


class Compare {
public:
    bool operator()(const int& a,const int& b) const {
		if(A[a]*B[b]!=A[b]*B[a]) {
			return A[a]*B[b]>A[b]*B[a];
		}
		return a<b;
	};
};


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
UF<101010> uf;
set<int,Compare> Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	S="("+S+")";
	B[0]=1;
	FOR(i,N) {
		cin>>A[i+1];
		B[i+1]=1;
	}
	vector<int> V;
	x=0;
	FORR(c,S) {
		if(c=='(') {
			if(x) P[x]=V.back();
			V.push_back(x);
			x++;
		}
		else {
			V.pop_back();
		}
	}
	FOR(i,N) Q.insert(i+1);
	ll ret=0;
	while(Q.size()) {
		int cur=*Q.begin();
		Q.erase(cur);
		x=uf[P[cur]];
		Q.erase(x);
		ret+=B[x]*A[cur];
		A[cur]=A[x]=A[cur]+A[x];
		B[cur]=B[x]=B[cur]+B[x];
		P[cur]=P[x];
		uf(cur,x);
		if(uf[cur]!=uf[0]) Q.insert(uf[cur]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
