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

ll from[1010],to[1010];
const ll mo=1000000007;

class SkyscraperCounting {
	public:
	int count(string visibility) {
		ZERO(from);
		from[0]=1;
		int N=visibility.size();
		
		int i,j;
		FOR(i,N) {
			if(visibility[i]=='X') {
				FOR(j,N+1) {
					if(j-i>0) (from[j]*=j-i)%=mo;
					else from[j]=0;
				}
			}
			else {
				ll sum=0;
				ZERO(to);
				FOR(j,N+1) {
					to[j]=sum;
					(sum+=from[j])%=mo;
				}
				swap(from,to);
			}
		}
		ll ret=0;
		FOR(i,1005) ret+=from[i];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "OXXXX"; int Arg1 = 24; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "OXOXXOX"; int Arg1 = 72; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "XOXOXO"; int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "OXXXXXXXXXXXXXO"; int Arg1 = 227020758; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SkyscraperCounting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

