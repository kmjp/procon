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

ll B1,B2,B3;
ll D1,D2;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B1>>B2>>B3;
	if(B2==B3) {
		cout<<B3<<endl;
		return;
	}
	D1=B2-B1;
	D2=B3-B2;
	//ll R=D2/D1;
	//ll B=B2-B1*D2/D1;
	cout<<(B3*D2+B2*D1-B1*D2)/D1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
