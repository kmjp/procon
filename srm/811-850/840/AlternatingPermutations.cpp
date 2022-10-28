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

const ll mo=1000000007;

ll from[7005][2];
ll to[7005][2];

class AlternatingPermutations {
	public:
	int count(int N, vector <int> prefix) {
		
		int i;
		set<int> S;
		FORR(p,prefix) {
			if(S.count(p)) return 0;
			S.insert(p);
		}
		
		if(prefix.size()>=3) {
			for(i=2;i<prefix.size();i++) if((prefix[i]-prefix[i-1])*(prefix[i-1]-prefix[i-2])>=0) return 0;
		}
		
		if(prefix.size()==N||N==1) return 1;
		
		ZERO(from);
		if(prefix.empty()) {
			FOR(i,N) from[i][0]=from[i][1]=1;
		}
		else if(prefix.size()==1) {
			from[prefix[0]][0]=from[prefix[0]][1]=1;
		}
		else {
			int le=prefix.back();
			FORR(p,prefix) if(p<prefix.back()) le--;
			if(prefix[prefix.size()-2]<prefix[prefix.size()-1]) from[le][1]=1;
			else from[le][0]=1;
			N-=prefix.size()-1;
		}
		
		
		while(N>1) {
			ZERO(to);
			
			//up
			ll sum=0;
			FOR(i,N) {
				(sum+=from[i][0])%=mo;
				to[i][1]=sum;
			}
			//down
			sum=0;
			for(i=N-1;i>=1;i--) {
				(sum+=from[i][1])%=mo;
				to[i-1][0]=sum;
			}
			
			
			swap(from,to);
			N--;
		}
		return (from[0][0]+from[0][1])%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {6, 0, 7, 1, 8, 2, 9, 3, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {6, 0, 7, 1, 8, 2, 9, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {6, 0, 7, 1, 8, 2, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 3; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 10; int Arr1[] = {9, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1385; verify_case(6, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AlternatingPermutations ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

