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

int L[3],R[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>L[i]>>R[i];
	double ret=0;
	for(i=L[0];i<=R[0];i++) {
		double pat=1.0/(R[0]-L[0]+1);
		pat *= max(0.0,(R[1]-max(L[1]-1,i))*1.0/(R[1]-L[1]+1));
		pat *= max(0.0,(R[2]-max(L[2]-1,i))*1.0/(R[2]-L[2]+1));
		ret+=pat;
	}
	
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
