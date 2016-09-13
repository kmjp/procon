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

int T;
char C;
ll V;
string Q;
int num[1<<18];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		
		cin>>C;
		if(C=='+' || C=='-') {
			cin>>V;
			x = 0;
			FOR(i,18) x = x*2 + V%2, V/=10;
			
			if(C=='+') num[x]++;
			if(C=='-') num[x]--;
		}
		else {
			cin>>Q;
			reverse(ALL(Q));
			x=0;
			FORR(c,Q) x=x*2+(c-'0');
			FOR(i,18-Q.size()) L=L*2;
			cout<<num[L]<<endl;
			
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
