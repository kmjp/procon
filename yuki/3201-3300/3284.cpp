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
ll S[505050];
int Q;
ll T[505050],F[505050];

ll small[1010];
ll big[501101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> Ss;
	FOR(i,N) {
		cin>>S[i];
		if(S[i]>1000) Ss.push_back(S[i]);
	}
	sort(ALL(Ss));
	Ss.erase(unique(ALL(Ss)),Ss.end());
	
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>F[i];
		if(i&&(T[i-1]+F[i-1])>=T[i]) {
			F[i-1]+=F[i];
			i--;
			Q--;
		}
	}
	ll FS=0;
	FOR(i,Q) {
		FS+=F[i];
		for(j=1;j<=1000;j++) small[j]+=F[i]/j;
		for(ll step=1;step*1000<=F[i];step++) {
			ll add=F[i]/step;
			big[0]++;
			x=lower_bound(ALL(Ss),add+1)-Ss.begin();
			big[x]--;
		}
	}
	for(i=1;i<Ss.size();i++) big[i]+=big[i-1];
	
	FOR(i,N) {
		if(S[i]<=1000) {
			cout<<small[S[i]]<<endl;
		}
		else {
			x=lower_bound(ALL(Ss),S[i])-Ss.begin();
			cout<<big[x]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
