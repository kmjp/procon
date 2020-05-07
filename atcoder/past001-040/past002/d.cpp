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

string S;
vector<string> T[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	T[0].push_back("");
	FOR(i,3) {
		FORR(t,T[i]) {
			FOR(j,27) {
				if(j<26) T[i+1].push_back(t+(char)('a'+j));
				else T[i+1].push_back(t+'.');
			}
		}
	}
	
	ll ret=0;
	for(i=1;i<=3;i++) {
		FORR(t,T[i]) {
			for(j=0;j+i<=S.size();j++) {
				FOR(x,i) {
					if(t[x]!='.' && S[j+x]!=t[x]) break;
				}
				if(x==i) {
					ret++;
					break;
				}
			}
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
