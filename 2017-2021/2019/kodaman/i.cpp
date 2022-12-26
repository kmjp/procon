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
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int sum=0;
		set<pair<int,int>> M;
		queue<int> S;
		FOR(i,N) {
			cin>>A[i+1];
			sum+=A[i+1];
			if(A[i+1]==1) S.push(i+1);
			else M.insert({A[i+1],i+1});
		}
		if(sum!=2*(N-1)) {
			cout<<"invalid"<<endl;
			continue;
		}
		vector<pair<int,int>> R;
		while(M.size()) {
			if(S.empty()) break;
			auto a=*M.begin();
			M.erase(M.begin());
			x=S.front();
			S.pop();
			R.push_back({a.second,x});
			a.first--;
			if(a.first==1) S.push(a.second);
			else M.insert(a);
		}
		
		if(S.size()==2) {
			x=S.front();
			S.pop();
			y=S.front();
			S.pop();
			R.push_back({x,y});
		}
		
		if(R.size()==(N-1)) {
			cout<<R.size()<<endl;
			FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
		}
		else {
			cout<<"invalid"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
