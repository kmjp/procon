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

int H,W,D;
int R[1001][1001];
string A="RYGB*";

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>D;
	
	if(D%2) {
		FOR(y,H) FOR(x,W) R[y][x]=(y+x)%2;
	}
	else if(D%4==2) {
		FOR(y,H) FOR(x,W) R[y][x]=(y%2*2)+(y/2+x/2)%2;
	}
	else {
		FOR(y,H) FOR(x,W) {
			int dy=y+x+1000;
			int dx=y-x+1000;
			R[y][x]=dy/D%2*2+dx/D%2;
			if((y+x)%2==1) R[y][x]^=3;
		}
		
	}
	
	
	FOR(y,H) {
		FOR(x,W) cout<<A[R[y][x]];
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
