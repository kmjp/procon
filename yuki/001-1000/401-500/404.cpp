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

int N;
int A[202020];
int Q;
int L[202020],R[202020];

ll LU[202020],RU[202020];
ll LD[202020],RD[202020];


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

BIT<ll,21> LL,RR,ret;

vector<int> V;
map<ll,ll> sameL,sameR;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>Q;
	FOR(i,Q) cin>>L[i]>>R[i];
	
	V.push_back(0);
	V.push_back(1<<30);
	FOR(i,N) V.push_back(A[i]);
	FOR(i,Q) V.push_back(L[i]),V.push_back(R[i]);
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		LU[i]=LL(1<<20)-LL(A[i]);
		LD[i]=LL(A[i]-1);
		LL.add(A[i],1);
	}
	for(i=N-1;i>=0;i--) {
		RU[i]=RR(1<<20)-RR(A[i]);
		RD[i]=RR(A[i]-1);
		RR.add(A[i],1);
		ret.add(A[i],LU[i]*RU[i]+LD[i]*RD[i]);
	}
	
	FOR(i,N) sameR[A[i]]++;
	ll same=0;
	FOR(i,N) {
		same -= sameL[A[i]]*sameR[A[i]];
		ret.add(A[i],-same);
		sameR[A[i]]--;
		sameL[A[i]]++;
		same += sameL[A[i]]*sameR[A[i]];
	}
	
	FOR(i,Q) {
		x=lower_bound(ALL(V),L[i])-V.begin();
		y=lower_bound(ALL(V),R[i])-V.begin();
		cout<<ret(y)-ret(x-1)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
