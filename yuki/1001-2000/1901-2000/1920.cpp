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
int L[1210101],R[1210101],D[1210101],U[1210101];
vector<int> LRdel[1210101],LRadd[1210101],UDdel[1210101],UDadd[1210101];


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
UF<1<<21> uf;


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,21> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(L);
	MINUS(R);
	MINUS(U);
	MINUS(D);
	
	ll NE=0,NV=2*(N+M);
	FOR(i,N) {
		cin>>y>>l>>r;
		y*=3;
		l=l*3-1;
		r=r*3+1;
		LRadd[l].push_back(y);
		LRdel[r].push_back(y);
		L[y]=l;
		R[y]=r;
	}
	FOR(i,M) {
		cin>>x>>l>>r;
		x*=3;
		l=l*3-1;
		r=r*3+1;
		UDadd[l].push_back(x);
		UDdel[r].push_back(x);
		D[x]=l;
		U[x]=r;
	}
	
	for(x=0;x<=1000000;x++) {
		FORR(y,LRadd[x]) bt.add(y,1);
		if(D[x]!=-1) {
			NE+=1+bt(U[x]-1)-bt(D[x]);
			NV+=bt(U[x]-1)-bt(D[x]);
		}
		FORR(y,LRdel[x]) bt.add(y,-1);
	}
	
	for(y=0;y<=1000000;y++) {
		FORR(x,UDadd[y]) bt.add(x,1);
		if(L[y]!=-1) NE+=1+bt(R[y]-1)-bt(L[y]);
		FORR(x,UDdel[y]) bt.add(x,-1);
	}
	
	set<pair<int,int>> S;
	set<int> T;
	S.insert({-1,-1});
	S.insert({1<<20,1<<20});
	T.insert(-1);
	T.insert(1<<20);
	FOR(x,1000000) {
		if(D[x]!=-1) {
			int mi=1<<20,ma=-1;
			while(1) {
				auto it=S.lower_bound({U[x]+1,0});
				it--;
				if(it->second<D[x]) break;
				if(it->first<D[x]&&U[x]<it->second) {
					auto it2=T.lower_bound(D[x]);
					if(*it2>U[x]) break;
				}
				uf((1<<20)+x,it->first);
				mi=min(mi,it->first);
				ma=max(ma,it->second);
				S.erase(it);
			}
			if(mi<=ma) S.insert({mi,ma});
			
		}
		FORR(e,LRadd[x]) {
			T.insert(e);
			auto it=S.lower_bound({e,0});
			it--;
			if(it->second>e) {
				int a=it->first;
				int b=it->second;
				assert(a<e&&e<b);
				S.erase(it);
				auto it2=T.find(e);
				S.insert({a,*prev(it2)});
				S.insert({e,e});
				S.insert({*next(it2),b});
			}
			else {
				S.insert({e,e});
			}
		}
		FORR(e,LRdel[x]) {
			auto it=S.lower_bound({e+1,0});
			it--;
			int a=it->first;
			int b=it->second;
			assert(a<=e&&e<=b);
			S.erase(it);
			auto it2=T.find(e);
			if(a==e) {
				if(b!=e) {
					S.insert({*next(it2),b});
				}
			}
			else {
				if(b==e) {
					S.insert({a,*prev(it2)});
				}
				else {
					S.insert({a,b});
				}
			}
			
			T.erase(e);
		}
	}
	int con=0;
	FOR(i,1<<20) {
		if(uf[i]==i&&L[i]!=-1) con++;
		if(uf[i+(1<<20)]==i+(1<<20)&&D[i]!=-1) con++;
	}
	//cout<<NE<<" "<<NV<<" "<<con<<endl;
	cout<<NE-NV+con<<endl;
	
	
}
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
