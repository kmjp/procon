#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------



int stt[105][26];
const char base='a';
void CreateSTT(string& pat) {
	int x,y,z,l;
	ZERO(stt);
	l=pat.size();
	FOR(x,l+1) {
		FOR(y,26) {
			string pre=pat.substr(0,x)+(char)(base+y);
			for(z=1;z<=min(pat.size(),pre.size());z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
		}
	}
}

ll from[5][105];
ll to[5][105];
const ll mo=1000000007;


class MostSubstrings {
	public:
	int count(string S, int L) {
		int N=S.size();
		CreateSTT(S);
		
		ZERO(from);
		from[0][0]=1;
		int i,x,y,c;
		FOR(i,L) {
			ZERO(to);
			
			FOR(x,4) FOR(y,101) if(from[x][y]) {
				FOR(c,26) {
					int t=stt[y][c];
					to[x+(t==N)][t]+=from[x][y];
					if(to[x+(t==N)][t]>=mo) to[x+(t==N)][t]-=mo;
				}
			}
			
			FOR(y,104) if(to[4][y]) break;
			if(y<104) {
				FOR(x,104) {
					FOR(y,4) to[y][x]=to[y+1][x];
					to[4][x]=0;
				}
			}
			
			swap(from,to);
		}
		
		ll ret=0;
		for(y=4;y>=0;y--) {
			FOR(x,101) ret+=from[y][x];
			if(ret) break;
		}
		return ret%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "helloworld"; int Arg1 = 7; int Arg2 = 31810120; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aaaa"; int Arg1 = 13; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "dogecoin"; int Arg1 = 17; int Arg2 = 78; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "decode"; int Arg1 = 11; int Arg2 = 52; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MostSubstrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

