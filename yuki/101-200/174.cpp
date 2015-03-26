#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,T;
double P[2],ret;
int A[30],B[30];
double PP[2][1<<21];
double PQ[2][21][21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P[0]>>P[1];
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	sort(A,A+N);
	sort(B,B+N);
	
	PP[0][0]=PP[1][0]=1;
	FOR(i,N) FOR(x,1<<N) if(__builtin_popcount(x)==i) {
		int f=1;
		FOR(j,N) if((x & (1<<j))==0) {
			if(i==N-1) {
				PP[0][x | (1<<j)] += PP[0][x];
				PP[1][x | (1<<j)] += PP[1][x];
				PQ[0][j][i] += PP[0][x];
				PQ[1][j][i] += PP[1][x];
			}
			else {
				if(f) {
					PP[0][x | (1<<j)] += PP[0][x] * P[0];
					PP[1][x | (1<<j)] += PP[1][x] * P[1];
					PQ[0][j][i] += PP[0][x] * P[0];
					PQ[1][j][i] += PP[1][x] * P[1];
					f=0;
				}
				else {
					PP[0][x | (1<<j)] += PP[0][x] * (1-P[0])/(N-1-i);
					PP[1][x | (1<<j)] += PP[1][x] * (1-P[1])/(N-1-i);
					PQ[0][j][i] += PP[0][x] * (1-P[0])/(N-1-i);
					PQ[1][j][i] += PP[1][x] * (1-P[1])/(N-1-i);
				}
			}
		}
	}
	
	FOR(i,N) FOR(x,N) FOR(y,N) if(A[x]>B[y]) ret += (A[x]+B[y]) * PQ[0][x][i]*PQ[1][y][i];
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
