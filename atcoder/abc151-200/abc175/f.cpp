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
string S[55];
ll C[55];

map<string,ll> cost[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>C[i];
		for(j=0;j<=S[i].size();j++) {
			FOR(y,2) {
				string A=S[i].substr(0,j);
				if(y==1&&j==0) continue;
				if(y==1) A.pop_back();
				string B=S[i].substr(j);
				reverse(ALL(A));
				x=min(A.size(),B.size());
				if(B.substr(0,x)==A.substr(0,x)) {
					if(A.size()<B.size()) {
						string D=B.substr(x);
						if(cost[1].count(D)==0) cost[1][D]=1LL<<60;
						cost[1][D]=min(cost[1][D],C[i]);
					}
					else {
						string D=A.substr(x);
						if(cost[0].count(D)==0) cost[0][D]=1LL<<60;
						cost[0][D]=min(cost[0][D],C[i]);
					}
					
				}
			}
		}
	}
	priority_queue<pair<ll,pair<int,string>>> PQ;
	FOR(i,2) FORR(c,cost[i]) {
		PQ.push({-c.second,{i,c.first}});
	}
	
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int type=PQ.top().second.first;
		string cur=PQ.top().second.second;
		PQ.pop();
		if(cost[type][cur]!=co) continue;
		if(cur=="") {
			cout<<co<<endl;
			return;
		}
		
		FOR(i,N) {
			string A;
			string B;
			if(type==1) {
				A=S[i];
				B=cur;
				reverse(ALL(A));
			}
			else {
				A=cur;
				B=S[i];
			}
			x=min(A.size(),B.size());
			if(A.substr(0,x)==B.substr(0,x)) {
				if(A.size()<B.size()) {
					string D=B.substr(x);
					if(cost[1].count(D)==0) cost[1][D]=1LL<<60;
					if(co+C[i]<cost[1][D]) {
						cost[1][D]=co+C[i];
						PQ.push({-cost[1][D],{1,D}});
					}
				}
				else {
					string D=A.substr(x);
					if(cost[0].count(D)==0) cost[0][D]=1LL<<60;
					if(co+C[i]<cost[0][D]) {
						cost[0][D]=co+C[i];
						PQ.push({-cost[0][D],{0,D}});
					}
				}
			}
		}
		
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
