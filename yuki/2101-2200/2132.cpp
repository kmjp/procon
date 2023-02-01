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
ll N,X;
const ll mo=998244353;

ll win[55][2][2];

int hoge(int cur,int p1,int p2) {
	if(win[cur][p1][p2]>=0) return win[cur][p1][p2];
	win[cur][p1][p2]=0;
	if(cur&&hoge(cur-1,p2,0)==0) win[cur][p1][p2]=1;
	if(cur>=X&&p1==0&&hoge(cur-X,p2,1)==0) win[cur][p1][p2]=1;
	return win[cur][p1][p2];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		
		MINUS(win);
		/*
		int ret1=0;
		for(i=1;i<=N;i++) {
			//cout<<i<<" "<<X<<" "<<hoge(i,0,0)<<endl;
			ret1+=hoge(i,0,0);
		}
		cout<<ret1<<endl;
		*/
		ll ret;
		if(X%2==1) {
			ret=(N+1)/2;
		}
		else {
			if(N<X) {
				ret=(N+1)/2;
			}
			else if(N==X) {
				ret=N/2+1;
			}
			else {
				ret=X/2+1;
				N-=X;
				ret+=N/(X+3)*(X/2+2);
				N%=X+3;
				ret+=N/2;
			}
		}
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
