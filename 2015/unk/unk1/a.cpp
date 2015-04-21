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

int pat[2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>s;
	pat[1][0]=pat[1][1]=-100;
	FORR(c,s) {
		if(c=='F') {
			pat[0][0]++;pat[0][1]++;
			pat[1][0]--;pat[1][1]--;
		}
		if(c=='T') {
			swap(pat[0][0],pat[1][0]);
			swap(pat[0][1],pat[1][1]);
		}
		if(c=='?') {
			int op[2][2];
			memmove(op,pat,sizeof(op));
			pat[0][0]=max(op[0][0]+1,op[1][0]);
			pat[0][1]=min(op[0][1]+1,op[1][1]);
			pat[1][0]=max(op[1][0]-1,op[0][0]);
			pat[1][1]=min(op[1][1]-1,op[0][1]);
		}
	}
	cout<<max(pat[0][0],pat[1][0])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
