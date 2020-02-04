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

int CD[2525][2525];
bitset<2600> L[2525],R[2525],nei,C[2525][3];

class StringTransformation {
	public:
	string getResult(string s, string t) {
		int N=s.size();
		int i,x,y;
		if(s[0]!=t[0] || s.back()!=t.back()) return "NO";
		FORR(c,s) {
			if(c=='R') c=0;
			if(c=='G') c=1;
			if(c=='B') c=2;
		}
		FORR(c,t) {
			if(c=='R') c=0;
			if(c=='G') c=1;
			if(c=='B') c=2;
		}
		
		FOR(x,N) L[x].reset(),R[x].reset();
		nei.reset();
		FOR(x,N-1) {
			L[x][x+1]=1;
			R[x+1][x]=1;
			if(s[x]==s[x+1]) nei[x]=1;
		}
		for(int len=4;len<=N;len+=2) {
			for(x=0;x+len<=N;x++) if(s[x]!=s[x+len-1]) {
				auto A=L[x]&(R[x+len-1]>>1)&nei;
				if(A.count()) {
					L[x][x+len-1]=1;
					R[x+len-1][x]=1;
				}
			}
		}
		FOR(x,N) {
			C[x][0].reset();
			C[x][1].reset();
			C[x][2].reset();
			FOR(y,N) if(L[x][y]) C[x][s[y]][y]=1;
		}
		bitset<2600> cur;
		cur[0]=1;
		for(i=1;i<t.size();i++) {
			bitset<2600> nex;
			FOR(x,N) {
				if(cur[x]) {
					nex |= C[x][t[i]];
					
				}
			}
			cur=nex;
		}
		if(cur[N-1]) return "YES";
		return "NO";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGGG"; string Arg1 = "RG"; string Arg2 = "YES"; verify_case(0, Arg2, getResult(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RGRGRBRGRB"; string Arg1 = "RGRGRBRGRB"; string Arg2 = "YES"; verify_case(1, Arg2, getResult(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "R"; string Arg1 = "RRRRGBR"; string Arg2 = "NO"; verify_case(2, Arg2, getResult(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "RGBRGGRRBGB"; string Arg1 = "RGBRBGB"; string Arg2 = "YES"; verify_case(3, Arg2, getResult(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  StringTransformation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

