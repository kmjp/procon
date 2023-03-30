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
int A[202020];

ll cur;
multiset<ll> M={-1LL<<30,1<<30};
void add(ll v) {
	auto it=M.lower_bound(v);
	ll a=*it;
	ll b=*--it;
	if(a<1<<30&&b>-1LL<<30) {
		cur-=(a-b)*(a-b);
	}
	if(a<1<<30) cur+=(a-v)*(a-v);
	if(b>-1<<30) cur+=(v-b)*(v-b);
	M.insert(v);
}
void del(ll v) {
	M.erase(M.find(v));
	auto it=M.lower_bound(v);
	ll a=*it;
	ll b=*--it;
	if(a<1<<30) cur-=(a-v)*(a-v);
	if(b>-1<<30) cur-=(v-b)*(v-b);
	if(a<1<<30&&b>-1LL<<30) {
		cur+=(a-b)*(a-b);
	}
}

ll ret[101010];
int L[101010],R[101010];
const int DI=200;
vector<pair<int,int>> ev[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ev[L[i]/DI].push_back({R[i],i});
	}
	int CL=0,CR=0;
	FOR(j,DI) {
		sort(ALL(ev[j]));
		FORR2(r,i,ev[j]) {
			l=L[i];
			while(CL>l) add(A[--CL]);
			while(CR<r) add(A[CR++]);
			while(CL<l) del(A[CL++]);
			while(CR>r) del(A[--CR]);
			ret[i]=cur;
		}
		
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
