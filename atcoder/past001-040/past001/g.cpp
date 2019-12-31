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
int A[10][10];
int V[1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		for(x=y+1;x<N;x++) {
			cin>>A[y][x];
			A[x][y]=A[y][x];
		}
	}
	
	int ma=-1<<30;
	int m1,m2;
	FOR(m1,1<<N) {
		FOR(y,N) FOR(x,y) if((m1&(1<<x))&&(m1&(1<<y))) V[m1]+=A[y][x];
		
	}
	FOR(m1,1<<N) FOR(m2,1<<N) if((m1&m2)==0) {
		int m3=(1<<N)-1-m1-m2;
		ma=max(ma,V[m1]+V[m2]+V[m3]);
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
