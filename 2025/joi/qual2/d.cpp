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

int N,M,Q;
ll A[404040],B[404040];
int RA[404040],RB[404040];
vector<ll> ret;

ll score(int x,int y) {
	return max(A[x],A[y])+max(B[x],B[y]);
}
ll id(int a,int b) {
	if(a>b) swap(a,b);
	return 1000000LL*a+b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	vector<pair<ll,int>> As,Bs;
	FOR(i,N) {
		cin>>A[i];
		A[i]=(A[i]*1000000)+i;
		As.push_back({A[i],i});
	}
	FOR(i,N) {
		cin>>B[i];
		B[i]=(B[i]*1000000)+i;
		Bs.push_back({B[i],i});
	}
	sort(ALL(As));
	sort(ALL(Bs));
	reverse(ALL(As));
	reverse(ALL(Bs));
	FOR(i,N) RA[As[i].second]=i;
	FOR(i,N) RB[Bs[i].second]=i;
	
	set<pair<int,int>> NG,did;
	FOR(i,M) {
		cin>>x>>y;
		NG.insert({x-1,y-1});
	}
	priority_queue<pair<ll,ll>> PQ;
	PQ.push({score(As[0].second,Bs[0].second),id(As[0].second,Bs[0].second)});
	while(PQ.size()&&ret.size()<=400000) {
		ll sc=PQ.top().first;
		x=PQ.top().second/1000000;
		y=PQ.top().second%1000000;
		PQ.pop();
		if(x!=y&&NG.count({x,y})==0) {
			ret.push_back(sc);
			NG.insert({x,y});
		}
		if(did.count({x,y})) continue;
		did.insert({x,y});
		int xa=-1,xb=-1,ya=-1,yb=-1;
		if(RA[x]!=N-1) xa=As[RA[x]+1].second;
		if(RB[x]!=N-1) xb=Bs[RB[x]+1].second;
		if(RA[y]!=N-1) ya=As[RA[y]+1].second;
		if(RB[y]!=N-1) yb=Bs[RB[y]+1].second;
		if(xa!=-1) PQ.push({score(xa,y),id(xa,y)});
		if(xb!=-1) PQ.push({score(xb,y),id(xb,y)});
		if(ya!=-1) PQ.push({score(ya,x),id(ya,x)});
		if(yb!=-1) PQ.push({score(yb,x),id(yb,x)});
	}
	while(Q--) {
		cin>>x;
		cout<<ret[x-1]/1000000<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
