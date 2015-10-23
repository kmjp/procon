#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll S[30];
string T;
int L;
vector<int> V[26];
int num[26];

struct comp {
	bool operator()(const pair<pair<ll,ll>,pair<ll,ll>> a, const pair<pair<ll,ll>,pair<ll,ll>> b) const {
		return a.first.first*b.first.second < a.first.second*b.first.first;
	}
};

__int128 hoge(ll s,vector<int> p) {
	if(p.empty()) return 1;
	sort(ALL(p));
	
	__int128 ss=s;
	if(s>10000000) {
		if(p.size()==1) {
			if(p[0]==1) return s;
			if(p[0]==2) return ss*(ss-1)/2;
		}
		if(p.size()==2 && p[0]==1 && p[1]==1) return (ss/2)*(ss-ss/2);
		return 1LL<<62;
	}
	
	__int128 pat=1;
	priority_queue<pair<pair<ll,ll>,pair<ll,ll>>,vector<pair<pair<ll,ll>,pair<ll,ll>>>,comp> Q;
	FORR(r,p) s-=r, Q.push(make_pair(make_pair(r+1,1),make_pair(r,r)));
	
	while(s--) {
		auto r=Q.top();
		Q.pop();
		
		pat=pat * r.first.first / r.first.second;
		if(pat>=1LL<<62) return pat;
		
		r.second.first++;
		Q.push(make_pair(make_pair(r.second.first+1,r.second.first+1-r.second.second),r.second));
	}
	return pat;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,26) cin>>S[i];
	cin>>T;
	L=T.size();
	
	V[T[0]-'a'].push_back(1);
	FOR(i,L-1) {
		if(T[i]==T[i+1]) V[T[i+1]-'a'].back()++;
		else V[T[i+1]-'a'].push_back(1);
	}
	FOR(i,L) num[T[i]-'a']++;
	
	__int128 ret=1;
	FOR(i,26) if(num[i]>S[i]) return _P("0\n");
	FOR(i,26) {
		__int128 pat=hoge(S[i],V[i]);
		if(pat>=1LL<<62) return _P("hel\n");
		ret*=pat;
		if(ret>=1LL<<62) return _P("hel\n");
	}
	cout<<(ll)ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
