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

int R,N;
ll S[2020202];
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>N;
	FOR(i,N) {
		cin>>x;
		S[x]++;
		S[R+x]++;
	}
	FOR(i,2*R+1) S[i+1]+=S[i];
	cin>>Q;
	while(Q--) {
		int X,Y;
		cin>>X>>Y;
		x=(Y-X)/R;
		ll ret=1LL*x*N;
		Y-=x*R;
		
		x=X/R;
		X-=x*R;
		Y-=x*R;
		ret+=S[Y];
		if(X) ret-=S[X-1];
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
