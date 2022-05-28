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


int N,M,Q;
int tim[202020];
ll V[202020];


int A[202020],B[202020],C[202020],D[202020];
vector<int> ev[202020];
ll ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,Q) {
		cin>>A[i+1]>>B[i+1]>>C[i+1];
		if(A[i+1]==1) cin>>D[i+1];
		
		if(A[i+1]==2) tim[B[i+1]]=i+1;
		if(A[i+1]==3) {
			ev[tim[B[i+1]]].push_back(i+1);
		}
	}
	
	
	for(i=Q;i>=1;i--) {
		if(A[i]==1) {
			bt.add(B[i],D[i]);
			bt.add(C[i]+1,-D[i]);
		}
		else if(A[i]==2) {
			FORR(e,ev[i]) {
				ll v=bt(C[e]);
				ret[e]=v-ret[e]+C[i];
			}
		}
		else if(A[i]==3) {
			ret[i]=bt(C[i]);
		}
	}
	FORR(e,ev[0]) {
		ret[e]=bt(C[e])-ret[e];
	}
	for(i-1;i<=Q;i++) if(A[i]==3) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
