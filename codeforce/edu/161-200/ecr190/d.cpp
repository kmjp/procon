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
int A[505050],B[505050];
vector<int> AP[505050],BP[505050],CP[505050];
int nex[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) {
			AP[i].clear();
			BP[i].clear();
			CP[i].clear();
		}
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) {
			A[i]--;
			B[i]--;
			AP[A[i]].push_back(i);
			BP[B[i]].push_back(i);
			if(A[i]==B[i]) CP[A[i]].push_back(i);
		}
		for(i=N-1;i>=0;i--) if(A[i]==B[i]) {
			j=A[i]+1;
			x=lower_bound(ALL(AP[j]),i)-AP[j].begin();
			y=lower_bound(ALL(BP[j]),i)-BP[j].begin();
			k=lower_bound(ALL(CP[j]),i)-CP[j].begin();
			if(k!=CP[j].size()) {
				if(AP[j][x]<CP[j][k]||BP[j][y]<CP[j][k]) {
					nex[i]=min(AP[j][x],BP[j][y])-1;
				}
				else {
					nex[i]=nex[CP[j][k]];
				}
			}
			else {
				nex[i]=N-1;
				if(x<AP[j].size()) nex[i]=min(nex[i],AP[j][x]-1);
				if(y<BP[j].size()) nex[i]=min(nex[i],BP[j][y]-1);
			}
		}
		ll ret=0;
		FOR(i,N) {
			x=lower_bound(ALL(AP[0]),i)-AP[0].begin();
			y=lower_bound(ALL(BP[0]),i)-BP[0].begin();
			k=lower_bound(ALL(CP[0]),i)-CP[0].begin();
			int cand;
			if(k!=CP[0].size()) {
				cand=nex[CP[0][k]];
				if(AP[0][x]<CP[0][k]) cand=min(cand,AP[0][x]-1);
				if(BP[0][y]<CP[0][k]) cand=min(cand,BP[0][y]-1);
			}
			else {
				cand=N-1;
				if(x<AP[0].size()) cand=min(cand,AP[0][x]-1);
				if(y<BP[0].size()) cand=min(cand,BP[0][y]-1);
			}
			ret+=cand-i+1;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
