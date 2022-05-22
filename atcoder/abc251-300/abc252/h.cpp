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


int N,C;
vector<ll> V[70];
ll K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C>>K;
	FOR(i,N) {
		ll v;
		cin>>x>>v;
		V[x-1].push_back(v);
	}
	
	vector<ll> A,B;
	A={1},B={1};
	vector<pair<int,int>> cand;
	FOR(i,C) cand.push_back({-V[i].size(),i});
	sort(ALL(cand));
	FORR2(a,i,cand) {
		if(A.size()>B.size()) swap(A,B);
		vector<ll> D;
		FORR(a,A) FORR(v,V[i]) D.push_back(a^v);
		swap(A,D);
	}
	
	ll ret=0;
	vector<pair<vector<ll>,vector<ll>>> D={{A,B}};
	
	for(i=59;i>=0;i--) {
		vector<pair<array<vector<ll>,2>,array<vector<ll>,2>>> nex;
		ll num=0;
		FORR2(a,b,D) {
			array<vector<ll>,2> na,nb;
			FORR(v,a) na[(v>>i)&1].push_back(v);
			FORR(v,b) nb[(v>>i)&1].push_back(v);
			nex.push_back(make_pair(na,nb));
			num+=na[0].size()*nb[1].size()+na[1].size()*nb[0].size();
		}
		
		D.clear();
		if(num<K) {
			//‚±‚Ìbit‚ª1‚¾‚ÆðŒ‚ð–ž‚½‚¹‚È‚¢
			K-=num;
			FORR2(a,b,nex) {
				if(a[0].size()&&b[0].size()) D.push_back({a[0],b[0]});
				if(a[1].size()&&b[1].size()) D.push_back({a[1],b[1]});
			}
		}
		else {
			//‚±‚Ìbit‚ª1‚Æ‚È‚é‚à‚Ì‚Ì’†‚É‰ð‚ª‚ ‚é
			ret+=1LL<<i;
			FORR2(a,b,nex) {
				if(a[0].size()&&b[1].size()) D.push_back({a[0],b[1]});
				if(a[1].size()&&b[0].size()) D.push_back({a[1],b[0]});
			}
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
