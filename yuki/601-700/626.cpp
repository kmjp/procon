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

int N;
ll W;
pair<ll,ll> P[5050];
ll ma=0;
pair<ll,ll> Q[2][150505];

bool cmp(pair<ll,ll> L,pair<ll,ll> R) {
	return L.first*1.0/L.second>R.first*1.0/R.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N,cmp);
	
	vector<pair<ll,ll>> V;
	V.push_back({0,0});
	
	FOR(i,N) {
		x=y=0;
		FORR(e,V) {
			Q[0][x++]=e;
			if(e.second+P[i].second<=W) {
				Q[1][y++]={e.first+P[i].first,e.second+P[i].second};
			}
		}
		V.clear();
		int x2=0,y2=0;
		while(V.size()<70000) {
			if(x2==x&&y2==y) break;
			if(x2==x) j=1;
			else if(y2==y) j=0;
			else {
				if(Q[0][x2].first>Q[1][y2].first) j=0;
				if(Q[0][x2].first<Q[1][y2].first) j=1;
				if(Q[0][x2].first==Q[1][y2].first) {
					if(Q[0][x2].second<Q[1][y2].second) j=0;
					else j=1;
				}
			}
			if(j==0) V.push_back(Q[0][x2++]);
			else V.push_back(Q[1][y2++]);
		}
		
	}
	cout<<V[0].first<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
