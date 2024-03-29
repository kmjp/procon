#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	set<int> B;
	FOR(i,N) if(S[i]=='1') B.insert(i);
	
	ll num=0;
	FOR(i,N) {
		B.erase(i);
		if(S[i]!=T[i]) {
			if(B.empty()) return _P("-1\n");
			x=*B.begin();
			S[i]^=1;
			S[x]^=1;
			B.erase(x);
			num+=x-i;
		}
	}
	cout<<num<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
