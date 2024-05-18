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

int T,N,A[202020],B[202020];

multiset<pair<ll,ll>> X,Y;
vector<pair<ll,ll>> ret;

int dfs(multiset<pair<ll,ll>>& A,multiset<pair<ll,ll>>& B,pair<ll,ll> p) {
	if(p.first<0||p.second<0) return 0;
	if(A.empty()) {
		return 1;
	}
	auto it=A.lower_bound({p.first,0});
	int x=0;
	if(it!=A.end()&&it->first==p.first) {
		auto q=*it;
		A.erase(it);
		B.erase(B.find({q.second,q.first}));
		x=dfs(A,B,{p.first,p.second-q.second});
		A.insert(q);
		B.insert({q.second,q.first});
	}
	it=B.lower_bound({p.second,0});
	if(x==0&&it!=B.end()&&it->first==p.second) {
		auto q=*it;
		B.erase(it);
		A.erase(A.find({q.second,q.first}));
		x|=dfs(A,B,{p.first-q.second,p.second});
		B.insert(q);
		A.insert({q.second,q.first});
	}
	return x;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		X.clear();
		Y.clear();
		int maX=0,maY=0;
		ll sum=0;
		FOR(i,N) {
			cin>>A[i]>>B[i];
			X.insert({A[i],B[i]});
			Y.insert({B[i],A[i]});
			maX=max(maX,B[i]);
			maY=max(maY,A[i]);
			sum+=1LL*A[i]*B[i];
			
		}
		
		ret.clear();
		if(sum%maX==0&&dfs(X,Y,{sum/maX,maX})) ret.push_back({sum/maX,maX});
		if(sum%maY==0&&dfs(X,Y,{maY,sum/maY})) ret.push_back({maY,sum/maY});
		sort(ALL(ret));
		ret.erase(unique(ALL(ret)),ret.end());
		cout<<ret.size()<<endl;
		FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
