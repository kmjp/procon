#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K,X[100020],R[1000020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	int lower_bound(V val) {
		V tv=0;int i,ent=0;
		FOR(i,ME) if(tv+bit[ent+(1<<(ME-1-i))-1]<val) tv+=bit[ent+(1<<(ME-1-i))-1], ent += (1<<(ME-1-i));
		return ent;
	}
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i],R[X[i]]=i+1;
	FOR(i,N) {
		bt.update(X[i],1);
		if(i>=K-1) cout << R[bt.lower_bound(K)] << endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
