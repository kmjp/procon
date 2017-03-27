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
vector<pair<int,int>> V;
int A[101010],B[101010];

int ok(int d) {
	deque<int> Q[2];
	int match=0;
	int i;
	FORR(r,V) {
		int id=r.second;
		int cur=r.first;
		FOR(i,2) while(Q[i].size() && Q[i].front() < cur-d) Q[i].pop_front();
		if(Q[id^1].size()) {
			match++;
			Q[id^1].pop_front();
		}
		else {
			Q[id].push_back(cur);
		}
		
		
	}
	return match>=K;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>x, V.push_back({x,0});
	FOR(i,M) cin>>x, V.push_back({x,1});
	sort(ALL(V));
	
	int ret=(1<<30)-1;
	for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret -= 1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
