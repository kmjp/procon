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
ll K;
int P[303030],R[303030],Q[303030],W[303030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ll rev=0;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			R[P[i]]=i;
			rev+=bt(N)-bt(P[i]);
			bt.add(P[i],1);
		}
		FOR(i,N) bt.add(P[i],-1);
		
		ll maq=1LL*N*(N-1)/2;
		ll mr=maq-rev;
		
		if(K<rev||mr*2+rev<K||(K-rev)%2) {
			cout<<"NO"<<endl;
			continue;
		}
		
		K=(K-rev)/2;
		
		int mi=-1,ma=N;
		FOR(i,N) {
			x=R[i];
			if(K==0) {
				Q[P[x]]=++ma;
			}
			else if(K>=bt(x)) {
				K-=bt(x);
				Q[P[x]]=--mi;
			}
			else {
				vector<pair<int,int>> A;
				Q[P[x]]=++ma;
				FOR(j,x) if(P[j]<P[x]) A.push_back({Q[P[j]],P[j]});
				sort(ALL(A));
				reverse(ALL(A));
				FOR(j,K) swap(Q[P[x]],Q[A[j].second]);
				K=0;
			}
			bt.add(x,1);
		}
		FOR(i,N) bt.add(i,-1);
		
		vector<int> V;
		FOR(i,N) V.push_back(Q[i]);
		sort(ALL(V));
		
		cout<<"YES"<<endl;
		FOR(i,N) {
			x=lower_bound(ALL(V),Q[i])-V.begin();
			cout<<x+1<<" ";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
