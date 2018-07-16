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

int T,testcase;
int N;
ll X[1010],Y[1010],H[1010];
int okcache[1<<10][10][10][10];
int from[1<<10][10][10][10];

double M[2][2],V[2],R[2];

const int MAT=2;
int Gauss(int n,double mat_[MAT][MAT],double v_[MAT],double r[MAT]) {
	int i,j,k;
	double mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		v[i]/=mat[i][i];
		for(k=n-1;k>=i;k--) mat[i][k]/=mat[i][i];
		for(j=i+1;j<n;j++) {
			v[j]-=v[i]*mat[j][i];
			for(k=n-1;k>=i;k--) mat[j][k]-=mat[i][k]*mat[j][i];
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]-=mat[i][j]*v[j],mat[i][j]=0;
		r[i]=v[i];
	}
	return n;
}


int ok(int mask,int a,int b,int c) {
	M[0][0]=X[b]-X[a];
	M[0][1]=Y[b]-Y[a];
	M[1][0]=X[c]-X[a];
	M[1][1]=Y[c]-Y[a];
	V[0]=-H[a]+H[b];
	V[1]=-H[a]+H[c];
	Gauss(2,M,V,R);
	double ax=R[0];
	double ay=R[1];
	double TH=H[a]-ax*X[a]-ay*Y[a];
	int i;
	FOR(i,N) if(mask&(1<<i)) {
		if(i==a || i==b || i==c) continue;
		if(TH+ax*X[i]+ay*Y[i]<H[i]) return 0;
	}
	return 1;
	
}


void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>H[i];
	int a,b,c;
	MINUS(from);
	for(int mask=0;mask<1<<N;mask++) {
		
		FOR(c,N) if(mask&(1<<c)) {
			FOR(b,N) if((mask&(1<<b))&&b!=c) {
				FOR(a,N) if((mask&(1<<a))&&a!=b && a!=c) {
					okcache[mask][a][b][c]=ok(mask,a,b,c);
					//cout<<mask<<" "<<a<<" "<<b<<" "<<c<<" "<<okcache[mask][a][b][c]<<endl;
				}
			}
		}
		
	}
	for(int mask=0;mask<1<<N;mask++) {
		FOR(c,N) if(mask&(1<<c)) {
			FOR(b,N) if((mask&(1<<b))&&b!=c) {
				FOR(a,N) if((mask&(1<<a))&&a!=b && a!=c) if(from[mask][a][b][c]>=0 || __builtin_popcount(mask)==3) {
					FOR(i,N) if((mask&(1<<i))==0) if(okcache[mask^(1<<i)][i][a][b]) from[mask^(1<<i)][i][a][b] = c;
				}
			}
		}
	}
	vector<int> V;
	FOR(c,N) FOR(b,N) FOR(a,N) if(from[(1<<N)-1][a][b][c]>=0) {
		int mask=(1<<N)-1;
		while(from[mask][a][b][c]>=0) {
			int t=from[mask][a][b][c];
			V.push_back(a);
			mask^=1<<a;
			a=b;
			b=c;
			c=t;
		}
		V.push_back(a);
		V.push_back(b);
		V.push_back(c);
		reverse(ALL(V));
		goto out;
	}
	out:
	_P("Case #%d:",TC);
	FORR(v,V) _P(" %d",v+1);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
