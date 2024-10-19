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

//以下は実は同じ。分割を90度見方を変えると良い。
ll M[4040][4040];   //M(x,y):= xを最大値y以下で分割する
ll L[4040][4040];   //L(x,y):= xをy個以下に分割

const ll mo=998244353;

int T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4010) M[0][i]=1;
	for(x=1;x<=4010;x++) {
		for(y=1;y<=4010;y++) {
			(M[x][y]=M[x][y-1]+(x>=y?M[x-y][y]:0))%=mo;
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>i>>x>>y;
		cout<<M[x][y]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
