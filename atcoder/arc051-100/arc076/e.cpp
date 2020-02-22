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

int H,W;
int N;
int X[101010][2],Y[101010][2];
vector<pair<int,int>> V;
int edge_id(int x,int y) {
	if(x==0) return y;
	if(y==H) return H+x;
	if(x==W) return H+W+(H-y);
	if(y==0) return H+W+H+(W-x);
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N;
	FOR(i,N) {
		cin>>X[i][0]>>Y[i][0]>>X[i][1]>>Y[i][1];
		
		x=edge_id(X[i][0],Y[i][0]);
		y=edge_id(X[i][1],Y[i][1]);
		if(x==-1 || y==-1) continue;
		V.push_back({x,i});
		V.push_back({y,i});
	}
	sort(ALL(V));
	vector<int> A;
	FORR(v,V) {
		if(A.size() && A.back()==v.second) A.pop_back();
		else A.push_back(v.second);
	}
	if(A.size()) return _P("NO\n");
	_P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
