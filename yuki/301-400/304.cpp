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

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	s="000";
	FOR(i,1000) {
		s[0]='0'+(i/100);
		s[1]='0'+(i/10%10);
		s[2]='0'+(i%10);
		
		cout<<s<<endl;
		cin>>t;
		if(t=="unlocked") break;
	}
}


int main(int argc,char** argv){
	string s;int i;
	solve(); return 0;
}
