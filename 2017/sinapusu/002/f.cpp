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

ll mo=1000000007;
map<string,ll> M[32];
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	M[S.size()][S]=1;
	
	for(i=S.size();i>=1;i--) {
		FORR(r,M[i]) {
			s=r.first;
			if(s.find(T)==string::npos) {
				FOR(j,i) (M[i-1][s.substr(0,j)+s.substr(j+1)] += r.second)%=mo;
			}
		}
	}
	if(M[0].empty()) cout<<0<<endl;
	else cout<<M[0].begin()->second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
