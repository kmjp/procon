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
int N;
set<int> E[202020];
int NC[2];
int C[202020];
int R[202020];

void dfs(int cur,int pre,int c) {
	C[cur]=c;
	NC[c]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,c^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		NC[0]=NC[1]=0;
		dfs(0,0,0);
		if(NC[0]==N-1) {
			NC[0]=NC[1]=0;
			dfs(0,0,1);
		}
		if(NC[0]==1) {
			x=2,y=4;
			FOR(i,N) {
				if(C[i]==0) {
					R[i]=x;
				}
				else {
					if(y==4) R[i]=1;
					else R[i]=y;
					y+=2;
				}
			}
		}
		else {
			FOR(i,N) if(C[i]==0&&E[i].size()!=NC[1]) x=i;
			FOR(i,N) if(C[i]==1&&E[i].count(x)==0) y=i;
			int a=2,b=2*N;
			
			FOR(i,N) {
				if(i==x) continue;
				if(i==y) continue;
				if(C[i]==0) {
					R[i]=a;
					a+=2;
				}
				else {
					R[i]=b;
					b-=2;
				}
			}
			R[x]=a;
			R[y]=b;
			
			
		}
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
