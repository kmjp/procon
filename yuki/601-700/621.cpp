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

ll mo=1000000007;

const int MAT=64;
struct Mat { ll v[MAT][MAT]; };
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

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll N;
Mat A,B;

void dfs(int id,int cmask,int row) {
	if(row==0) {
		if((cmask&((1<<3)|(1<<6)))==0) dfs(id,cmask|(1<<3)|(1<<6),1);
		dfs(id,cmask|(1<<6)|(1<<7),2);
		dfs(id,cmask,1);
	}
	if(row==1) {
		if((cmask&((1<<4)|(1<<7)))==0) dfs(id,cmask|(1<<4)|(1<<7),2);
		dfs(id,cmask|(1<<7)|(1<<8),3);
		dfs(id,cmask,2);
	}
	if(row==2) {
		if((cmask&((1<<5)|(1<<8)))==0) dfs(id,cmask|(1<<5)|(1<<8),3);
		dfs(id,cmask,3);
	}
	if(row==3) {
		if((cmask&9)==0) return;
		if((cmask&18)==0) return;
		if((cmask&36)==0) return;
		if((cmask&24)==0) return;
		if((cmask&48)==0) return;
		A.v[cmask>>3][id]++;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,64) {
		if((i&3)==0) continue;
		if((i&6)==0) continue;
		dfs(i,i,0);
		//FOR(j,64) cout<<A.v[i][j]<<" ";
		//cout<<endl;
	}
	B=powmat(N,A);
	ll ret=0;
	FOR(i,64) {
		if((i&3)==0) continue;
		if((i&6)==0) continue;
		if((i&24)==0) continue;
		if((i&48)==0) continue;
		if((i&9)==0) continue;
		if((i&18)==0) continue;
		if((i&36)==0) continue;
		ret+=B.v[i][63];
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
