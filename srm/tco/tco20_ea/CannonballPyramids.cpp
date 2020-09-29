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

class CannonballPyramids {
	public:
	vector <int> build(int B) {
		vector<pair<int,ll>> P;
		ll sum=0;
		int i;
		for(i=0;i<=10000;i++) {
			sum+=i*i;
			P.push_back({i,sum});
			if(sum>B) break;
		}
		
		vector<vector<int>> cand={
			{0,0,0},
			{0,1,1},
			{0,2,5},
			{1,1,2},
			{1,2,6},
			{2,2,10},
		};
		
		map<int,pair<int,int>> C;
		FORR(p,P) FORR(q,P) {
			ll s=p.second+q.second;
			C[s]={p.first,q.first};
			
			FORR(c,cand) {
				ll lef=B-(s+c[2]);
				if(C.count(lef)) {
					vector<int> ret;
					ret.push_back(p.first);
					ret.push_back(q.first);
					ret.push_back(C[lef].first);
					ret.push_back(C[lef].second);
					ret.push_back(c[0]);
					ret.push_back(c[1]);
					
					sort(ALL(ret));
					while(ret[0]==0) ret.erase(ret.begin());
					return ret;
					
				}
				
			}
			
			
		}
		
		return {};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 280; int Arr1[] = {7, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, build(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 1, 1, 1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, build(Arg0)); }
	void test_case_2() { int Arg0 = 1253620; int Arr1[] = {2, 9, 155 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, build(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CannonballPyramids ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

