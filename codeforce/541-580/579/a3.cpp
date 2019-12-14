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

int Q,N;
int P[402];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			P[i+N]=P[i];
		}
		int ok=0;
		FOR(i,N) {
			if(P[i]==0) {
				FOR(j,N) if(P[i+j]!=j) break;
				if(j==N) ok=1;
			}
			if(P[i]==N-1) {
				FOR(j,N) if(P[i+j]!=N-1-j) break;
				if(j==N) ok=1;
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
