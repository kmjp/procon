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

int N,Q;
ll H[202020];

vector<int> add[202020];
int L[202020],R[202020];
vector<int> Qs[202020];
int ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<ll> V;
	FOR(i,N) {
		cin>>H[i];
		H[i]=H[i]*1000000+i;
		V.push_back(H[i]);
	}
	set<int> S={-1};
	sort(ALL(V));
	reverse(ALL(V));
	FORR(v,V) {
		v%=1000000;
		S.insert(v);
		auto it=S.find(v);
		int pre=*--it;
		if(pre==-1) pre=0;
		add[pre].push_back(v);
	}
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		Qs[L[i]].push_back(i);
	}
	FOR(i,N) {
		FORR(a,add[i]) bt.add(0,1),bt.add(a,-1);
		FORR(e,Qs[i]) ret[e]=bt(R[e]);
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
