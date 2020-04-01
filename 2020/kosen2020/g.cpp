#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[101010],B[101010],S[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y;;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i]=A[i];
		if(i) S[i]+=S[i-1];
	}
	FOR(i,N) {
		cin>>B[i];
	}
	set<pair<ll,int>> C;
	FOR(i,N) {
		if(S[i]<=B[i]) {
			bt.add(i,1);
		}
		else {
			C.insert({S[i]-B[i],i});
		}
	}
	
	ll ret=0;
	ll s=0;
	FOR(i,N) {
		x=lower_bound(S,S+N,B[i]+(i?S[i-1]:0))-S;
		x=max(x,i);
		ret+=bt(N)-bt(x-1);
		s+=A[i];
		while(C.size() && C.begin()->first<=s) {
			bt.add(C.begin()->second,1);
			C.erase(C.begin());
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
