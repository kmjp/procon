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

int X,Y,A,B,C;
vector<pair<int,int>> E;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>A>>B>>C;
	FOR(i,A) cin>>x, E.push_back({x,0});
	FOR(i,B) cin>>x, E.push_back({x,1});
	FOR(i,C) cin>>x, E.push_back({x,2});
	sort(ALL(E));
	
	ll ret=0;
	FORR(e,E) {
		x=e.second;
		y=e.first;
		if(x==0) {
			if(A+C==X || (B+C==Y&&A==X) || A+B+C==X+Y) {
				X--;
				ret+=y;
			}
			A--;
		}
		else if(x==1) {
			if((A+C==X&&B==Y) || B+C==Y || A+B+C==X+Y) {
				Y--;
				ret+=y;
			}
			B--;
		}
		else {
			if(A+C==X || B+C==Y || A+B+C==X+Y) {
				if(A<X) {
					X--;
				}
				else if(Y) {
					Y--;
				}
				ret+=y;
			}
			C--;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
