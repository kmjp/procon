#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;

/*
const int MAT=301;
double A[MAT][MAT];
double V[MAT];
double R[MAT];


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

double hoge(vector<int> X) {
	int N=X.size()+1;
	int x,y;
	FOR(x,N) FOR(y,N) A[x][y]=V[x]=0;
	A[0][0]=V[0]=1,A[0][1]=-1;
	A[N-1][N-1]=1;
	int i;
	for(i=1;i<N-1;i++) {
		A[i][i]=V[i]=1;
		A[i][i-1]=-1.0*X[i-1]/(X[i-1]+X[i]);
		A[i][i+1]=-1.0*X[i]/(X[i-1]+X[i]);
	}
	Gauss(N,A,V,R);
	return R[0];
}
double hoge2(vector<int> X,int v=0) {
	int N=X.size();
	R[0]=0;
	double ret=N;
	for(int i=1;i<=N-1;i++) {
		double e=2+R[i-1];
		R[i]=e*X[i-1]/X[i];
		ret+=R[i];
	}
	if(v) {
		int i;
		FOR(i,N) cout<<R[i]/2<<" ";
		cout<<endl;
	}
	return (ret-N);
}
*/
double from[3030];
double to[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(N==1) {
		cout<<1<<endl;
		return;
	}
	
	FOR(x,3030) from[x]=1e10;
	from[1]=0;
	for(i=2;i<=N;i++) {
		FOR(x,3030) to[x]=1e10;
		for(x=M;x>=i-1;x--) if(from[x]<1e10) {
			for(y=x/(i-1);x+y*(N+1-i)<=M;y++) {
				chmin(to[x+y],from[x]+1.0*x/y);
			}
		}
		swap(from,to);
	}
	double ret=from[M]*2+N;
	_P("%.12lf\n",ret);
	
	/*
	vector<int> V(4);
	int ma=M;
	double mi=100000;
	for(V[0]=1;V[0]<=ma;V[0]++) {
		for(V[1]=1;V[0]+V[1]<ma;V[1]++) {
			for(V[2]=1;V[0]+V[1]+V[2]<ma;V[2]++) {
				V[3]=ma-V[0]-V[1]-V[2];
				double a=hoge2(V);
				if(a<=mi) {
					mi=a;
					double ma=max({1.0*V[1]/V[0],1.0*V[2]/V[1],1.0*V[3]/V[2]});
					cout<<V[0]<<" "<<V[1]<<" "<<V[2]<<" "<<V[3]<<" "<<a<<" "<<hoge(V)<<endl;
					cout<<"# ";
					hoge2(V,1);
				}
			}
		}
	}
	*/
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
