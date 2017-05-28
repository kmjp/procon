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
int mat[24][24];
int ma[1<<24];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>mat[y][x];
	
	int ret=0;
	for(int mask=0;mask<1<<N;mask++) if((__builtin_popcount(mask)&1)==0) {
		ret=max(ret,ma[mask]);
		FOR(y,N) if((mask&(1<<y))==0) {
			for(x=y+1;x<N;x++) if((mask&(1<<x))==0) {
				int mask2=mask | (1<<y) | (1<<x);
				ma[mask2]=max(ma[mask2],ma[mask]+mat[y][x]);
				ret = max(ret, ma[mask2]);
			}
			break;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
