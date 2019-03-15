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

int D[505050];
ll mo=1000000007;

class SimulateBST {
	public:
	int checksum(int n, vector <int> S, int a, int m) {
		int SZ=S.size();
		int i;
		map<int,int> mp;
		ll ret=0;
		ll p=1;
		mp[-1]=mp[1<<30]=-1;
		FOR(i,n) {
			if(i>=SZ) S.push_back((a*1LL*S[i-SZ]+D[i-1]+1)%m);
			
			if(mp.count(S[i])==0) {
				auto it=mp.lower_bound(S[i]);
				int R=it->second;
				it--;
				int L=it->second;
				mp[S[i]]=max(L,R)+1;
			}
			D[i]=mp[S[i]];
			ret=(ret+D[i]*p)%mo;
			p=p*100000%mo;
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {10, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; int Arg4 = 99860; verify_case(0, Arg4, checksum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {10, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; int Arg4 = 0; verify_case(1, Arg4, checksum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {20, 10, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; int Arg4 = 99930; verify_case(2, Arg4, checksum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 9; int Arr1[] = {40, 20, 60, 70, 80, 30, 10, 30, 90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; int Arg4 = 461469106; verify_case(3, Arg4, checksum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 15; int Arr1[] = {10, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 1000000007; int Arg4 = 149719615; verify_case(4, Arg4, checksum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimulateBST ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

