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

int T,N,Q;
int A[1010101],re[1010101];
int L[1010101],R[1010101];
vector<int> ev[1010101];
ll ret[1010101];
ll M[1<<20];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,21> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			cin>>A[i+1];
			re[A[i+1]]=i+1;
			ev[i+1].clear();
			bt.add(i+1,-bt(i+1));
		}
		FOR(i,Q) {
			cin>>L[i]>>R[i];
			ev[L[i]].push_back(i);
		}
		for(i=1;i<=N;i++) {
			bt.add(re[i],1);
			ll sum=bt(re[i])-bt(re[i]-1);
			for(j=2*i;j<=N;j+=i) if(re[j]>re[i]) bt.add(re[j],sum);
		}
		for(i=1;i<=N;i++) {
			FORR(e,ev[i]) {
				ret[e]=bt(R[e])-bt(L[e]-1);
			}
			x=A[i];
			M[x]=bt(i)-bt(i-1);
			for(y=x;y<=N;y+=x) {
				ll del=M[y];
				M[y]=0;
				bt.add(re[y],-del);
				for(j=2*y;j<=N;j+=y) if(re[j]>re[y]) M[j]+=del;
			}
		}
		FOR(i,Q) cout<<ret[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
