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

int T,N;
int A[202020],B[202020];
int S[404040];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		vector<int> Xs={-1<<30};
		cin>>N;
		FOR(i,N) {
			cin>>A[i]>>B[i];
			Xs.push_back(A[i]);
			Xs.push_back(B[i]);
		}
		FOR(i,2*N+2) S[i]=0;
		sort(ALL(Xs));
		vector<pair<int,int>> ev;
		FOR(i,N) {
			A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
			B[i]=lower_bound(ALL(Xs),B[i])-Xs.begin();
			ev.push_back({B[i],i});
		}
		sort(ALL(ev));
		reverse(ALL(ev));
		ll ret=0;
		FORR2(a,i,ev) {
			ret+=bt(A[i]);
			bt.add(A[i],1);
		}
		FOR(i,N) bt.add(A[i],-1);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
