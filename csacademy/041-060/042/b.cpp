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

string S,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>A>>B;
	for(i=0;i+A.size()<=S.size();i++) {
		if(S.substr(i,A.size())==A) {
			S=S.substr(0,i)+B+S.substr(i+A.size());
			i+=A.size()-1;
		}
		else if(S.substr(i,A.size())==B) {
			S=S.substr(0,i)+A+S.substr(i+B.size());
			i+=A.size()-1;
		}
	}
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
