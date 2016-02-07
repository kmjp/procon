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

vector<pair<int,int> > V[101010];

class FleetFunding {
	public:
	
	int ok(int v,int m) {
		map<int,int> M;
		int i;
		
		for(i=1;i<=m;i++) {
			while(M.size() && M.begin()->first<i) M.erase(M.begin());
			FORR(r,V[i]) M[r.first]+=r.second;
			int d=v;
			while(d>0) {
				if(M.empty()) return 0;
				int s=min(d,M.begin()->second);
				d-=s;
				M.begin()->second-=s;
				if(M.begin()->second==0) M.erase(M.begin());
			}
		}
		return 1;
	}
	
	int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
		int i;
		int N=k.size();
		FOR(i,m+2) V[i].clear();
		FOR(i,N) V[a[i]].push_back({b[i],k[i]});
		
		int ret=0;
		for(i=29;i>=0;i--) if(ok(ret+(1<<i),m)) ret+=1<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 55; verify_case(1, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {2,4,6,8,10,1,3,5,7,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 84457; int Arr1[] = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
857994,991217,149619,415870}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 186; verify_case(3, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {1000000,1000000,1000000,1000000,1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2500000; verify_case(4, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FleetFunding ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
