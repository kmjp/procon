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
int P[202020],Q[202020];

ll pat[2][2][202020];
const ll mo=998244353;
int vis[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	FOR(i,N) {
		cin>>x;
		Q[P[i]]=x-1;
	}
	
	pat[0][0][0]=pat[1][1][0]=1;
	FOR(i,201010) {
		FOR(x,2) {
			pat[x][0][i+1]=pat[x][1][i];
			pat[x][1][i+1]=(pat[x][0][i]+pat[x][1][i])%mo;
		}
	}
	
	ll ret=1;
	FOR(i,N) if(vis[i]==0) {
		int num=0;
		int cur=i;
		while(vis[cur]==0) {
			vis[cur]=1;
			num++;
			cur=Q[cur];
		}
		(ret*=pat[0][0][num]+pat[1][1][num])%=mo;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
