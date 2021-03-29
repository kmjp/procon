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
vector<int> X[202020];

ll from[2];
ll to[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[y].push_back(x);
	}
	X[0].push_back(0);
	int pre=0;
	for(i=1;i<=N;i++) if(X[i].size()) {
		sort(ALL(X[i]));
		to[0]=min(from[0]+abs(X[i].back()-X[pre][0])+abs(X[i][0]-X[i].back()),from[1]+abs(X[i].back()-X[pre].back())+abs(X[i][0]-X[i].back()));
		to[1]=min(from[0]+abs(X[i][0]-X[pre][0])+abs(X[i][0]-X[i].back()),from[1]+abs(X[i][0]-X[pre].back())+abs(X[i][0]-X[i].back()));
		swap(from,to);
		pre=i;
	}
	
	cout<<min(from[0]+abs(X[pre][0]),from[1]+abs(X[pre].back()))<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
