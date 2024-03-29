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

int N,Q;
int A[303030],pos[303030];
int PL[303030],PR[303030];

int L[1303030],R[1303030];
int ret[1303030];
const int DI=550;

int S[303030];
int B[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,303030) S[i]=B[i]=1<<20;
	FOR(i,N) {
		scanf("%d",&A[i]);
		A[i]--;
		pos[A[i]]=i;
	}
	vector<pair<int,int>> Qs;
	FOR(i,Q) {
		scanf("%d%d",&L[i],&R[i]);
		L[i]--;
		Qs.push_back({L[i],i});
	}
	sort(ALL(Qs));
	
	for(i=N-2;i>=0;i--) {
		for(j=i+1;j<N&&j-i<DI;j++) {
			chmin(S[j],abs(A[j]-A[i]));
			chmin(B[j/DI],abs(A[j]-A[i]));
		}
		for(j=max(0,A[i]-DI);j<min(N,A[i]+DI);j++) if(pos[j]>i) {
			x=pos[j];
			chmin(S[x],abs(A[x]-A[i]));
			chmin(B[x/DI],abs(A[x]-A[i]));
		}
		while(Qs.size()&&Qs.back().first==i) {
			x=Qs.back().second;
			Qs.pop_back();
			ret[x]=1<<20;
			for(y=L[x]/DI;y<R[x]/DI;y++) chmin(ret[x],B[y]);
			for(y=R[x]/DI*DI;y<R[x];y++) chmin(ret[x],S[y]);
		}
	}
	
	FOR(i,Q) _P("%d\n",ret[i]);
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
