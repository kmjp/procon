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

int N,P;
ll W[101010],B[101010];
int V[101010];

ll SW[101010];
ll SB[101010];

bool cmp(int& a,int& b) {
	return 100*W[b]-P*(W[b]+B[a])>100*W[a]-P*(W[a]+B[b]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) cin>>W[i]>>B[i], V[i]=i;
	sort(V,V+N,cmp);
	
	FOR(i,N) {
		SW[i+1]=SW[i]+W[V[i]];
		SB[i+1]=SB[i]+B[V[i]];
	}
	for(i=1;i<=N;i++) {
		ll TW=SW[N]-SW[N-i];
		ll TB=SB[N-i];
		
		if(100*TW>=P*(TW+TB)) {
			return _P("%d\n",i);
		}
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
