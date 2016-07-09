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

int N,K;
int A[2020];
ll mi[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(x,2020) FOR(y,2020) mi[x][y]=1<<30;
	
	cin>>N>>K;
	ll sum=0;
	mi[0][0]=0;
	FOR(i,N) {
		cin>>x;
		
		if(i==0) {
			mi[1][1]=1;
			mi[1][0]=0;
		}
		else {
			FOR(j,i+1) if(mi[i][j]<1<<30) {
				//good
				ll y=mi[i][j]*x;
				y=(y/sum)+1;
				if(y<=x) mi[i+1][j+1]=min(mi[i+1][j+1],mi[i][j]+y);
				//same
				mi[i+1][j]=min(mi[i+1][j],mi[i][j]);
			}
		}
		
		sum+=x;
	}
	
	if(sum==0) return _P("0\n");
	if(sum==K) return _P("1\n");
	
	for(i=N;i>=0;i--) if(mi[N][i]<=K) return _P("%d\n",i);
	_P("0\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
