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

ll dp[1<<20][20];

class TheRectangularCityDiv2 {
	public:
	long long find(vector <string> city) {
		int H=city.size();
		int W=city[0].size();
		ZERO(dp);
		int mask=0;
		int y,x;
		FOR(y,H) FOR(x,W) if(city[y][x]=='#') mask |= 1<<(y*W+x);
		FOR(y,H) FOR(x,W) if(city[y][x]=='.' && (y==0 || y==H-1 || x==0 || x==W-1)) dp[mask | (1<<(y*W+x))][y*W+x]=1;
		
		FOR(mask,1<<(H*W)) {
			FOR(y,H) FOR(x,W) if(dp[mask][y*W+x]) {
				if(y&&(mask&(1<<((y-1)*W+x)))==0) dp[mask | (1<<((y-1)*W+x))][(y-1)*W+x] += dp[mask][y*W+x];
				if(y<H-1&&(mask&(1<<((y+1)*W+x)))==0) dp[mask | (1<<((y+1)*W+x))][(y+1)*W+x] += dp[mask][y*W+x];
				if(x&&(mask&(1<<(y*W+x-1)))==0) dp[mask | (1<<(y*W+x-1))][y*W+x-1] += dp[mask][y*W+x];
				if(x<W-1&&(mask&(1<<(y*W+x+1)))==0) dp[mask | (1<<(y*W+x+1))][y*W+x+1] += dp[mask][y*W+x];
			}
		}
		
		ll ret=0;
		FOR(y,H) FOR(x,W) if(y==0 || y==H-1 || x==0 || x==W-1) ret+=dp[(1<<(H*W))-1][y*W+x];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"....", 
".##.", 
"...."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 20LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {
"....", 
".###", 
"...."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {
"....", 
"####", 
"...."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {
"....", 
"....", 
"...."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 80LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheRectangularCityDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

