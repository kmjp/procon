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

int N,W;

ll SW[101][40202];
ll SP[101][40202];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) FOR(x,40201) SW[i][x]=-1LL<<30;
	SW[0][10000]=0;
	SP[0][10000]=1;
	FOR(i,N) {
		int v,w;
		cin>>v>>w;
		FOR(x,40000) {
			if(x+w>=0&&x+w<=40000) {
				if(SW[i+1][x+w]<SW[i][x]+v) SW[i+1][x+w]=SW[i][x]+v, SP[i+1][x+w]=0;
				if(SW[i+1][x+w]==SW[i][x]+v) (SP[i+1][x+w]+=SP[i][x])%=mo;
			}
			if(SW[i+1][x]<SW[i][x]) SW[i+1][x]=SW[i][x], SP[i+1][x]=0;
			if(SW[i+1][x]==SW[i][x]) (SP[i+1][x]+=SP[i][x])%=mo;
		}
	}
	int best=-1<<30;
	ll pat=0;
	for(i=0;i<=W+10000;i++) {
		if(SW[N][i]>best) best=SW[N][i],pat=0;
		if(SW[N][i]==best) pat+=SP[N][i];
	}
	cout<<best<<" "<<pat%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
