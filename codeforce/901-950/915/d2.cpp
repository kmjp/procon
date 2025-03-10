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

int T,N,P[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;
int R[1010101];
int C[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
			R[P[i]]=i;
			C[i]=0;
		}
		int m=-1;
		FOR(i,N) {
			m=max(m,R[i]);
			C[m]++;
		}
		ll sum=0;
		ll ma=0;
		map<ll,ll> M;
		FOR(i,N) {
			if(i) C[i]+=C[i-1];
			M[C[i]]++;
			sum+=C[i];
		}
		ma=sum;
		FOR(i,N) {
			x=P[i];
			while(M.rbegin()->first>x) {
				sum-=(M.rbegin()->first-x)*M.rbegin()->second;
				M[x]+=M.rbegin()->second;
				M.erase(M.rbegin()->first);
			}
			M[N]++;
			sum+=N;
			ma=max(ma,sum);
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
