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
ll A[303],B[303];

ll from[155][155];
ll to[155][155];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	FOR(i,M) cin>>B[i];
	sort(A,A+N);
	sort(B,B+M);
	
	ll ret=0;
	if(N%2==1) {
		if(M%2==1) ret+=A[N-1];
		FOR(i,M) ret+=B[i];
		N--;
	}
	if(M%2==1) {
		FOR(i,N) ret+=A[i];
		M--;
	}
	vector<pair<int,int>> cand;
	FOR(i,N) cand.push_back({A[i],0});
	FOR(i,M) cand.push_back({B[i],1});
	sort(ALL(cand));
	FOR(x,152) FOR(y,152) from[x][y]=1LL<<60;
	from[0][0]=0;
	int D=0,C=0;
	FORR2(v,i,cand) {
		FOR(x,152) FOR(y,152) to[x][y]=1LL<<60;
		FOR(x,152) FOR(y,152) {
			if(i==0) {
				//‘O”¼
				chmin(to[x+1][y],from[x][y]+1LL*v*(M-2*y));
				//Œã”¼
				chmin(to[x][y],from[x][y]+1LL*v*(M-2*(C-y)));
			}
			else {
				//‘O”¼
				chmin(to[x][y+1],from[x][y]+1LL*v*(N-2*x));
				//Œã”¼
				chmin(to[x][y],from[x][y]+1LL*v*(N-2*(D-x)));
			}
		}
		if(i==0) D++;
		else C++;
		swap(from,to);
	}
	
	
	cout<<ret+from[N/2][M/2]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
