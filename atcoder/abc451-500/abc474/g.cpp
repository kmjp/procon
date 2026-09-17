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

int T,N,K;
int vis[1010][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(N%2==0) {
			cout<<"No"<<endl;
			continue;
		}
		if(K<N-1||K>(N*N-1)/2||K%2) {
			cout<<"No"<<endl;
			continue;
		}
		FOR(y,N) FOR(x,N) vis[y][x]=0;
		
		int M=N/2;
		int lef=(K-N+1)/2;
		vis[0][0]=1;
		y=x=0;
		string S="";
		
		FOR(i,M) {
			k=min(lef,N/2);
			lef-=k;
			FOR(j,2*k) S+="R", x++, vis[y][x]=1;
			S+="D",y++,vis[y][x]=1;
			FOR(j,2*k) S+="L", x--, vis[y][x]=1;
			S+="D",y++,vis[y][x]=1;
		}
		while(y!=N-1||x!=N-1) {
			if(y>0&&vis[y-1][x]==0) {
				S+="U",y--,vis[y][x]=1;
			}
			else if(y+1<N&&vis[y+1][x]==0) {
				S+="D",y++,vis[y][x]=1;
			}
			else if(x+1<N&&vis[y][x+1]==0) {
				S+="R",x++,vis[y][x]=1;
			}
		}
		cout<<"Yes"<<endl;
		cout<<S<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
