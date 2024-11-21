#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int M;
ll Q[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<vector<int>> R;
	cin>>M;
	FOR(i,50) {
		cin>>Q[i];
		if(Q[i]==1) x=i;
		if(Q[i]!=1) y=i;
	}
	int sum=x;
	FOR(i,50) R.push_back({1,i+1});
	vector<int> C={y};
	FOR(i,50) if(i!=y&&i!=x) C.push_back(i);
	FOR(i,30) {
		R.push_back({4,C[i]+1,C[i]+1,C[i+1]+1});
	}
	int first=-1;
	FOR(i,30) if(M&(1<<i)) {
		if(first==-1) {
			first=C[i];
		}
		else {
			R.push_back({4,first+1,C[i]+1,first+1});
		}
	}
	
	FOR(i,50) if(i!=first&&i!=sum) R.push_back({4,first+1,first+1,i+1});
	
	cout<<R.size()<<endl;
	FORR(r,R) {
		FOR(i,r.size()-1) cout<<r[i]<<" ";
		cout<<r.back()<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
