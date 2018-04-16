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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N,M,K;
int A[101010],B[101010];
int P[101010],Q[101010],R[101010];
vector<int> evd[101010],eva[101010];
ll ret[101010];

BIT<ll,20> bit;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	V.push_back(0);
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		B[i]++;
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	
	FOR(i,M) {
		cin>>P[i]>>Q[i]>>R[i];
		V.push_back(P[i]);
		evd[Q[i]-1].push_back(i);
		eva[R[i]-1].push_back(i);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		FORR(e,evd[i]) ret[e]-=bt(lower_bound(ALL(V),P[e])-V.begin());
		bt.add(lower_bound(ALL(V),A[i])-V.begin(),1);
		bt.add(lower_bound(ALL(V),B[i])-V.begin(),-1);
		FORR(e,eva[i]) ret[e]+=bt(lower_bound(ALL(V),P[e])-V.begin());
	}
	FOR(i,M) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
