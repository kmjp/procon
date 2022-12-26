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
int A[202020],B[202020];
vector<int> R[202020];
int vis[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	queue<int> Q;
	FOR(i,N) {
		cin>>x>>y;
		x--;
		y--;
		if(i==x||i==y) {
			vis[i]=1;
			Q.push(i);
		}
		R[x].push_back(i);
		R[y].push_back(i);
		
	}
	
	vector<int> ret;
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		ret.push_back(x+1);
		FORR(e,R[x]) if(vis[e]==0) {
			vis[e]=1;
			Q.push(e);
		}
	}
	if(ret.size()<N) {
		cout<<-1<<endl;
	}
	else {
		reverse(ALL(ret));
		FORR(r,ret) cout<<r<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
