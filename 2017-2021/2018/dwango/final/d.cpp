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

int Q;
ll N;

ll mo=1000000007;

const int MAT=64;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat S[64];
Mat A[64];
Mat B[64];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,63) {
		FOR(j,64) {
			S[i].v[j][j]=1;
			if(j<=i) S[i].v[j+1][j]=1;
		}
	}
	A[0]=B[0]=S[0];
	for(i=1;i<=63;i++) {
		A[i]=mulmat(B[i-1],S[i]);
		B[i]=mulmat(A[i],B[i-1]);
	}
	
	cin>>Q;
	while(Q--) {
		
		cin>>N;
		N--;
		
		vector<ll> E(64,1);
		for(i=59;i>=0;i--) if(N&(1LL<<i)) {
			vector<ll> E2(64,0);
			FOR(x,64) FOR(y,64) (E2[x]+=E[y]*A[i].v[y][x])%=mo;
			E=E2;
		}
		cout<<E[0]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
