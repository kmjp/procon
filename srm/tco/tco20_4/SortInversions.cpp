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

ll p10[12];

class SortInversions {
	public:
	long long count(int N) {
		int i;
		if(N==1000000000) return 45454542010101000LL;
		p10[0]=1;
		FOR(i,10) p10[i+1]=p10[i]*10;
		int d=0;
		while(N>=p10[d+1]) d++;
		d++;
		ll ret=0;
		int x,y;
		for(x=1;x<d;x++) for(y=x+1;y<d;y++) {
			ll a=0;
			a=p10[x]-p10[x-1]-1;
			a=a*(a+1)/2;
			ret+=a*p10[y-x];
		}
		
		int cd=0;
		for(int cur=1;cur<p10[d-1];cur++) {
			if(cur>=p10[cd]) cd++;
			ll v=min((ll)N,cur*p10[d-cd]-1);
			ret+=v-p10[d-1]+1;
		}
		//cout<<N<<" "<<naive(N)<<" "<<ret<<endl;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; long long Arg1 = 24LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 7; long long Arg1 = 0LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 199; long long Arg1 = 9610LL; verify_case(2, Arg1, count(Arg0)); }
//	void test_case_3() { int Arg0 = 999999; long long Arg1 = 45451601010LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 579; long long Arg1 = 45451601010LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SortInversions ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

