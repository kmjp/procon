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

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	string T;
	FORR(c,S) {
		if(c>='0' && c<='9') T+=c;
		if(c=='A') T+="1";
		if(c=='T') T+="10";
		if(c=='J') T+="11";
		if(c=='Q') T+="12";
		if(c=='K') T+="13";
	}
	
	ll a=atol(T.c_str());
	if(isprime(a) || a==57 || a==1729) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
