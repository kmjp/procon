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

int N,M,Q;
int A[202020],B[202020],C[202020];
int QA[202020],QB[202020],QC[202020];
ll E[300][300];
int ok[202020];
ll ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		ok[i]=1;
	}
	FOR(i,Q) {
		cin>>QA[i]>>QB[i];
		if(QA[i]==1) {
			QB[i]--;
			ok[QB[i]]=0;
		}
		else {
			cin>>QC[i];
			QB[i]--;
			QC[i]--;
		}
	}
	FOR(x,N) FOR(y,N) E[x][y]=(x==y)?0:1LL<<60;
	FOR(i,M) if(ok[i]) {
		E[A[i]][B[i]]=E[B[i]][A[i]]=min(E[A[i]][B[i]],(ll)C[i]);
	}
	FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
	for(i=Q-1;i>=0;i--) {
		if(QA[i]==2) {
			ret[i]=E[QB[i]][QC[i]];
			if(ret[i]>=1LL<<60) ret[i]=-1;
		}
		else {
			int a=A[QB[i]],b=B[QB[i]];
			E[a][b]=E[b][a]=min(E[a][b],(ll)C[QB[i]]);
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][a]+E[a][b]+E[b][y]);
			FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][b]+E[b][a]+E[a][y]);
		}
	}
	FOR(i,Q) if(QA[i]==2) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
