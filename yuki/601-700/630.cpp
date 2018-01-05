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

int N,M;
int A[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) A[i]=i+1;
	
	vector<pair<int,int>> V;
	set<pair<int,int>> S;
	FOR(i,N/2) {
		V.push_back({i,i+N/2});
		S.insert({i,i+N/2});
		M--;
		if(i+N/2+1<N) {
			V.push_back({i,i+N/2+1});
			S.insert({i,i+N/2+1});
			M--;
		}
	}
	if(M<0) return _P("NO\n");
	
	FOR(i,N/2) {
		for(j=N/2;j<N && M;j++) {
			if(S.count({i,j})==0) {
				V.push_back({i,j});
				S.insert({i,j});
				M--;
			}
		}
	}
	
	if(M) return _P("NO\n");
	cout<<"YES"<<endl;
	FOR(i,N) {
		cout<<A[i];
		if(i<N-1) cout<<" ";
	}
	cout<<endl;
	FORR(v,V) {
		cout<<v.first+1<<" "<<v.second+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
