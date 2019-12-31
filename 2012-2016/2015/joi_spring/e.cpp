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
int B[1010100];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=0,id=-1,dif=0;
	int step=0;
	FOR(i,N-1) {
		cin>>B[i];
		if(B[i]<=ma) continue;
		if(ma+1==B[i]) {
			ma=B[i];
			id=i;
		}
		else if(ma+2==B[i]) {
			if(step) return _P("0\n");
			step=ma+1;
			dif=i-id;
			ma=B[i];
		}
		else {
			return _P("0\n");
		}
	}
	
	if(step) return _P("%d\n",dif);
	
	ll ret=1;
	ma=0;
	FOR(i,N-1) {
		ma=max(ma,B[i]);
		ret+=ma+1;
	}
	cout<<ret-(N-1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
