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
int A[101010];
int L[1010101],R[1010101];
vector<pair<int,int>> cand[1010];
int ret[1010101];
int vis[101010];
const int DI=330;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		cand[L[i]/DI].push_back({R[i],i});
	}
	FOR(i,DI) {
		ZERO(vis);
		int CL=0,CR=0;
		sort(ALL(cand[i]));
		int num=0;
		FORR2(r,cur,cand[i]) {
			while(CR<r) {
				num-=vis[A[CR]];
				vis[A[CR]]^=1;
				num+=vis[A[CR]];
				CR++;
			}
			while(CL<L[cur]) {
				num-=vis[A[CL]];
				vis[A[CL]]^=1;
				num+=vis[A[CL]];
				CL++;
			}
			while(L[cur]<CL) {
				CL--;
				num-=vis[A[CL]];
				vis[A[CL]]^=1;
				num+=vis[A[CL]];
			}
			ret[cur]=((CR-CL)-num)/2;
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
