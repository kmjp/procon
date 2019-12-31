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
	
	while(1) {
		cin>>S;
		if(S.size()==1) break;
		reverse(ALL(S));
		ll cur=0,di=1;
		x=0;
		while(x<S.size()) {
			if(x==0) {
				if(S[x]=='h') x+=5, cur=0;
				else x+=4, cur=90;
			}
			else {
				cur*=2;
				di*=2;
				if(S[x]=='h') x+=5, cur-=90;
				else x+=4, cur+=90;
			}
		}
		ll g=__gcd(cur,di);
		cur/=g;
		di/=g;
		if(di>1) cout<<cur<<"/"<<di<<endl;
		else cout<<cur<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
