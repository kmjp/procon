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

int N,M;
int X[303030],D[303030];

int ret[1010101];
int pos[1010101];

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
UF<1<<20> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i];
	FOR(i,M) cin>>D[i];
	vector<pair<pair<int,int>,int>> S={{{1,1000000},1}};
	FOR(i,M) {
		vector<pair<pair<int,int>,int>> T;
		FORR2(p,f,S) {
			if(p.first>0) {
				p.first-=D[i];
				p.second-=D[i];
			}
			else {
				p.first+=D[i];
				p.second+=D[i];
			}
			if(p.first>0||p.second<0) {
				T.push_back({p,f});
			}
			else {
				if(p.first<0) T.push_back({{p.first,-1},f});
				if(p.second>0) T.push_back({{1,p.second},f+(1-p.first)});
				x=f-p.first;
				ret[uf[x]]=i+1;
			}
		}
		sort(ALL(T));
		S.clear();
		int pre=0;
		
		FORR(v,T) {
			int L=v.first.first,R=v.first.second,F=v.second;
			x=lower_bound(ALL(S),v)-S.begin();
			if(x&&S[x].first.first>L) x--;
			while(L<=R) {
				if(x==S.size()) break;
				if(L>S[x].first.second) {
					x++;
					continue;
				}
				uf(S[x].second+L-S[x].first.first,F);
				L++;
				F++;
			}
			if(L<=R) {
				S.push_back({{L,R},F});
			}
		}
	}
	FORR2(a,b,S) {
		for(i=a.first;i<=a.second;i++) pos[uf[b+i-a.first]]=i;
	}
	
	FOR(i,N) {
		x=uf[X[i]];
		if(ret[x]) {
			cout<<"Yes "<<ret[x]<<endl;
		}
		else {
			cout<<"No "<<pos[x]<<endl;
		}
			
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
