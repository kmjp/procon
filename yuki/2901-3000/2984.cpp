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

int T;
ll A[3][3][3];
ll X[3][3];
ll Y[3][3];
ll Z[3][3];

int cost(vector<int> V) {
	if(V[0]==0&&V[1]==1&&V[2]==2) return 0;
	if(V[0]==0) return 1;
	if(V[1]==1) return 1;
	if(V[2]==2) return 1;
	return 2;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>T;
	while(T--) {
		FOR(x,3) FOR(y,3) FOR(z,3) cin>>A[x][y][z];
		FOR(i,3) FOR(j,3) cin>>X[i][j];
		FOR(i,3) FOR(j,3) cin>>Y[i][j];
		FOR(i,3) FOR(j,3) cin>>Z[i][j];
		vector<int> ZR={0,1,2};
		vector<int> YR={0,1,2};
		vector<int> XR={0,1,2};
		int ret=101010;
		do {
			do {
				do {
					int ok=1;
					
					FOR(i,3) FOR(j,3) {
						ll sum=0;
						FOR(k,3) sum+=A[k][YR[i]][ZR[j]];
						if(sum!=X[i][j]) ok=0;
						sum=0;
						FOR(k,3) sum+=A[XR[i]][k][ZR[j]];
						if(sum!=Y[i][j]) ok=0;
						sum=0;
						FOR(k,3) sum+=A[XR[i]][YR[j]][k];
						if(sum!=Z[i][j]) ok=0;
					}
					
					if(ok) {
						ret=min(ret,cost(ZR)+cost(YR)+cost(XR));
					}
				} while(next_permutation(ALL(ZR)));
			} while(next_permutation(ALL(YR)));
		} while(next_permutation(ALL(XR)));
		
		if(ret>10) ret=-1;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
