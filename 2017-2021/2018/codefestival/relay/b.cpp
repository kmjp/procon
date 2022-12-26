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

string S;
int X,Y;
int C[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X>>Y;
	vector<pair<int,int>> V;
	V.push_back({0,1});
	V.push_back({0,-1});
	V.push_back({1,0});
	V.push_back({-1,0});
	sort(ALL(V));
	if(X==0 && Y==0) return _P("Yes\n");
	FORR(c,S) {
		C[c-'W']++;
		
		do {
			x=y=0;
			FOR(i,4) {
				x+=C[i]*V[i].first;
				y+=C[i]*V[i].second;
			}
			if(x==X && y==Y) return _P("Yes\n");
		} while(next_permutation(ALL(V)));
		
		
	}
	_P("No\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
