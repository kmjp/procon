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
ll L,R,A[303030],S[303030];
vector<ll> Ss;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	Ss.push_back(0);
	Ss.push_back(L);
	Ss.push_back(R+1);
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		Ss.push_back(S[i+1]);
		Ss.push_back(S[i+1]+L);
		Ss.push_back(S[i+1]+R+1);
	}
	sort(ALL(Ss));
	Ss.erase(unique(ALL(Ss)),Ss.end());
	
	ll ret=0;
	for(i=N;i>=0;i--) {
		x=lower_bound(ALL(Ss),S[i])-Ss.begin();
		int l=lower_bound(ALL(Ss),S[i]+L)-Ss.begin();
		int r=lower_bound(ALL(Ss),S[i]+R+1)-Ss.begin();
		ret+=bt(r-1)-bt(l-1);
		bt.add(x,1);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
