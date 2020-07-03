#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll A[202020];
int L[202020],R[202020];
ll ret[202020],M[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,18> bt;

pair<ll,int> P[202020];
vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		M[i]=N-1;
	}
	for(j=17;j>=0;j--) {
		FOR(i,Q) if(M[i]-(1<<j)>=0) ev[M[i]-(1<<j)].push_back(i);
		
		FOR(i,N) {
			bt.add(P[i].second,1);
			FORR(e,ev[i]) if(bt(R[e]-1)-bt(L[e]-1)>=(R[e]-L[e]+1)/2) M[e]-=1<<j;
			ev[i].clear();
		}
		FOR(i,N) bt.add(i,-1);
	}
	
	FOR(i,Q) {
		ev[M[i]].push_back(i);
		ll v=P[M[i]].first;
		ret[i]+=1LL*((R[i]-L[i]+1)/2)*v-1LL*(R[i]-L[i]-(R[i]-L[i]+1)/2)*v;
	}
	FOR(i,N) {
		bt.add(P[i].second,A[P[i].second]);
		FORR(e,ev[i]) {
			ret[e]-=2*(bt(R[e]-1)-bt(L[e]-1));
		}
	}
	
	FOR(i,Q) {
		ret[i]+=bt(R[i]-1)-bt(L[i]-1);
		cout<<ret[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
