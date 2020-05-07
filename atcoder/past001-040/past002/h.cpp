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

vector<pair<int,int>> V[11];
int H,W;
string S[51];

int D[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			if(S[y][x]=='S') V[0].push_back({y,x});
			else if(S[y][x]=='G') V[10].push_back({y,x});
			else V[S[y][x]-'0'].push_back({y,x});
			D[y][x]=1<<20;
		}
	}
	
	D[V[0][0].first][V[0][0].second]=0;
	FOR(i,10) {
		FORR(v,V[i]) FORR(w,V[i+1]) {
			r=D[v.first][v.second]+abs(v.first-w.first)+abs(v.second-w.second);
			D[w.first][w.second]=min(D[w.first][w.second],r);
		}
	}
	
	int ret=D[V[10][0].first][V[10][0].second];
	if(ret>=1<<20) cout<<-1<<endl;
	else cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
