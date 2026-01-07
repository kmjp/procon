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

int M;
ll from[32][32][32][32];
ll S[32][32][32][32];
ll to[32][32][32][32];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	int a,b,c,d;
	
	from[0][1][2][3]=1;
	cin>>M;
	FOR(y,4) {
		int A[4];
		cin>>A[0]>>A[1]>>A[2]>>A[3];
		ZERO(to);
		FOR(a,31) FOR(b,31) FOR(c,31) FOR(d,31) {
			S[a][b][c][d]=from[a][b][c][d];
			if(a) S[a][b][c][d]+=S[a-1][b][c][d];
			if(b) S[a][b][c][d]+=S[a][b-1][c][d];
			if(c) S[a][b][c][d]+=S[a][b][c-1][d];
			if(d) S[a][b][c][d]+=S[a][b][c][d-1];
			if(a&&b) S[a][b][c][d]-=S[a-1][b-1][c][d];
			if(a&&c) S[a][b][c][d]-=S[a-1][b][c-1][d];
			if(a&&d) S[a][b][c][d]-=S[a-1][b][c][d-1];
			if(b&&c) S[a][b][c][d]-=S[a][b-1][c-1][d];
			if(b&&d) S[a][b][c][d]-=S[a][b-1][c][d-1];
			if(c&&d) S[a][b][c][d]-=S[a][b][c-1][d-1];
			if(a&&b&&c) S[a][b][c][d]+=S[a-1][b-1][c-1][d];
			if(a&&b&&d) S[a][b][c][d]+=S[a-1][b-1][c][d-1];
			if(a&&c&&d) S[a][b][c][d]+=S[a-1][b][c-1][d-1];
			if(b&&c&&d) S[a][b][c][d]+=S[a][b-1][c-1][d-1];
			if(a&&b&&c&&d) S[a][b][c][d]-=S[a-1][b-1][c-1][d-1];
			S[a][b][c][d]=(S[a][b][c][d]%mo+mo)%mo;
			
			if(A[0]!=-1&&A[0]!=a) continue;
			if(A[1]!=-1&&A[1]!=b) continue;
			if(A[2]!=-1&&A[2]!=c) continue;
			if(A[3]!=-1&&A[3]!=d) continue;
			if(a&&a<b&&b<c&&c<d&&d<=M) {
				to[a][b][c][d]=S[a-1][b-1][c-1][d-1];
			}
			
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(a,M+1) FOR(b,M+1) FOR(c,M+1) FOR(d,M+1) ret+=from[a][b][c][d];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
