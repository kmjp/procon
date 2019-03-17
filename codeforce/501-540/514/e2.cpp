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

int N,L;
ll S;
ll W[101010];
ll WS[101010];
int P[20][101010];
int C[101010];
vector<int> E[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>S;
	FOR(i,N) {
		cin>>W[i];
		if(W[i]>S) return _P("-1\n");
	}
	WS[0]=W[0];
	FOR(i,N-1) {
		cin>>P[0][i+1];
		P[0][i+1]--;
		E[P[0][i+1]].push_back(i+1);
		WS[i+1]=WS[P[0][i+1]]+W[i+1];
		
		FOR(j,19) P[j+1][i]=P[j][P[j][i]];
		
		x=y=i;
		for(j=19;j>=0;j--) {
			if((L-1)&(1<<j)) x=P[j][x];
			if(WS[i]-(WS[P[j][y]]-W[P[j][y]])<=S) y=P[j][y];
		}
		C[i]=max(x,y);
	}
	
	int ret=0;
	for(i=N-1;i>=0;i--) {
		int first=1;
		FORR(e,E[i]) if(C[e]>=0) {
			if(first==0) ret++;
			first=0;
			C[i]=max(C[i],C[e]);
		}
		
		if(C[i]==i) {
			ret++;
			C[i]=-1;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
