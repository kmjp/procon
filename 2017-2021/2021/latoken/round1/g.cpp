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
int X[1010100],Y[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<ll,ll>> ev;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		ev.push_back({x+y,y-x});
	}
	sort(ALL(ev));
	ll ret=0;
	priority_queue<ll,vector<ll>,greater<ll>> U;
	priority_queue<ll,vector<ll>,less<ll>> D;
	U.push(0);
	D.push(0);
	FORR2(x,y,ev) {
		// 傾きがマイナスとなるy座標の最大値からの距離と、傾きがプラスとなるy座標の最小値からの距離
		ret+=max({0LL,D.top()-x-y,y-(U.top()+x)});
		if(U.empty()||U.top()+x>y) {
			//追加は傾きが0かマイナスのところ
			D.push(x+y);
			D.push(x+y);
			U.push(D.top()-2*x);
			D.pop();
		}
		else {
			//追加は傾きがプラスのところ
			U.push(y-x);
			U.push(y-x);
			D.push(U.top()+2*x);
			U.pop();
		}
		
	}
	cout<<ret/2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
