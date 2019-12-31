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

int N,L;
string W[555];
int ok[9][256];

ll pat[150][256][256];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>W[i];
		int mask=0;
		FORR(c,W[i]) {
			mask=(mask<<1)|(c-'0');
		}
		ok[W[i].size()][mask]=1;
	}
	ll ret=0;
	pat[L][0][1]=1;
	for(i=L;i>0;i--) {
		FOR(x,256) FOR(y,256) FOR(k,2) {
			int nex=((x<<1)|k)&255;
			int ney=(y<<1)&255;
			for(j=1;j<=8;j++) if((y&(1<<(j-1))) && ok[j][nex&((1<<j)-1)]==1) break;
			if(j<9) ney|=1;
			(pat[i-1][nex][ney]+=pat[i][x][y])%=mo;
			
			if(i==1 && (ney&1)) ret+=pat[i][x][y];
		}
	}
	
	cout<<ret%mo<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
