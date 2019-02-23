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

int ptr;
string S;
ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	vector<pair<ll,ll>> V;
	FORR(c,S) {
		if(c>='0' && c<='9') {
			if(V.empty() || V.back().first<0) V.push_back({0,-1});
			V.back().first=(V.back().first*10+c-'0')%mo;
		}
		else if(c==')') {
			pair<ll,ll> a=V[V.size()-3];
			pair<ll,ll> b=V[V.size()-1];
			pair<ll,ll> d;
			if(V[V.size()-2].second==',') {
				assert(a.second==-1);
				assert(b.second==-1);
				d={a.first,b.first};
			}
			else {
				if(a.second==-1 && b.second==-1) {
					d={a.first*b.first%mo,-1};
				}
				if(a.second!=-1 && b.second!=-1) {
					d={(a.first*b.first+a.second*b.second)%mo,-1};
				}
				if(a.second==-1 && b.second!=-1) {
					d={a.first*b.first%mo, a.first*b.second%mo};
				}
				if(a.second!=-1 && b.second==-1) {
					d={a.first*b.first%mo, a.second*b.first%mo};
				}
			}
			V.pop_back();
			V.pop_back();
			V.pop_back();
			V.pop_back();
			V.push_back(d);
		}
		else {
			V.push_back({-1,c});
		}
	}
	assert(V.size()==1);
	cout<<V[0].first<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
