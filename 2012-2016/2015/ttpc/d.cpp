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

bool isprime(ll v) {
	if(v==1) return false;
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return true;
}

void dfs(string s,int mask) {
	int i;
	char a='0';
	FORR(r,s) {
		if(r>='a' && r<='z') {
			a=r;
			break;
		}
	}
	
	if(a=='0') {
		ll b=atoll(s.c_str());
		if(isprime(b)) {
			cout<<b<<endl;
			exit(0);
		}
	}
	else {
		FOR(i,5) if((mask&(1<<i))==0) {
			string t=s;
			FORR(r,t) if(r==a) r='1'+2*i;
			dfs(t,mask|(1<<i));
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	dfs(s,0);
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
