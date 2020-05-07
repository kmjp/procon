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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	while(1) {
		x=0;
		y=S.size();
		FOR(i,y) {
			if(S[i]=='(') x=i;
			if(S[i]==')') {
				string X=S.substr(0,x);
				string Y=S.substr(x+1,i-x-1);
				string Z=S.substr(i+1);
				S=X+Y;
				reverse(ALL(Y));
				S+=Y+Z;
				break;
			}
		}
		if(i==y) break;
	}
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
