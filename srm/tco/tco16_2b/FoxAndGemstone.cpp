#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int num[51][16];
int num2[51][1<<16];
ll dp[1<<16];

class FoxAndGemstone {
	public:
	string isPossible(vector <string> B) {
		int i,x,y,mask;
		
		FORR(s,B) sort(s.begin(),s.end());
		sort(B.begin(),B.end());
		B.erase(unique(B.begin(),B.end()),B.end());
		int N=B.size();
		ZERO(num);
		ZERO(num2);
		FOR(i,N) {
			FORR(r,B[i]) num[i][r-'A']++;
			FOR(x,1<<16) FOR(y,16) if(x&(1<<y)) num2[i][x]+=num[i][y];
		}
		
		ll tot=0;
		FOR(x,N) {
			ZERO(dp);
			dp[0]=1;
			
			for(int mask=1;mask<1<<16;mask++) {
				FOR(y,N) if(num2[y][mask]>num2[x][mask]) break;
				if(y<N) continue;
				FOR(y,16) if(mask&(1<<y)) dp[mask] += dp[mask^(1<<y)];
			}
			tot+=dp[(1<<16)-1];
		}
		
		if(tot==16LL*15*14*13*12*11*10*9*8*7*6*5*4*3*2) return "Possible";
		return "Impossible";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB", "AC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, isPossible(Arg0)); }
	void test_case_1() { string Arr0[] = {"A", "BC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, isPossible(Arg0)); }
	void test_case_2() { string Arr0[] = {"A", "B", "C", "AB", "AC", "BC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, isPossible(Arg0)); }
	void test_case_3() { string Arr0[] = {"AB","AC","AD","BC","BD","CD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, isPossible(Arg0)); }
	void test_case_4() { string Arr0[] = {"AB", "CD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, isPossible(Arg0)); }
	void test_case_5() { string Arr0[] = {"A", "A", "A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(5, Arg1, isPossible(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndGemstone ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
