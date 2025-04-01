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

int T;
int N,Q,K;
int B[101010];
int L[202020],R[202020];
int ret[202020];
const int DI=330;
vector<pair<int,int>> ev[DI];

int C[1010101];
int sum;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,11> bt;

void add(int cur,int val) {
	sum+=val;
	C[cur]+=val;
	bt.add(min(1001,K/cur+1),val);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q>>K;
		FOR(i,N) cin>>B[i];
		FOR(i,Q) {
			cin>>L[i]>>R[i];
			L[i]--;
			ev[L[i]/DI].push_back({R[i],i});
		}
		FOR(i,DI) if(ev[i].size()) {
			sort(ALL(ev[i]));
			int CL=DI*i,CR=DI*i;
			
			FORR2(TR,e,ev[i]) {
				int TL=L[e];
				while(CR<TR) add(B[CR++],1);
				while(TL<CL) add(B[--CL],1);
				while(TL>CL) add(B[CL++],-1);
				
				ret[e]=0;
				int num=0;
				for(k=1;k*k<=K;k++) if(C[k]) {
					int nng=bt(k);
					int nok=num;
					if(nng>nok) ret[e]=max(ret[e],(nng-nok+1)/2);
					
					num+=C[k];
					if(num*2>TR-TL) break;
				}
				if(num*2+1<TR-TL) ret[e]=max(ret[e],(TR-TL-num*2)/2);
				
			}
			
			
			while(CL<CR) add(B[CL++],-1);
			ev[i].clear();
			
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
