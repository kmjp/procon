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

int dp[500][500];

class BearPlaysDiv2 {
	public:
	string equalPiles(int A, int B, int C) {
		if(A>B) swap(A,B);
		if(B>C) swap(B,C);
		if(A>B) swap(A,B);
		
		int T=A+B+C,i;
		if(T%3) return "impossible";
		ZERO(dp);
		dp[A][B]=1;
		queue<pair<int,int> > Q;
		Q.push({A,B});
		while(Q.size()) {
			auto r=Q.front();
			Q.pop();
			int a=r.first,b=r.second,c=T-a-b;
			if(a==b && b==c) return "possible";
			
			int vec[3][3]= {
				{a*2,b-a,c},
				{a*2,c-a,b},
				{b*2,c-b,a},
			};
			FOR(i,3) {
				sort(vec[i],vec[i]+3);
				if(dp[vec[i][0]][vec[i][1]]==0) dp[vec[i][0]][vec[i][1]]=1, Q.push({vec[i][0],vec[i][1]});
			}
		}
		return "impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 35; string Arg3 = "possible"; verify_case(0, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; string Arg3 = "impossible"; verify_case(1, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 8; string Arg3 = "impossible"; verify_case(2, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 18; int Arg2 = 18; string Arg3 = "possible"; verify_case(3, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 225; int Arg1 = 500; int Arg2 = 475; string Arg3 = "possible"; verify_case(4, Arg3, equalPiles(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearPlaysDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
