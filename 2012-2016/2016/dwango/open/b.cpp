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

ll N;
ll X[1010];
double memo[1010][1010][2];

int ok(double v) {
	int x,y,cur;
	int w,L,R;
	FOR(x,N+1) FOR(y,N+1) memo[x][y][0]=memo[x][y][1]=1e20;
	FOR(x,N) if(X[x]==0) cur=x;
	
	memo[cur][cur][0]=0;
	for(w=1;w<=N;w++) {
		for(L=0;L+w-1<N;L++) {
			R=L+w-1;
			FOR(x,2) {
				int now=x?R:L;
				if(memo[L][R][x]>=1e20) continue;
				double tim = memo[L][R][x];
				if(L) {
					double ne=tim + (X[now]-X[L-1])/v;
					if(memo[L-1][R][0]>ne && ne<=abs(X[L-1])) memo[L-1][R][0]=ne;
				}
				if(R<N-1) {
					double ne=tim + (X[R+1]-X[now])/v;
					if(memo[L][R+1][1]>ne && ne<=abs(X[R+1])) memo[L][R+1][1]=ne;
				}
			}
		}
	}
	
	return (memo[0][N-1][0]<1e20 || memo[0][N-1][1]<1e20);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	N++;
	sort(X,X+N);
	
	double L=1,R=1e10;
	FOR(i,80) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	
	_P("%.12lf\n",(L+R)/2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
