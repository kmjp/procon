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

ll ret;
string S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>S;
	
	x=0;
	FOR(i,S.size()) {
		if((x%2==0 && S[i]=='2') || (x%2==1 && S[i]=='5')) x++;
		else {
			ret+=1LL*(x/2)*(x/2+1)/2;
			x=0;
			if(x%2==0 && S[i]=='2') x++;
		}
	}
	ret+=1LL*(x/2)*(x/2+1)/2;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
