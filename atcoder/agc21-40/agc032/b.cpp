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
int mat[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N%2==0) {
		for(x=1;x<=N;x++) {
			for(y=1;y<=N;y++) {
				if(x+y!=N+1) mat[x][y]=1;
			}
		}
	}
	else if(N*(N+1)/2%2==0) {
		set<int> A;
		int tot=N*(N+1)/2/2;
		for(i=N;i>=1;i--) {
			if(tot>=i) {
				A.insert(i);
				tot-=i;
			}
		}
		for(x=1;x<=N;x++) {
			for(y=1;y<=N;y++) {
				if(A.count(x)+A.count(y)==1) mat[x][y]=1;
			}
		}
	}
	else {
		for(x=1;x<=N-1;x++) {
			for(y=1;y<=N-1;y++) {
				if(x+y!=N) mat[x][y]=1;
			}
		}
		for(x=1;x<=N-1;x++) mat[x][N]=mat[N][x]=1;
	}
	
	vector<pair<int,int>> V;
	int sum[101]={};
	for(x=1;x<=N;x++) {
		for(y=x+1;y<=N;y++) {
			if(mat[x][y]) {
				V.push_back({x,y});
				sum[x]+=y;
				sum[y]+=x;
			}
		}
	}
	for(x=1;x<=N;x++) assert(sum[1]==sum[x]);
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
