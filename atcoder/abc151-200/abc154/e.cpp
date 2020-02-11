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

string N;
int K;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>K;
	while(N.size()<100) N="0"+N;
	string S(100,'0');
	
	ll ret=0;
	FOR(x,100) {
		for(S[x]='1';S[x]<='9';S[x]++) {
			if(K==1 && S<=N) ret++;
			FOR(y,x) {
				for(S[y]='1';S[y]<='9';S[y]++) {
					if(K==2 && S<=N) ret++;
					FOR(z,y) {
						for(S[z]='1';S[z]<='9';S[z]++) {
							if(K==3 && S<=N) ret++;
						}
						S[z]='0';
					}
				}
				S[y]='0';
			}
		}
		S[x]='0';
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
