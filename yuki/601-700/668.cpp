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
int add;

string incinc(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r=='9') r='0';
		else {
			r++;
			break;
		}
	}
	if(A.back()=='0') A += '1';
	reverse(A.begin(),A.end());
	return A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S;
	
	add=S.size()-3;
	S=S.substr(0,3);
	
	if(S[0]=='9' && S[1]=='9' && S[2]>='5') {
		_P("1.0*10^%d\n",add+3);
	}
	else {
		if(S[2]>='5') {
			S=incinc(S.substr(0,2));
		}
		else {
			S=S.substr(0,2);
		}
		_P("%c.%c*10^%d\n",S[0],S[1],add+2);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
