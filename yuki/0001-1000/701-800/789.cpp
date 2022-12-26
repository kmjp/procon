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
BIT<ll,20> bt;

int N;
int A[101010],B[101010],C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> cand;
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		if(A[i]==0) {
			cand.push_back(B[i]);
		}
		else {
			cand.push_back(B[i]);
			cand.push_back(C[i]);
		}
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	FOR(i,N) {
		if(A[i]==0) {
			x=lower_bound(ALL(cand),B[i])-cand.begin();
			bt.add(x,C[i]);
		}
		else {
			x=lower_bound(ALL(cand),B[i])-cand.begin();
			y=lower_bound(ALL(cand),C[i])-cand.begin();
			ret+=bt(y)-bt(x-1);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
