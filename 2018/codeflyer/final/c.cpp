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
string S;
int C[101010];
int R[101010];
int cand[202000];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	C[0]=101000;
	FOR(i,202000) cand[i]=N+1;
	FOR(i,N) C[i+1]=C[i]+((S[i]=='(')?1:-1);
	FOR(i,N+1) V[C[i]].push_back(i);
	
	for(i=N-1;i>=0;i--) {
		cand[C[i+1]]=i+1;
		R[i]=cand[C[i]-1];
	}
	
	ll ret=0;
	FOR(i,N) {
		ret+=lower_bound(ALL(V[C[i]]),R[i])-lower_bound(ALL(V[C[i]]),i+1);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
