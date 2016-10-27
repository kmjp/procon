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

int T;
int N;
int A[50505];
int B[50505];
int Z[50505];
int R[50505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> AA;
		vector<pair<int,int>> BB;
		FOR(i,N) cin>>x, AA.push_back({x,i});
		FOR(i,N) cin>>x, BB.push_back({x,i});
		sort(ALL(AA));
		sort(ALL(BB));
		
		FOR(i,N/2) {
			if(AA[i].first>=BB[i+N/2].first) {
				_P("-1\n");
				goto out;
			}
			if(AA[i+N/2].first<=BB[i].first) {
				_P("-1\n");
				goto out;
			}
			R[AA[i].second]=BB[i+N/2].second+1;
			R[AA[i+N/2].second]=BB[i].second+1;
		}
		
		FOR(i,N) _P("%d%c",R[i],(i==N-1)?'\n':' ');
		out:
		;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
