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
int X[16][3];
int ma[1<<16][16][3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(ma);
	cin>>N;
	FOR(i,N) {
		cin>>X[i][0]>>X[i][1]>>X[i][2];
		FOR(x,3) FOR(y,3) if(x!=y) ma[1<<i][i][x][y]=X[i][3-x-y];
	}
	
	int ret=0;
	for(int mask=0;mask<1<<N;mask++) FOR(i,N) if(mask&(1<<i)) {
		FOR(x,3) FOR(y,3) if(x!=y && ma[mask][i][x][y]>=0) {
			ret=max(ret,ma[mask][i][x][y]);
			
			FOR(j,N) if((mask&(1<<j))==0) {
				int x2,y2;
				FOR(x2,3) FOR(y2,3) if(x2!=y2) {
					if(X[j][x2]>X[i][x]) continue;
					if(X[j][y2]>X[i][y]) continue;
					ma[mask|(1<<j)][j][x2][y2]=max(ma[mask|(1<<j)][j][x2][y2],ma[mask][i][x][y]+X[j][3-x2-y2]);
				}
			}
			
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
