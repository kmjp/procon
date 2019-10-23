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
int A[101010],B[101010],C[101010];
ll dp[202020];
vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	V.push_back(0);
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		V.push_back(A[i]);
		V.push_back(B[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
		ev[A[i]].push_back(i);
	}
	FOR(i,V.size()) {
		if(i) dp[i]=max(dp[i],dp[i-1]);
		FORR(e,ev[i]) {
			dp[B[e]]=max(dp[B[e]],dp[i]+C[e]);
		}
	}
	cout<<dp[V.size()-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
