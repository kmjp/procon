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


int N,X;
int A[505],B[505];

ll from[50505][2];
ll to[50505][2];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	FOR(j,50001) from[j][0]=from[j][1]=1LL<<60;
	from[0][0]=0;
	
	FOR(i,N) {
		FOR(j,50001) to[j][0]=to[j][1]=1LL<<60;
		FOR(x,49901) {
			to[x+X][0]=min(to[x+X][0],from[x][0]+B[i]);
			to[x+X][1]=min(to[x+X][1],from[x][1]+B[i]);
			to[x+A[i]][1]=min(to[x+A[i]][1],from[x][0]);
			to[x+A[i]][1]=min(to[x+A[i]][1],from[x][1]);
		}
		swap(from,to);
	}
	
	ll mi=1LL<<60;
	FOR(j,50001) if(j>=N*X) mi=min(mi,from[j][1]);
	if(mi>=1LL<<60) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
