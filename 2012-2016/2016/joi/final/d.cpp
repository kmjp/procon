#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
string S;

vector<pair<ll,ll>> C;

map<pair<ll,ll>,vector<pair<ll,ll>>> V;

ll intersect(vector<pair<ll,ll>> A,vector<pair<ll,ll>> B,vector<pair<ll,ll>> C,vector<pair<ll,ll>> D) {
	ll ret=0;
	ll a=0,b=0,c=0,d=0;
	while(1) {
		if(a>=A.size()) break;
		if(b>=B.size()) break;
		if(c>=C.size()) break;
		if(d>=D.size()) break;
		ll L=max({A[a].first,B[b].first,C[c].first,D[d].first});
		ll R=min({A[a].second,B[b].second,C[c].second,D[d].second});
		ret+=max(0LL,R-L);
		if(A[a].second==min({A[a].second,B[b].second,C[c].second,D[d].second})) a++;
		else if(B[b].second==min({A[a].second,B[b].second,C[c].second,D[d].second})) b++;
		else if(C[c].second==min({A[a].second,B[b].second,C[c].second,D[d].second})) c++;
		else d++;
		
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	C.push_back({0,0});
	FORR(c,S) {
		C.push_back(C.back());
		if(c=='E') C.back().first++;
		if(c=='W') C.back().first--;
		if(c=='N') C.back().second--;
		if(c=='S') C.back().second++;
	}
	
	if(C.back()==make_pair(0LL,0LL)) {
		set<pair<int,int>> SS;
		FORR(c,C) SS.insert(c);
		int ret=0;
		FORR(s,SS) {
			if(SS.count({s.first,s.second+1})&&SS.count({s.first+1,s.second})&&SS.count({s.first+1,s.second+1})) ret++;
		}
		cout<<ret<<endl;
		return;
	}
	if(C.back().first==0) {
		FORR(c,C) swap(c.first,c.second);
	}
	if(C.back().first<0) {
		FORR(c,C) c.first=-c.first;
	}
	if(C.back().second<0) {
		FORR(c,C) c.second=-c.second;
	}
	ll DX=C.back().first;
	ll DY=C.back().second;
	C.erase(C.begin());
	V[{0,0}].push_back({0,1});
	V[{DX,DY}].push_back({-1,0});
	FORR(c,C) {
		x=c.first;
		y=c.second;
		ll px=x/DX;
		ll qx=x%DX;
		if(qx<0) px--,qx+=DX;
		V[{qx,y-DY*px}].push_back({px,px+K});
		V[{qx+DX,y-DY*px+DY}].push_back({px-1,px+K-1});
	}
	FORR(v,V) {
		vector<pair<ll,ll>> R;
		sort(ALL(v.second));
		FORR(e,v.second) {
			if(R.empty() || R.back().second<e.first) {
				R.push_back(e);
			}
			else {
				R.back().second=max(e.second,R.back().second);
			}
		}
		V[v.first]=R;
	}
	ll ret=0;
	FORR(v,V) if(v.first.first<DX) {
		if(V.count({v.first.first+1,v.first.second}) && V.count({v.first.first,v.first.second+1}) && V.count({v.first.first+1,v.first.second+1})) {
			ret+=intersect(v.second,V[{v.first.first+1,v.first.second}],V[{v.first.first,v.first.second+1}],V[{v.first.first+1,v.first.second+1}]);
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
