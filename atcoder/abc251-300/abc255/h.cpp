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


ll N,Q;
ll D[202020],L[202020],R[202020];
const ll mo=998244353;

__int128 hoge(__int128 L, __int128 R) {
	__int128 ret=(L+R-1)*(R-L)/2%mo;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	map<ll,ll> ev;
	ev[0]=ev[1LL<<60]=0;
	
	FOR(i,Q) {
		cin>>D[i]>>L[i]>>R[i];
		
		R[i]++;
		auto it=ev.lower_bound(L[i]+1);
		it--;
		ev[L[i]]=it->second;
		it=ev.lower_bound(R[i]+1);
		it--;
		ev[R[i]]=it->second;
		
		__int128 ret=0;
		while(1) {
			it=ev.lower_bound(L[i]);
			ll cur=it->first;
			ll d=it->second;
			if(cur>=R[i]) break;
			ll nex=next(it)->first;
			ev.erase(it);
			(ret+=hoge(cur,nex)%mo*(D[i]-d))%=mo;
		}
		ev[L[i]]=D[i];
		cout<<(ll)ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
