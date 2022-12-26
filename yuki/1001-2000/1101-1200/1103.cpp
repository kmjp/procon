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
vector<int> E[2][1010101];
int in[2][1010101];
int C[2][1010101];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[0][x].push_back(y);
		E[1][y].push_back(x);
		in[0][y]++;
		in[1][x]++;
	}
	FOR(i,2) {
		queue<int> Q;
		FOR(j,N) if(in[i][j]==0) Q.push(j);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			C[i][x]++;
			FORR(e,E[i][x]) {
				C[i][e]+=C[i][x];
				in[i][e]--;
				if(in[i][e]==0) Q.push(e);
			}
		}
	}
	ll ret=0;
	FOR(i,N) FORR(e,E[0][i]) ret+=1LL*C[0][i]*C[1][e]%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
