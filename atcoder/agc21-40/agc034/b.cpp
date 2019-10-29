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

string S,T;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(c,S) {
		if(T.size() && c=='C' && T.back()=='B') T.back()='#';
		else T.push_back(c);
	}
	
	ll num=0;
	ll ret=0;
	reverse(ALL(T));
	FORR(c,T) {
		if(c=='B' || c=='C') {
			num=0;
		}
		else if(c=='#') num++;
		else ret+=num;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
