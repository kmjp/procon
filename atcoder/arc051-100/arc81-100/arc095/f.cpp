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
vector<vector<int>> E;

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

vector<pair<int,int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	
	vector<pair<int,int>> R;
	//dS‚ðŽæ‚éê‡
	for(int i=E.size()-1;i>=0;i--) if(D[0][i]+D[1][i]==v2.first) R.push_back({D[0][i],i});
	sort(ALL(R));

	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	auto R=diameter(E);
	vector<int> A,B;
	int num=0;
	FOR(i,R.size()) {
		A.push_back(E[R[i].second].size());
		A.back()--;
		if(i>0 && i<R.size()-1) A.back()--;
		num+=1+A.back();
	}
	B=A;
	reverse(ALL(B));
	if(num!=N) return _P("-1\n");
	A=min(A,B);
	
	int nex=0;
	FOR(i,A.size()) {
		FOR(x,A[i]) cout<<nex+2+x<<" ";
		cout<<nex+1<<" ";
		nex+=1+A[i];
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
