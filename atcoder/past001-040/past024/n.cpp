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

int H,W;

map<string,ll> F[50],T[50];

pair<string,int> hoge(string A,string B) {
	UF<20> uf;
	int x,y;
	int num=0;
	FOR(x,W) {
		if(A[x]!='.'&&B[x]!='.'&&uf[A[x]]!=uf[B[x]]) uf(A[x],B[x]), num++;
		if(x&&A[x]!='.'&&A[x-1]!='.'&&uf[A[x]]!=uf[A[x-1]]) uf(A[x],A[x-1]), num++;
		if(x&&B[x]!='.'&&B[x-1]!='.'&&uf[B[x]]!=uf[B[x-1]]) uf(B[x],B[x-1]), num++;
	}
	char nex=1;
	map<int,char> M;
	FORR(c,B) if(c!='.') {
		x=uf[c];
		if(M.count(x)==0) M[x]=nex++;
		c=M[x];
	}
	return {B,num};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	s=string(W,'.');
	F[0][s]=1;
	
	while(H--) {
		FOR(i,50) T[i].clear();
		
		FOR(i,50) FORR2(s,v,F[i]) {
			int mask;
			FOR(mask,1<<W) {
				string s2;
				int now=i;
				FOR(j,W) {
					if(mask&(1<<j)) {
						s2.push_back(8+j);
						now++;
					}
					else s2.push_back('.');
				}
				auto p=hoge(s,s2);
				T[now-p.second][p.first]+=v;
			}
		}
		
		FOR(i,50) swap(F[i],T[i]);
	}
	
	ll ret=0;
	FOR(i,50) FORR2(a,b,F[i]) ret+=i*b;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
