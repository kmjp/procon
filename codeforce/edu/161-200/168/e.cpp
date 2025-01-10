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

int A[202020];
const int DI=2000;

int win[121+1][202020];
int ret[202020];
int num[202020];
int X[202020],Y[202020];
vector<int> ev[DI+1];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	
	for(x=1;x<=121-2;x++) {
		FOR(i,N) {
			win[x][i+1]=win[x][i];
			if(A[i]>=x) win[x][i+1]++;
		}
	}
	
	FOR(i,Q) {
		cin>>x>>y;
		if(y>=2000) {
			int cur=0;
			int lv=1;
			int ok=0;
			while(cur<N) {
				int nex=lower_bound(win[lv]+min(N+1,cur+y-1),win[lv]+N+1,win[lv][cur]+y)-win[lv];
				if(x<=nex) {
					if(A[x-1]>=lv) ret[i]=1;
					break;
				}
				cur=nex;
				lv++;
			}
		}
		else {
			ev[y].push_back(i);
			X[i]=x;
		}
	}
	
	for(x=1;x<=2000+2;x++) {
		int step=x;
		FOR(i,N) {
			num[i]=0;
			if(A[i]>=step/x) {
				num[i]=1;
				step++;
			}
		}
		FORR(e,ev[x]) ret[e]=num[X[e]-1];
	}
	
	
	FOR(i,Q) {
		if(ret[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
