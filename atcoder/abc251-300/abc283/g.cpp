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
ll L,R;
ll A[202020];

vector<ll> add(vector<ll> T,ll v) {
	FORR(t,T) v=min(v,t^v);
	if(v) T.push_back(v);
	//sort(ALL(T)); reverse(ALL(T));
	return T;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	vector<ll> V(N),W;
	FOR(i,N) {
		cin>>V[i];
		W=add(W,V[i]);
	}
	
	sort(ALL(W));
	for(ll v=L-1;v<R;v++) {
		ll c=v;
		ll cur=0;
		for(x=W.size()-1;x>=0;x--) {
			if((cur^W[x])>cur) {
				if(c>=1LL<<x) {
					c-=1LL<<x;
					cur^=W[x];
				}
			}
			else {
				if(c>=1LL<<x) {
					c-=1LL<<x;
				}
				else {
					cur^=W[x];
				}
			}
			
		}
		
		cout<<cur<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
