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
string S[5];

string T[]={
	".###..#..###.###.#.#.###.###.###.###.###.",
	".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
	".#.#..#..###.###.###.###.###...#.###.###.",
	".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
	".###.###.###.###...#.###.###...#.###.###.",
};

int hoge(int x) {
	int i,y;
	FOR(i,10) {
		FOR(y,5) {
			if(T[y].substr(i*4+1,3)!=S[y].substr(x,3)) break;
		}
		if(y==5) return i;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,5) cin>>S[i];
	
	string R;
	FOR(i,N) R+='0'+hoge(i*4+1);
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
