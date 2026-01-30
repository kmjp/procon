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

int Q;
int N,M,K;
int T[606060],C[606060];
int B[606060],D[606060];
ll S[606060];
vector<pair<ll,int>> V[606060];
ll P;

vector<int> cand[606060];
set<pair<ll,int>> X[606060];

pair<ll,pair<int,int>> hoge(ll v) {
	ll num=0;
	int a=-1,b=-1,i;
	FOR(i,N) {
		if(T[i]<v) {
			int x=lower_bound(ALL(V[K]),make_pair(v-T[i]+1,0))-V[K].begin();
		
			num+=x;
		}
		if(T[i]<v+S[C[i]]) {
			int x=lower_bound(ALL(V[C[i]]),make_pair(v+S[C[i]]-T[i]+1,0))-V[C[i]].begin();
			num+=x;
			if(T[i]<v) {
				int y=lower_bound(ALL(V[C[i]]),make_pair(v-T[i],0))-V[C[i]].begin();
				num-=y;
			}
		}
	}
	return {num,{-1,-1}};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>M>>K>>P;
		FOR(i,K+1) {
			V[i].clear();
			cand[i].clear();
			X[i].clear();
		}
		FOR(i,N) cin>>T[i];
		FOR(i,N) {
			cin>>C[i];
			C[i]--;
			cand[C[i]].push_back(i);
		}
		FOR(i,M) cin>>B[i];
		FOR(i,M) {
			cin>>D[i];
			D[i]--;
			V[D[i]].push_back({B[i],i});
			V[K].push_back({B[i],i});
			X[D[i]].insert({B[i],i});
			X[K].insert({B[i],i});
		}
		FOR(i,K) cin>>S[i];
		FOR(i,K+1) sort(ALL(V[i]));
		ll ret=1LL<<32;
		for(i=31;i>=0;i--) if(hoge(ret-(1LL<<i)).first>=P) ret-=1LL<<i;
		auto p=hoge(ret);
		int a=-2,b=-2;
		FOR(i,K) {
			FORR2(x,y,V[i]) X[K].erase({x,y});
			FORR(c,cand[i]) {
				auto it=X[K].lower_bound({ret-T[c],0});
				if(it!=X[K].end()&&T[c]+it->first==ret) {
					a=c;
					b=it->second;
				}
				it=X[C[c]].lower_bound({ret+S[i]-T[c],0});
				if(it!=X[C[c]].end()&&T[c]+it->first==ret+S[i]) {
					a=c;
					b=it->second;
				}
				
			}
			
			FORR2(x,y,V[i]) X[K].insert({x,y});
		}
		cout<<a+1<<" "<<b+1<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
