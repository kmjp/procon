#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int L;
string S;

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>L>>S;
	
	int n0=0,n1=0,r=0;
	FOR(i,2*L-1) {
		if(S[i]!=S[i+1]) {
			i++;
		}
		else {
			if(S[i]=='0') {
				if(n0) n0--;
				else r++,n1++;
			}
			else {
				if(n1) n1--;
				else r++,n0++;
			}
		}
	}
	cout<<r<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
