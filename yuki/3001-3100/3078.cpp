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
ll A[1<<17];
vector<ll> As[18][1<<17];
vector<ll> Ss[18][1<<17];
int Q;

ll hoge(int v,ll X) {
	ll ret=0;
	int cur=0;
	int i;
	for(i=17;i>=0;i--) if(cur+(1<<i)<=v) {
		cur+=(1<<i);
		ll c=cur>>i;
		int x=lower_bound(ALL(As[i][c]),X)-As[i][c].begin();
		ret+=x*X-Ss[i][c][x];
		ret+=Ss[i][c].back()-Ss[i][c][x]-X*((1<<i)-x);
		
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i+1];
	FOR(i,18) {
		FOR(j,1<<17) if(j) {
			As[i][((j-1)>>i)+1].push_back(A[j]);
		}
		FOR(j,1<<17) if(As[i][j].size()) {
			sort(ALL(As[i][j]));
			Ss[i][j].push_back(0);
			FORR(a,As[i][j]) Ss[i][j].push_back(Ss[i][j].back()+a);
		}
	}
	
	while(Q--) {
		int L,R;
		ll X;
		cin>>L>>R>>X;
		cout<<hoge(R,X)-hoge(L-1,X)<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
