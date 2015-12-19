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

int state[1<<19];
int tim[1<<19];
vector<pair<int,int> > Q;

class RailroadSwitchOperator {
	public:
	int minEnergy(int N, vector <int> x, vector <int> t) {
		int M=x.size();
		int i,j,L=0;
		
		while((1<<(L+1))<=N) L++;
		
		ZERO(state);
		MINUS(tim);
		Q.clear();
		FOR(i,M) {
			x[i]--;
			FOR(j,L) {
				int pos=(1<<j)+(x[i]>>(L-j));
				int ns=(x[i]>>(L-j-1))&1;
				if(state[pos]!=ns) Q.push_back({t[i]+j,tim[pos]+1});
				state[pos]=ns;
				tim[pos]=t[i]+j;
			}
		}
		
		sort(Q.begin(),Q.end());
		
		int cnt=0;
		int right=-1;
		FORR(r,Q) if(r.second>right) right = r.first, cnt++;
		return cnt;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2,1,2,1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, minEnergy(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,4,4,4,4,4,4,4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,4,8,16,32,64,128,256,512}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, minEnergy(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 32; int Arr1[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; verify_case(2, Arg3, minEnergy(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 131072; int Arr1[] = {1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,300,500,676,800,950,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, minEnergy(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1024; int Arr1[] = {1,1024,2,512,4,256,8,128,16,64,32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,5,8,13,21,34,55,89,144}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(4, Arg3, minEnergy(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RailroadSwitchOperator ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
