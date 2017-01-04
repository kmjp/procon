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

int H,W,N;
int X[303030],Y[303030];
int ma;

void dfs(int T,int B,vector<pair<int,int>>& P) {
	if(T>=B || (B-T)+W<=ma) return;
	if(P.empty()) {
		ma=(B-T)+W;
		return;
	}
	if(P.size()==1) {
		ma=max(ma,max(B-P[0].second,P[0].second-T)+W);
		ma=max(ma,max(P[0].first,W-P[0].first)+B-T);
		return;
	}
	
	vector<int> Y;
	FORR(r,P) Y.push_back(r.second);
	sort(ALL(Y));
	int my=Y[Y.size()/2], x;
	vector<pair<int,int>> PT,PB;
	
	
	FORR(r,P) {
		if(r.second<my) PT.push_back(r);
		if(r.second>my) PB.push_back(r);
	}
	dfs(T,my,PT);
	dfs(my,B,PB);
	
	vector<pair<int,pair<int,int>>> LL,RR;
	vector<int> RM;
	int mid = lower_bound(ALL(P),make_pair(W/2,0))-P.begin();
	
	int CT=T,CB=B;
	for(x=mid-1;x>=0 && CT!=CB;x--) {
		while(LL.size() && LL.back().second==make_pair(CT,CB)) LL.pop_back();
		LL.push_back({P[x].first,{CT,CB}});
		if(P[x].second<=my && P[x].second>CT) CT=P[x].second;
		if(P[x].second>=my && P[x].second<CB) CB=P[x].second;
	}
	if(CT!=CB) {
		while(LL.size() && LL.back().second==make_pair(CT,CB)) LL.pop_back();
		LL.push_back({0,{CT,CB}});
	}
	
	CT=T,CB=B;
	for(x=mid;x<P.size() && CT!=CB;x++) {
		while(RR.size() && RR.back().second==make_pair(CT,CB)) RR.pop_back(), RM.pop_back();
		RR.push_back({P[x].first,{CT,CB}});
		RM.push_back(CB-CT+P[x].first);
		
		if(P[x].second<=my && P[x].second>CT) CT=P[x].second;
		if(P[x].second>=my && P[x].second<CB) CB=P[x].second;
	}
	if(CT!=CB) {
		while(RR.size() && RR.back().second==make_pair(CT,CB)) RR.pop_back(), RM.pop_back();
		RR.push_back({W,{CT,CB}});
		RM.push_back(CB-CT+W);
	}
	for(x=RM.size()-2;x>=0;x--) RM[x]=max(RM[x],RM[x+1]);
	
	int TL=0, TR=0;
	FORR(l,LL) {
		while(TL<RR.size()-1 && RR[TL+1].second.first<=l.second.first && RR[TL+1].second.second>=l.second.second) TL++;
		while(TR<RR.size() && (RR[TR].second.first<l.second.first || RR[TR].second.second>l.second.second)) TR++;
		
		for(x=TL;x<=min((int)RR.size()-1,TR);x++) {
			auto r=RR[x];
			int dx=r.first-l.first;
			int dy=min(l.second.second,r.second.second)-max(l.second.first,r.second.first);
			if(dy>0) ma=max(ma,dx+dy);
		}
		if(TR<RR.size()) ma=max(ma,RM[TR]-l.first);
		
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	ma=max(W,H)+1;
	
	FOR(j,2) {
		vector<pair<int,int>> P;
		FOR(i,N) P.push_back({X[i],Y[i]});
		sort(ALL(P));
		
		dfs(0,H,P);
		
		swap(W,H);
		FOR(i,N) swap(X[i],Y[i]);
	}
	
	cout<<ma*2<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
