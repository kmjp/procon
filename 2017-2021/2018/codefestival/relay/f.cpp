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


int N,K,T;
double X[101010][301];
double W[101010][301];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	W[0][0]=1;
	cin>>N>>K;
	FOR(i,N) {
		cin>>T;
		double CX=0,CW=0;
		double LX=0,LW=0;
		FOR(j,K) {
			if(W[i][j]) {
				X[i][j]/=W[i][j];
				CX+=X[i][j]*W[i][j]/K;
				CW+=W[i][j]/K;
				if(j) {
					LX+=(X[i][j]+(K-j))*W[i][j]*j/K;
					LW+=W[i][j]*j/K;
				}
			}
			X[i+1][(j+T)%K]+=(CX/CW+T)*CW;
			W[i+1][(j+T)%K]+=CW;
			CX+=CW;
		}
		if(LW) {
			LX/=LW;
			double w=LW/K;
			FOR(x,K) {
				X[i+1][(x+T)%K]+=(LX+x+T)*w;
				W[i+1][(x+T)%K]+=w;
			}
		}
	}
	
	double ret=0;
	FOR(j,K) ret+=X[N][j];
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
