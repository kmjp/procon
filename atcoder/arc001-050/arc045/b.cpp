#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int S[303030],T[303030];
int ok[303030];
int ok2[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>S[i]>>T[i];
		ok[S[i]]++;
		ok[T[i]+1]--;
	}
	for(i=1;i<=N;i++) {
		ok[i]+=ok[i-1];
		ok2[i]=ok2[i-1]+(ok[i]>1);
	}
	vector<int> R;
	FOR(i,M) {
		if(ok2[T[i]]-ok2[S[i]-1]==T[i]-(S[i]-1)) R.push_back(i+1);
	}
	_P("%d\n",R.size());
	FORR(r,R) _P("%d\n",r);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
