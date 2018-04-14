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
ll PX,PY;
int C[101010],D[101010];

const int MAT=3;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);v[0][0]=v[1][1]=v[2][2]=1;};}; //

Mat mulmat(Mat a,Mat b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
	}
	return r;
}

Mat M[101010];

Mat hoge(int c,int d) {
	Mat m;
	if(c==1) {
		m.v[0][2]=d;
	}
	if(c==2) {
		m.v[1][2]=d;
	}
	if(c==3) {
		m.v[0][0]=m.v[1][1]=0;
		m.v[0][1]=1;
		m.v[1][0]=-1;
	}
	return m;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>PX>>PY;
	FOR(i,N) {
		cin>>C[i];
		if(C[i]!=3) cin>>D[i];
	}
	
	for(i=N-1;i>=0;i--) {
		M[i]=mulmat(M[i+1],hoge(C[i],D[i]));
	}
	FOR(i,N) {
		cout<<(M[i].v[0][0]*PX+M[i].v[0][1]*PY+M[i].v[0][2])<<" "<<(M[i].v[1][0]*PX+M[i].v[1][1]*PY+M[i].v[1][2])<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
