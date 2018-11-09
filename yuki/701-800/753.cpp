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
int A[16][16];
ll win[16][1<<16];
vector<int> C[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	N=16;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		if(A[y][x]==0) A[y][x]=-A[x][y];
	}
	
	FOR(x,N) win[x][1<<x]=1;
	FOR(i,N) FOR(j,1<<N) if(j&(1<<i)) C[j].push_back(i);
	
	for(int mask=1;mask<1<<N;mask++) if(__builtin_popcount(mask)%2==0) {
		FOR(x,N) if(mask&(1<<x)) break;
		for(int sub=mask; sub>0; sub=(sub-1)&mask) if((sub&(1<<x)) && __builtin_popcount(sub)*2==__builtin_popcount(mask)) {
			int oth=mask^sub;
			FORR(a,C[sub]) FORR(b,C[oth]) {
				if(A[a][b]>0) win[a][mask]+=2*win[a][sub]*win[b][oth];
				if(A[a][b]<0) win[b][mask]+=2*win[a][sub]*win[b][oth];
			}
		}
	}
	
	FOR(i,N) cout<<win[i][(1<<N)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
