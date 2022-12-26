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
int A[3030];
int B[3030];
int ok[3030][3030];
int D[3030];
int pre[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+1) cin>>A[i];
	FOR(i,N+1) cin>>B[i];
	FOR(i,N) cin>>D[i];
	
	sort(D,D+N);
	reverse(D,D+N);
	FOR(x,N+1) FOR(y,N+1) pre[x][y]=N+1;
	pre[0][0]=-1;
	
	int ma=0;
	FOR(x,N+1) FOR(y,N+1) if(pre[x][y]<=N) {
		ma=max(ma,x+y);
		FOR(i,2) {
			int nx=x+(i==0);
			int ny=y+(i==1);
			if(nx<=N && ny<=N) {
				
				for(j=pre[x][y]+1;j<N;j++) if(A[nx]+B[ny]>=D[j]) {
					pre[nx][ny]=min(pre[nx][ny],j);
					break;
				}
			}
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
