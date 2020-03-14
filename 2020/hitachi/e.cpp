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

int N,M,H,W;
int A[1024][1024];

int B[1024][1024];
void check() {
	int x,y;
	FOR(y,H) FOR(x,W) {
		B[y+1][x+1]=B[y][x+1]+B[y+1][x]-B[y][x]+A[y][x];
	}
	int ret=0,sum=0;
	int x1,x2,y1,y2;
	FOR(x2,W) FOR(x1,x2+1) FOR(y2,H) FOR(y1,y2+1) {
		int num=B[y2+1][x2+1]-B[y1][x2+1]-B[y2+1][x1]+B[y1][x1];
		if(num%2==1) ret++;
		sum++;
	}
	cout<<ret<<"/"<<sum<<endl;
}


void dfs(int y1,int y2,int x1,int x2) {
	if(y1>y2 || x1>x2) return;
	int my=(y1+y2)/2;
	int mx=(x1+x2)/2;
	A[my][mx]=1;
	dfs(y1,my-1,x1,mx-1);
	dfs(y1,my-1,mx+1,x2);
	dfs(my+1,y2,x1,mx-1);
	dfs(my+1,y2,mx+1,x2);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	H=(1<<N)-1;
	W=(1<<M)-1;
	
	dfs(0,H-1,0,W-1);
	//check();
	
	FOR(y,H) {
		FOR(x,W) cout<<A[y][x];
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
