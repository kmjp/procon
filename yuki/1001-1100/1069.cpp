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

int N,M,K;
int S,T;
int X[202020],Y[202020];
vector<int> E[202020];
double D[2020];
vector<int> P[2020];

pair<double,vector<int>> hoge(int start,set<pair<int,int>> NG,vector<int> pref,double prel) {
	int i;
	
	FOR(i,N) D[i]=1e9, P[i].clear();
	FORR(p,pref) D[p]=-1;
	D[start]=prel;
	
	P[start]=pref;
	P[start].push_back(start);
	priority_queue<pair<double,int>> Q;
	Q.push({-prel,start});
	while(Q.size()) {
		double co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(D[cur]!=co) continue;
		FORR(e,E[cur]) {
			if(NG.count({e,cur})) continue;
			if(NG.count({cur,e})) continue;
			if(count(ALL(P[cur]),e)) continue;
			double d=co+hypot(X[cur]-X[e],Y[cur]-Y[e]);
			if(D[e]>d) {
				D[e]=d;
				P[e]=P[cur];
				P[e].push_back(e);
				Q.push({-d,e});
			}
		}
	}
	
	return {D[T],P[T]};
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S>>T;
	S--,T--;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	vector<pair<double,vector<int>>> ret;
	vector<pair<double,vector<int>>> cand;
	set<pair<int,int>> NG;
	ret.push_back(hoge(S,NG,vector<int>(),0));
	while(ret.size()<K) {
		double sum=0;
		vector<int> pre;
		FOR(x,ret.back().second.size()-1) {
			if(x) {
				pre.push_back(ret.back().second[x-1]);
				sum+=hypot(X[ret.back().second[x-1]]-X[ret.back().second[x]],Y[ret.back().second[x-1]]-Y[ret.back().second[x]]);
			}
			NG.clear();
			FOR(i,ret.size()) {
				if(ret[i].second.size()<x+2) continue;
				FOR(y,x+1) if(ret[i].second[y]!=ret.back().second[y]) break;
				if(y!=x+1) continue;
				NG.insert({ret[i].second[x],ret[i].second[x+1]});
			}
			
			cand.push_back(hoge(ret.back().second[x],NG,pre,sum));
		}
		
		
		
		sort(ALL(cand));
		while(cand.size()) {
			int ng=0;
			FORR(r,ret) if(r.second==cand[0].second) ng=1;
			if(ng==0) break;
			cand.erase(cand.begin());
		}
		if(cand.empty()) break;
		if(cand[0].first>1e8) break;
		ret.push_back(cand[0]);
		cand.erase(cand.begin());
	}
	
	FOR(i,K) {
		if(i<ret.size()) {
			_P("%.12lf\n",ret[i].first);
		}
		else {
			_P("-1\n");
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
