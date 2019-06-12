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

int H,W;
string S[3030];

int from[3];
int to[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	int ret=0;
	FOR(r,H+W) {
		int p2=0,p1=0;
		ZERO(from);
		FOR(x,W) {
			y=r-x;
			ZERO(to);
			to[0]=max({from[0],from[1],from[2]});
			if(y>=0 && y<H && S[y][x]=='G' && x>0 && x<W-1 && S[y][x-1]=='R' && S[y][x+1]=='W') {
				to[1]=max({from[0]+1,from[1]+1});
			}
			if(y>=0 && y<H && S[y][x]=='G' && y>0 && y<H-1 && S[y-1][x]=='R' && S[y+1][x]=='W') {
				to[2]=max({from[0]+1,from[2]+1});
			}
			
			swap(from,to);
		}
		ret+=max({from[0],from[1],from[2]});
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
