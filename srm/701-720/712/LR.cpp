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

class LR {
	public:
	int N;
	string construct(vector<long long> s, vector<long long> t) {
		ll AS=0,AT=0;
		N=s.size();
		
		if(s==t) return "";
		FORR(a,s) AS+=a;
		FORR(a,t) AT+=a;
		
		if(AS==0 || AT%AS) return "No solution";
		int st=0;
		while(1LL<<st<AT/AS) st++;
		if(AS<<st != AT) return "No solution";

		int i,j;
		int LL,RR;
		FOR(LL,st+1) {
			RR=st-LL;
			vector<ll> f=s;
			string ret;
			FOR(i,LL) {
				ret+='L';
				vector<ll> v=f;
				FOR(j,N) v[j]+=f[(j+N-1)%N];
				f=v;
			}
			FOR(i,RR) {
				ret+='R';
				vector<ll> v=f;
				FOR(j,N) v[j]+=f[(j+1)%N];
				f=v;
			}
			
			if(t==f) return ret;
		}
		
		return "No solution";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {0,1,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,1,2,1,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "LL"; verify_case(0, Arg2, construct(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {0,0,0,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,1,0,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(1, Arg2, construct(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {12,24,56,95,12,78,0,100,54,88}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(2, Arg2, construct(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {1,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {11,11,10}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RRRRR"; verify_case(3, Arg2, construct(Arg0, Arg1)); }
	void test_case_4() { long Arr0[] = {1,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {562949953421312,562949953421312}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL"; verify_case(4, Arg2, construct(Arg0, Arg1)); }
	void test_case_5() { long Arr0[] = {0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,0,0,1,0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "No solution"; verify_case(5, Arg2, construct(Arg0, Arg1)); }
	void test_case_6() { long Arr0[] = {123,456}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {123,456}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(6, Arg2, construct(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LR ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

