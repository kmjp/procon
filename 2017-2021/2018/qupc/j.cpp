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

int N,Q;
string S;
string T[202020];
vector<int> V[202020];
int ret[202020];

int num[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i];
		if(T[i].size()>N) T[i].resize(N);
		V[T[i].size()].push_back(i);
	}
	
	for(i=1;i<=N;i++) if(V[i].size()) {
		
		for(j=1;j<N;j++) num[j%i][S[j]!=S[j-1]]++;
		
		FORR(v,V[i]) {
			FOR(j,i) ret[v]+=num[(j+1)%i][T[v][j]==T[v][(j+1)%i]];
			ret[v]+=S[0]!=T[v][0];
			ret[v]=(ret[v]+1)/2;
		}
		
		FOR(j,i) num[j][0]=num[j][1]=0;
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
