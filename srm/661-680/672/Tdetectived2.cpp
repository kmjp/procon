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

int is[1<<18];

class Tdetectived2 {
	public:
	int reveal(vector <string> s) {
		int val[20];
		int N=s.size();
		int i,j,k;
		
		FOR(i,N) val[i]=100;
		ZERO(is);
		
		is[1]=1;
		for(int mask=0;mask<1<<N;mask++) if(is[mask]) {
			int ma[20]={};
			FOR(i,N) if(mask&(1<<i)) FOR(j,N) ma[j]=max(ma[j],s[i][j]-'0');
			
			int md=-1,ma2=0;
			FOR(i,N) if((mask&(1<<i))==0) {
				if(md<ma[i]) md=ma[i], ma2=0;
				if(md==ma[i]) ma2 |= 1<<i;
			}
			FOR(i,N) if(ma2&(1<<i)) {
				is[mask | (1<<i)] = 1;
				val[i]=min(val[i],__builtin_popcount(mask));
			}
		}
		
		int ret=0;
		FOR(i,N) ret += i*val[i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, reveal(Arg0)); }
	void test_case_1() { string Arr0[] = {"0224","2011","2104","4140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, reveal(Arg0)); }
	void test_case_2() { string Arr0[] = {"0886","8086","8801","6610"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, reveal(Arg0)); }
	void test_case_3() { string Arr0[] = {"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, reveal(Arg0)); }
	void test_case_4() { string Arr0[] = {"0313131","3030020","1301132","3010031","1010003","3233003","1021330"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, reveal(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Tdetectived2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
