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

class BalancedStrings {
	public:
	vector <string> findAny(int N) {
		vector<string> R;
		int i,x,y,j;
		if(N<=26) {
			FOR(i,N) {
				R.push_back(string(1,'a'+i));
			}
		}
		else {
			int ret=0;
			FOR(i,N-4) {
				R.push_back(string(1,'a'+(i/8)));
				ret += i%8;
			}
			FOR(i,4) {
				int c='a'+18+i*2;
				int d=c+1;
				R.push_back(string(1,c));
				swap(c,d);
				while(ret&&R.back().size()<100) {
					R.back().push_back(c);
					swap(c,d);
					ret--;
				}
			}
			
			
		}
		
		int A=0,B=0;
		FORR(r,R) {
			FOR(i,r.size()-1) if(r[i]!=r[i+1]) A++;
		}
		FOR(j,N) FOR(i,j) {
			FORR(rr,R[i]) FORR(rk,R[j]) if(rr==rk) B++;
		}
		
		if(A!=B || N!=R.size()) cout<<A<<" "<<B<<" "<<N<<" "<<R.size()<<endl;
		
		
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"eertree", "topcoder", "arena" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findAny(Arg0)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {"hello", "little", "polar", "bear" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findAny(Arg0)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findAny(Arg0)); }
	void test_case_3() { int Arg0 = 1; string Arr1[] = {"kkkkkkkkkkkkkkkkkkk" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findAny(Arg0)); }
	void test_case_4() { int Arg0 = 50; string Arr1[] = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findAny(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BalancedStrings ___test;
  int i;
  for(i=1;i<=100;i++) {
	___test.findAny(i);
 }
 // ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

