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

int N,X;
int L[50505];
int V[50505];

bool cmp2(pair<int,int> a,pair<int,int> b) {
	return 1LL*a.first*b.second*(b.second+1)<1LL*b.first*a.second*(a.second+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>V[i];
	
	auto cmp = [](pair<int,int>& a,pair<int,int>& b) -> bool {return (ll)a.first*b.second*(b.second+1)<(ll)b.first*a.second*(a.second+1);};
	priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> PQ(cmp);
	FOR(i,N) {
		PQ.push({L[i],V[i]});
	}
	
	while(X) {
		auto a=PQ.top();
		PQ.pop();
		if(X>1000000) {
			a.second+=5;
			X-=5;
		}
		else {
			a.second++;
			X--;
		}
		PQ.push(a);
	}
	double ret=0;
	while(PQ.size()) {
		auto a=PQ.top();
		PQ.pop();
		ret+=a.first*1.0/a.second;
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
