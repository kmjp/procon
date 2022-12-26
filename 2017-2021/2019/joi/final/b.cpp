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

int N,M;
vector<pair<int,int>> V;
vector<int> W;

int ok(int v) {
	if(v>N || v>M) return 0;
	int i,cur=0;
	priority_queue<int> PQ;
	int pre=-1;
	for(i=M-v;i<M;i++) {
		while(cur<N&&V[cur].first<=W[i]) PQ.push(-V[cur].second), cur++;
		while(PQ.size() && -PQ.top()<pre) PQ.pop();
		
		if(PQ.empty()) return 0;
		pre=-PQ.top();
		PQ.pop();
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		V.push_back({x,y});
	}
	FOR(i,M) {
		cin>>x;
		W.push_back(x);
	}
	sort(ALL(V));
	sort(ALL(W));
	int ret=0;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
