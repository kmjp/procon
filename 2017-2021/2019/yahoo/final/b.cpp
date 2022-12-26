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

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

vector<int> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[3];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	int i;
	FOR(i,D[0].size()) D[2].push_back(max(D[0][i],D[1][i]));
	return D[2];
}

int N,M;
vector<vector<int>> E[2];
vector<int> D[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E[0].resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[0][x-1].push_back(y-1);
		E[0][y-1].push_back(x-1);
	}
	cin>>M;
	E[1].resize(M);
	FOR(i,M-1) {
		cin>>x>>y;
		E[1][x-1].push_back(y-1);
		E[1][y-1].push_back(x-1);
	}
	D[0]=diameter(E[0]);
	D[1]=diameter(E[1]);
	vector<ll> S;
	S.push_back(0);
	sort(ALL(D[0]));
	sort(ALL(D[1]));
	FORR(d,D[1]) S.push_back(d+S.back());
	
	ll ret=0;
	ll MD=max(D[0].back(),D[1].back());
	FORR(d,D[0]) {
		int e=MD-d-1;
		x=lower_bound(ALL(D[1]),e)-D[1].begin();
		ret+=MD*x+(S[M]-S[x]+1LL*(d+1)*(M-x));
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
