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

int N;
string P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	reverse(ALL(P));
	
	int num=2,carry=0,first=1;
	FORR(c,P) {
		x=c-'0'-carry;
		carry=0;
		
		if(num==-1) return _P("No\n");
		
		if(x==0) {
			num=-1;
		}
		else if(x==6||x==7) {
			if(num<1) return _P("No\n");
			num=1;
		}
		else if(x>=2 && x<=4) {
			if(num<2) return _P("No\n");
			carry=1;
		}
		else {
			return _P("No\n");
		}
		if(first&&num!=2) return _P("No\n");
		first=0;
	}
	if(carry) return _P("No\n");
	_P("Yes\n");
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
