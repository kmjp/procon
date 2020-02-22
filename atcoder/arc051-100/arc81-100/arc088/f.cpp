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
vector<int> E[101010];

int dfs(int cur,int pre,int T) {
	multiset<int> V;
	FORR(e,E[cur]) if(e!=pre) {
		int ret=dfs(e,cur,T);
		if(ret==-2) return -2;
		if(ret>=0) V.insert(ret+1);
	}
	if(E[cur].size()%2) V.insert(0);
	
	int cand=-1;
	while(V.size()) {
		int x=*V.rbegin();
		V.erase(V.find(x));
		
		auto it=V.lower_bound(T-x+1);
		if(it==V.begin()) {
			if(cand!=-1) return -2;
			cand=x;
		}
		else {
			it--;
			V.erase(it);
		}
	}
	return cand;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	int A=0;
	FOR(i,N) if(E[i].size()%2==1) A++;
	
	int B=1<<20;
	for(i=19;i>=0;i--) {
		if(dfs(0,-1,B-(1<<i))!=-2) B-=1<<i;
	}
	
	cout<<A/2<<" "<<B<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
