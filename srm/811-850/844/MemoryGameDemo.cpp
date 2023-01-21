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

class MemoryGameDemo {
	public:
	
	vector <int> demo(int N, string cards, string remove) {
		vector<int> C[26];
		vector<int> R;
		int i;
		FOR(i,3*N) C[cards[i]-'A'].push_back(i);
		int x,y,z;
		
		FOR(i,remove.size()) {
			
			if(remove[i]=='Y') {
				FOR(x,N) if(C[x].size()) {
					R.push_back(C[x][0]);
					R.push_back(C[x][1]);
					R.push_back(C[x][2]);
					C[x].clear();
					break;
				}
			}
			else {
				FOR(x,N) if(C[x].size()) {
					FOR(y,x) if(C[y].size()) {
						if(i%2==0) {
							R.push_back(C[x][0]);
							R.push_back(C[y][0]);
							R.push_back(C[y][1]);
						}
						else {
							R.push_back(C[x][0]);
							R.push_back(C[x][1]);
							R.push_back(C[y][0]);
						}
						goto out;
					}
				}
				out:
				;
			}
		}
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arg1 = "AAABBBCCC"; string Arg2 = "NNNN"; int Arr3[] = {0, 3, 6, 0, 3, 7, 1, 3, 4, 2, 5, 6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, demo(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "ABABCCBAC"; string Arg2 = "YN"; int Arr3[] = {0, 2, 7, 4, 1, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, demo(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "FEABDCDEACFFADCEBB"; string Arg2 = "YNYNNYY"; int Arr3[] = {2, 8, 12, 5, 3, 16, 3, 16, 17, 4, 5, 9, 5, 4, 6, 5, 9, 14, 4, 6, 13 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, demo(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MemoryGameDemo ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

