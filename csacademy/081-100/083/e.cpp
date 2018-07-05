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

int N,M,Q;
ll A[202020],B[202020],L[202020];
map<pair<int,int>,int> R;
vector<pair<int,int>> V[201010];
ll QT[202020],QA[202020],QB[202020],X[202020];
ll tim[404040];

vector<pair<int,int>> E[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>L[i];
		L[i]*=2;
		A[i]--,B[i]--;
		R[{A[i],B[i]}]=i;
		R[{B[i],A[i]}]=i+M;
		V[i].push_back({0,A[i]});
		V[i].push_back({L[i],B[i]});
	}
	FOR(i,N) tim[i]=1LL<<60;
	FOR(i,Q) {
		cin>>tim[N+i]>>x>>y>>X[i];
		X[i]*=2;
		tim[N+i]*=2;
		int cur=R[{x-1,y-1}];
		if(cur<M) {
			V[cur].push_back({X[i],N+i});
		}
		else {
			cur-=M;
			V[cur].push_back({L[cur]-X[i],N+i});
		}
	}
	FOR(i,M) {
		sort(ALL(V[i]));
		FOR(j,V[i].size()-1) {
			E[V[i][j].second].push_back({V[i][j+1].first-V[i][j].first,V[i][j+1].second});
			E[V[i][j+1].second].push_back({V[i][j+1].first-V[i][j].first,V[i][j].second});
		}
	}
	priority_queue<pair<ll,int>> PQ;
	FOR(i,N+Q) PQ.push({-tim[i],i});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(tim[cur]!=co) continue;
		FORR(e,E[cur]) {
			if(tim[e.second]>co+e.first) {
				tim[e.second]=co+e.first;
				PQ.push({-tim[e.second],e.second});
			}
		}
	}
	ll ma=0;
	FOR(i,N+Q) FORR(e,E[i]) {
		ll X=tim[i];
		ll Y=tim[e.second];
		ll L=e.first;
		ma=max(ma,Y+(L-abs(Y-X))/2);
	}
	cout<<ma/2;
	if(ma%2) cout<<".5";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
