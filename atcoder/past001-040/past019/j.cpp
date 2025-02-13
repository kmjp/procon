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

int N;
ll A[15];
ll S[1<<15];
int ret=1<<30;

void dfs(int mask,int ma,int mi) {
	if(mask==0) {
		ret=min(ret,ma-mi);
		return;
	}
	int i,j,k;
	FOR(i,3*N) if(mask&(1<<i)) {
		for(j=i+1;j<3*N;j++) if(mask&(1<<j)) {
			for(k=j+1;k<3*N;k++) if(mask&(1<<k)) {
				int v=A[i]+A[j]+A[k];
				dfs(mask^(1<<i)^(1<<j)^(1<<k),max(ma,v),min(mi,v));
			}
		}
		break;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3*N) cin>>A[i];
	
	dfs((1<<(3*N))-1,0,1<<30);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
