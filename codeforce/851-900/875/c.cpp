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

int T,N,K;
int L[303030],R[303030];
const ll mo=998244353;
vector<int> C[303030];
int TR[303030];

ll catalan(int n) {
	const int NUM_=700001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	return fact[2*n]*factr[n]%mo*factr[n+1]%mo;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,K) {
			cin>>L[i]>>R[i];
			L[i]--;
		}
		L[K]=0,R[K]=N;
		K++;
		FOR(i,N+2) C[i].clear(),TR[i]=-1;
		FOR(i,K) {
			if((R[i]-L[i])%2) break;
			C[L[i]].push_back(R[i]);
		}
		if(i<K) {
			cout<<0<<endl;
			continue;
		}
		vector<pair<int,int>> S;
		FOR(i,N+1) {
			while(S.size()&&S.back().second==i) {
				TR[S.back().first]=S.back().second;
				S.pop_back();
			}
			if(C[i].size()) {
				sort(ALL(C[i]));
				C[i].erase(unique(ALL(C[i])),C[i].end());
				FOR(j,C[i].size()-1) {
					C[C[i][j]].push_back(C[i][j+1]);
				}
				x=C[i][0];
				if(S.size()&&S.back().second<=x) {
					TR[S.back().first]=i;
					if(x>S.back().second) C[S.back().second].push_back(x);
					x=S.back().second;
					S.pop_back();
				}
				S.push_back({i,x});
			}
		}
		assert(S.empty());
		
		set<int> alive;
		set<pair<int,int>> Z;
		FOR(i,N) {
			alive.insert(i);
			bt.add(i,1);
			if(TR[i]>=0) Z.insert({TR[i]-i,i});
		}
		ll ret=1;
		FORR2(a,b,Z) {
			x=bt(TR[b]-1)-bt(b-1);
			if(x%2) {
				ret=0;
			}
			else {
				ret=ret*catalan(x/2)%mo;
			}
			auto it=alive.lower_bound(b);
			while(1) {
				if(it==alive.end()||*it>=TR[b]) break;
				bt.add(*it,-1);
				it=alive.erase(it);
			}
		}
		assert(alive.empty());
		
		
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
