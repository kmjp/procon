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



class IncreasingJumpsDiv1 {
	public:
	
	int ok(vector <int> frogs,vector <int> ret) {
		int i;
		for(i=0;i<ret.size();i++) {
			if(ret[i]>0) frogs[ret[i]-1]+=i+1;
			else if(ret[i]<0) frogs[-ret[i]-1]-=i+1;
			else return 0;
		}
		sort(ALL(frogs));
		FOR(i,frogs.size()-1) if(frogs[i]+1!=frogs[i+1]) return 0;
		return 1;
	}
	
	vector <int> jump(vector <int> frogs) {
		int N=frogs.size();
		int x,i;
		
		
		vector<int> R,D=frogs;
		for(x=1;x<=2500;x++) {
			FOR(i,N) {
				if(D[i]>1500) {
					R.push_back(-(i+1));
					D[i]-=x;
					break;
				}
				if(D[i]<1000) {
					R.push_back((i+1));
					D[i]+=x;
					break;
				}
			}
			if(i==N) break;
		}
		FOR(i,N) {
			int tar=1250-(N/2)+i;
			while(D[i]<tar) {
				int d=sqrt(abs(tar-D[i]));
				D[i]+=d*d;
				FOR(x,d) R.push_back(-(i+1));
				FOR(x,d) R.push_back((i+1));
			}
			while(D[i]>tar) {
				int d=sqrt(abs(tar-D[i]));
				D[i]-=d*d;
				FOR(x,d) R.push_back((i+1));
				FOR(x,d) R.push_back(-(i+1));
			}
		}
		cerr<<R.size()<<endl;
		assert(ok(frogs,R));
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, jump(Arg0)); }
	void test_case_0_() { int Arr0[] = {5, 6, 1, 9, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, jump(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, jump(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 35}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, -2, -2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, jump(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 7, 3, 9, 5, 6, 10, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, -3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, jump(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IncreasingJumpsDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

