#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>S;
		int L=S.size();
		bool ok=true;
		int W=0,G=0,R=0;
		for(i=L-1;i>=0;i--) {
			if(S[i]=='R') {
				R++;
			}
			if(S[i]=='G') {
				if(R==0) {
					ok=false;
					break;
				}
				R--;
				G++;
			}
			if(S[i]=='W') {
				if(G==0 && W==0) {
					ok=false;
					break;
				}
				else if(G) {
					G--;
					W++;
				}
				else {
					W++;
				}
			}
		}
		
		if(G||R) ok=false;
		
		if(ok) cout<<"possible"<<endl;
		else cout<<"impossible"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
