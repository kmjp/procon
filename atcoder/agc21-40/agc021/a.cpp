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

int hoge(string S) {
	int ret=0;
	FORR(c,S) ret+=c-'0';
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int ma=hoge(S);
	
	for(i=0;i<S.size();i++) {
		string T=S;
		if(S[i]!='0') {
			T[i]--;
			for(j=i+1;j<S.size();j++) T[j]='9';
		}
		ma=max(ma,hoge(T));
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
