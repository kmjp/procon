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

int T,N;
ll A[55][55];
int R[55],C[55];
ll P;

const int MAT=1002;
int mat[1002][1002];

int gf2_rank(int A[MAT][MAT],int n) { /* input */
	int i,j,k;
	FOR(i,n) {
		int be=i,mi=n+1;
		for(j=i;j<n;j++) {
			FOR(k,n) if(A[j][k]) break;
			if(k<mi) be=j,mi=k;
		}
		if(mi>=n) break;
		FOR(j,n) swap(A[i][j],A[be][j]);
		
		FOR(j,n) if(i!=j&&A[j][mi]) {
			FOR(k,n) A[j][k] ^= A[i][k];
		}
	}
	return i;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>P;
		ZERO(R);
		ZERO(C);
		set<int> Rs,Cs;
		FOR(i,N) Rs.insert(i),Cs.insert(i);
		FOR(y,N) FOR(x,N) {
			cin>>A[y][x];
			if(A[y][x]==-1) {
				R[y]++;
				C[x]++;
				Rs.erase(y);
				Cs.erase(x);
			}
		}
		if(P>=3) {
			cout<<0<<endl;
			continue;
		}
		FOR(i,N) {
			if(R[i]>1||C[i]>1) break;
		}
		if(i<N) {
			cout<<0<<endl;
			continue;
		}
		
		vector<int> RR,CC;
		FORR(r,Rs) RR.push_back(r);
		FORR(c,Cs) CC.push_back(c);
		FOR(y,RR.size()) {
			FOR(x,CC.size()) mat[y][x]=A[RR[y]][CC[x]];
		}
		k=gf2_rank(mat,RR.size());
		if(k==RR.size()) {
			cout<<1<<endl;
		}
		else {
			cout<<0<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
