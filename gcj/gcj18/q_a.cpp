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

int T,testcase;

ll D;
string P;

ll damage(string S) {
	ll cur=1,tot=0;
	FORR(c,S) {
		if(c=='C') cur*=2;
		else tot+=cur;
	}
	return tot;
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>P;
	int num=0;
	while(1) {
		if(damage(P)<=D) return _P("Case #%d: %d\n",TC,num);
		num++;
		for(i=P.size()-1;i>=0;i--) {
			if(P[i]=='C'&&P[i+1]=='S') {
				swap(P[i],P[i+1]);
				break;
			}
		}
		if(i==-1) break;
		
	}
	_P("Case #%d: IMPOSSIBLE\n",TC);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
