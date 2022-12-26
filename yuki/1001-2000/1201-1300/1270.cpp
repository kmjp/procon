#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int A[20202];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
int B[20202],C[20202];

ll pref[202020],suf[202020];

BIT<int,15> bt;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) {
		if(i) pref[i]+=pref[i-1];
		pref[i]+=bt(N)-bt(A[i]);
		bt.add(A[i],1);
	}
	ZERO(bt.bit);
	for(i=N-1;i>=0;i--) {
		suf[i]=suf[i+1]+bt(A[i]-1);
		bt.add(A[i],1);
	}
	
	
	FOR(i,Q) {
		int L,R;
		ZERO(B);
		ZERO(C);
		
		cin>>L>>R;
		L--,R--;
		ll ret=(L?pref[L-1]:0)+suf[R+1];
		FOR(j,L) B[A[j]]++;
		for(j=N+1;j>=1;j--) B[j]+=B[j+1];
		for(j=R+1;j<N;j++) {
			ret+=B[A[j]+1];
			C[A[j]]++;
		}
		
		for(j=1;j<=N+1;j++) C[j]+=C[j-1];
		int mi=1<<30;
		for(j=1;j<=N;j++) mi=min(mi,(R-L+1)*(B[j+1]+C[j-1]));
		cout<<mi+ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
