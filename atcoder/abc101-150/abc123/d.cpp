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

int X,Y,Z,K;
vector<ll> A,B,C;
ll cand[1010101];
int id[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z>>K;
	A.resize(X);
	B.resize(Y);
	C.resize(Z);
	FOR(i,X) cin>>A[i];
	FOR(i,Y) cin>>B[i];
	FOR(i,Z) cin>>C[i];
	sort(ALL(C));
	reverse(ALL(C));
	
	priority_queue<pair<ll,int>> PQ;
	
	FOR(x,X) FOR(y,Y) {
		cand[x*Y+y]=A[x]+B[y];
		PQ.push({cand[x*Y+y]+C[0],x*Y+y});
	}
	
	while(K--) {
		ll sc=PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		
		cout<<sc<<endl;
		
		id[cur]++;
		if(id[cur]<Z) {
			PQ.push({cand[cur]+C[id[cur]],cur});
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
