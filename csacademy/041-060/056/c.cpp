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
map<pair<int,int>,int> M;
vector<int> E[101010];
vector<int> E2[101010];
vector<pair<int,int>> ES;
int in[101010],NE;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		E[i].resize(x);
		FOR(j,E[i].size()) {
			cin>>E[i][j];
			E[i][j]--;
			if(M.count(make_pair(E[i][j],i))==0) {
				M[{i,E[i][j]}]=M[{E[i][j],i}]=NE;
				NE++;
				ES.push_back({i+1,E[i][j]+1});
			}
		}
		if(E[i].size()) {
			FOR(j,E[i].size()-1) {
				E2[M[{i,E[i][j]}]].push_back(M[{i,E[i][j+1]}]);
				in[M[{i,E[i][j+1]}]]++;
			}
		}
	}
	vector<int> ret;
	queue<int> Q;
	FOR(i,NE) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		ret.push_back(cur);
		FORR(e,E2[cur]) if(--in[e]==0) Q.push(e);
	}
	
	if(ret.size()!=NE) return _P("-1\n");
	FOR(i,NE) _P("%d %d\n",ES[ret[i]].first,ES[ret[i]].second);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
