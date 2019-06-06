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

int G[305];
int ok[305][505];

class YetAnotherTokenGame {
	public:
	string getWinner(vector <int> piles) {
		ZERO(ok);
		ZERO(G);
		ok[0][0]=1;
		int i,j,x;
		for(i=1;i<=300;i++) {
			for(j=1;j<i;j++) {
				for(x=0;x<=500;x++) if(ok[i-j][x]) ok[i][G[j]^x]=1;
			}
			int did[504]={};
			FOR(j,i) did[G[j]]=1;
			FOR(j,503) if(ok[i][j]) did[j]=1;
			
			while(did[G[i]]) G[i]++;
			ok[i][G[i]]=1;
		}
		
		int nim=0;
		FORR(p,piles) nim^=G[p];
		return nim?"William":"Xenia";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "William"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "William"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {3,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "William"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {3,42,47,3,42,47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Xenia"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { int Arr0[] = {300,42,47,3,42,47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "William"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { int Arr0[] = {1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Xenia"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  YetAnotherTokenGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

