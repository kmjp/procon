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

int N,X,S,F,M;
int A[20][20];
double L[20][20];

double dpf[20][61][20];
ll dpi[20][61][20];
ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>S>>F>>M;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		if(x!=y) L[y][x]=log(A[y][x]);
	}
	
	FOR(x,N) FOR(y,60) FOR(i,N) dpf[x][y][i]=-1;
	FOR(i,N) {
		dpf[i][0][i]=0;
		dpi[i][0][i]=1;
		FOR(j,60) {
			FOR(x,N) if(dpf[i][j][x]>=0) {
				FOR(y,N) if(x!=y && dpf[i][j][x]+L[x][y]>dpf[i][j+1][y]) {
					dpf[i][j+1][y]=dpf[i][j][x]+L[x][y];
					dpi[i][j+1][y]=dpi[i][j][x]*A[x][y]%mo;
				}
			}
		}
	}
	
	double maf=-1;
	ll ma=0;
	FOR(i,N) {
		FOR(x,60) FOR(y,60) for(j=2;j<=20;j++) {
			if(x+y<=M && (M-(x+y))%j==0) {
				double hoge=dpf[S][x][i]+dpf[i][y][F]+dpf[i][j][i]*((M-(x+y))/j);
				if(dpf[S][x][i]<0 || dpf[i][y][F]<0 || dpf[i][j][i]<0) continue;
				if(hoge>maf) {
					maf=hoge;
					ma=X*dpi[S][x][i]%mo*dpi[i][y][F]%mo*modpow(dpi[i][j][i],(M-(x+y))/j)%mo;
				}
			}
		}
		
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
