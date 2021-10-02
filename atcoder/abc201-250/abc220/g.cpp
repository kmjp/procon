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
int X[1010],Y[1010];
ll C[1010];
map<pair<ll,ll>,ll> V,H;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
	}
	vector<pair<pair<ll,ll>,pair<int,int>>> V;
	FOR(y,N) FOR(x,y) {
		ll dx=(X[y]-X[x]);
		ll dy=Y[y]-Y[x];
		
		ll g=__gcd(abs(dx),abs(dy));
		dx/=g;
		dy/=g;
		if(dx<0) dx=-dx, dy=-dy;
		if(dx==0&&dy<0) dy=-dy;
		ll c=dx*(X[y]+X[x])+dy*(Y[y]+Y[x]);
		
		ll k=(dx<<32)+dy;
		V.push_back({{k,c},{x,y}});
	}
	sort(ALL(V));
	ll ret=-1;
	pair<ll,ll> pre={-1LL<<63,-1LL<<63};
	map<pair<int,int>,ll> memo;
	FORR2(v,a,V) {
		//cout<<v.first<<" "<<v.second<<"  "<<a.first<<" "<<a.second<<endl;
		if(v!=pre) {
			ll ma=-1LL<<60;
			FORR2(a,b,memo) {
				//cout<<"#"<<a.first<<" "<<a.second<<" "<<b<<endl;
				ret=max(ret,ma+b);
				ma=max(ma,b);
			}
			memo.clear();
		}
		pre=v;
		x=X[a.first]+X[a.second];
		y=Y[a.first]+Y[a.second];
		memo[{x,y}]=max(memo[{x,y}],C[a.first]+C[a.second]);
	}
	ll ma=-1LL<<60;
	FORR2(a,b,memo) {
		ret=max(ret,ma+b);
		ma=max(ma,b);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
