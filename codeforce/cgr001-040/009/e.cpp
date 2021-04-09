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
int A[1010];
int S[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,vector<int>> M;
	FOR(i,N) {
		cin>>A[i];
		M[A[i]].push_back(i);
	}
	vector<pair<int,int>> R;
	vector<int> C;
	FORR(m,M) {
		vector<int> B=m.second;
		reverse(ALL(C));
		FORR(b,B) FORR(c,C) if(b<c) {
			R.push_back({b,c});
		}
		FORR(b,B) C.push_back(b);
		sort(ALL(C));
		
	}
	
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r.first+1<<" "<<r.second+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
