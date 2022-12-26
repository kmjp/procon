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

int H,W,Q;
ll SA[101010];
ll SB[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) {
		cin>>i;
		SA[y+1]=SA[y]+((y%2==0)?i:-i);
	}
	FOR(x,W) {
		cin>>i;
		SB[x+1]=SB[x]+((x%2==0)?i:-i);
	}
	
	while(Q--) {
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		
		cout<<(SA[x2]-SA[x1-1])*(SB[y2]-SB[y1-1])<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
