#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
class TaroFillingAStringDiv1 {
	public:
	
	int getNumber(int N, vector <int> position, string value) {
		int L=position.size(),i,x,y;
		pair<int,char> P[55];
		FOR(i,L) P[i]=make_pair(position[i]-1,value[i]);
		sort(P,P+L);
		
		ll ret=1;
		FOR(i,L-1) {
			int dif=P[i+1].first-P[i].first;
			if(dif%2==abs(P[i+1].second-P[i].second)) continue;
			if(dif==0) continue;
			ret = ret * dif % mo;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AB"; int Arg3 = 2; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBA"; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBBBABABBAAABA"; int Arg3 = 1; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 305; int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA"; int Arg3 = 43068480; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TaroFillingAStringDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
