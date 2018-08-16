#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class MazeWithKeys {
	public:
	int H,W;
	vector<string> S;
	int vis[51][51];
	int key[26];
	int door[26];
	int ok(int sy,int sx,int use_door) {
		ZERO(vis);
		ZERO(key);
		MINUS(door);
		queue<int> Q;
		Q.push(sy*100+sx);
		
		while(Q.size()) {
			int cy=Q.front()/100;
			int cx=Q.front()%100;
			Q.pop();
			if(S[cy][cx]=='*') return 1;
			if(vis[cy][cx]) continue;
			vis[cy][cx]=1;
			int d[4]={1,0,-1,0};
			int i;
			FOR(i,4) {
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
				if(vis[ty][tx] || S[ty][tx]=='#') continue;
				if(S[ty][tx]>='A' && S[ty][tx]<='Z') {
					door[S[ty][tx]-'A']=ty*100+tx;
					if(use_door && key[S[ty][tx]-'A']) Q.push(ty*100+tx);
				}
				else {
					if(S[ty][tx]>='a' && S[ty][tx]<='z') {
						key[S[ty][tx]-'a']++;
						if(use_door && door[S[ty][tx]-'a']>=0) Q.push(door[S[ty][tx]-'a']);
					}
					Q.push(ty*100+tx);
				}
				
			}
			
		}
		return 0;
	}
	
	int startingPoints(vector <string> a) {
		S=a;
		H=a.size();
		W=a[0].size();
		
		int y,x;
		int ret=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='.' && ok(y,x,1) && ok(y,x,0)==0) ret++;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...#.A.",
 ".#B#.#.",
 ".#.#.#.",
 ".#.#.#.",
 ".#b#.#.",
 "a#...#*"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, startingPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"..*",
 ".a.",
 "A.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, startingPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {".A*C.",
 ".#B#.",
 ".#.#.",
 "a..b."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, startingPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"a#a#*",
 "#..#.",
 "a..A."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, startingPoints(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MazeWithKeys ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

