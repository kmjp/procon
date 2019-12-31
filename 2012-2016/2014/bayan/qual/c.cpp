#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

void solve() {
	int i,j,k,l,r,x,y; string s[6],t;
	FOR(i,6) cin>>s[i];
	cin>>i;
	while(i--) {
		cin>>t>>j;
		j%=4;
		while(j--) {
			if(t=="X") swap(s[0],s[1]),swap(s[0],s[2]),swap(s[2],s[5]);
			if(t=="Y") swap(s[1],s[4]),swap(s[2],s[1]),swap(s[1],s[3]);
			if(t=="Z") swap(s[0],s[4]),swap(s[0],s[3]),swap(s[5],s[3]);
		}
	}
	FOR(i,5) cout<<s[i]<<" ";
	cout<<s[5]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cin>>i;
	while(i--) solve();
	return 0;
}
