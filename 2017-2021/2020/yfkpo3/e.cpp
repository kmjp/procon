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

int N,Q;
ll A[202020],B[202020],C[202020],D[202020];

struct Mat {
	ll v[4][4];
};

int NV=1<<19;
Mat val[1<<20];

Mat comp(Mat& A,Mat& B) {
	Mat C;
	int x,y,z;
	FOR(x,4) FOR(y,4) {
		C.v[x][y]=-1LL<<60;
		for(z=x;z<=y;z++) {
			C.v[x][y]=max(C.v[x][y],A.v[x][z]+B.v[z][y]);
			if(z<y) C.v[x][y]=max(C.v[x][y],A.v[x][z]+B.v[z+1][y]);
		}
	}
	return C;
}

void update(int entry) {
	entry += NV;
	while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>D[i];
	
	FOR(i,2*NV) {
		FOR(x,4) FOR(y,4) val[i].v[x][y]=-1LL<<60;
	}
	for(i=NV+N;i<2*NV;i++) val[i].v[3][3]=0;
	FOR(i,N) {
		val[NV+i].v[0][0]=A[i];
		val[NV+i].v[1][1]=B[i];
		val[NV+i].v[2][2]=C[i];
		val[NV+i].v[3][3]=D[i];
		if(i==N-1) val[NV+i].v[2][2]=-1LL<<60;
	}
	for(i=NV-1;i>=1;i--) val[i]=comp(val[i*2],val[i*2+1]);
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		swap(A[x],A[y]);
		swap(B[x],B[y]);
		swap(C[x],C[y]);
		swap(D[x],D[y]);
		val[NV+x].v[0][0]=A[x];
		val[NV+x].v[1][1]=B[x];
		val[NV+x].v[2][2]=C[x];
		val[NV+x].v[3][3]=D[x];
		val[NV+y].v[0][0]=A[y];
		val[NV+y].v[1][1]=B[y];
		val[NV+y].v[2][2]=C[y];
		val[NV+y].v[3][3]=D[y];
		if(y==N-1) val[NV+y].v[2][2]=-1LL<<60;
		update(x);
		update(y);
		cout<<val[1].v[0][3]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
