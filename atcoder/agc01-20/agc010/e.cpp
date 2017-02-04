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
int A[2020];
vector<pair<int,int>> E[2020];
int vis[2020];

deque<int> dfs(int cur) {
	deque<int> R;
	vis[cur]=1;
	sort(ALL(E[cur]));
	FORR(r,E[cur]) if(vis[r.second]==0) {
		deque<int> R2=dfs(r.second), R3;
		while(R.size() || R2.size()) {
			if(R2.size() && (R.empty() || R.front()<=R2.front())) {
				R3.push_back(R2.front());
				R2.pop_front();
			}
			else {
				R3.push_back(R.front());
				R.pop_front();
			}
		}
		R=R3;
	}
	R.push_front(A[cur]);
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(x,N) FOR(y,N) if(x!=y && __gcd(A[x],A[y])>1) E[x].push_back({A[y],y});
	
	FOR(i,N) E[N].push_back({A[i],i});
	auto ret=dfs(N);
	FOR(i,N) _P("%d%c",ret[i+1],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
