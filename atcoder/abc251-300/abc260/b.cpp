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

int N,X,Y,Z;
int A[1010],B[1010];
int vis[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>Z;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	
	vector<int> R;
	FOR(i,X) {
		x=-1;
		FOR(j,N) if(vis[j]==0) {
			if(x==-1||A[x]<A[j]) x=j;
		}
		R.push_back(x+1);
		vis[x]=1;
	}
	FOR(i,Y) {
		x=-1;
		FOR(j,N) if(vis[j]==0) {
			if(x==-1||B[x]<B[j]) x=j;
		}
		R.push_back(x+1);
		vis[x]=1;
	}
	FOR(i,Z) {
		x=-1;
		FOR(j,N) if(vis[j]==0) {
			if(x==-1||A[x]+B[x]<A[j]+B[j]) x=j;
		}
		R.push_back(x+1);
		vis[x]=1;
	}
	
	sort(ALL(R));
	FORR(r,R) cout<<r<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
