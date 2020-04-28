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

class LineColoring {
	public:
	int minCost(vector <int> x) {
		int N=x.size();
		
		// 2 col;
		int ma[2]={};
		int i,j;
		FOR(i,N) ma[i%2]=max(ma[i%2],x[i]);
		int ret=ma[0]+ma[1];
		// 3col
		vector<pair<int,int>> V;
		FOR(i,N) V.push_back({x[i],i});
		sort(ALL(V));
		reverse(ALL(V));
		
		vector<pair<int,int>> V2;
		V2.push_back({V[0].second,1});
		for(i=1;i<N;i++) {
			int cur=V[i].second;
			V2.push_back({cur,2});
			sort(ALL(V2));
			int tmp=V[0].first+x[cur];
			int ma=0;
			FOR(j,V2.size()-1) {
				int a=V2[j].first;
				int b=V2[j+1].first;
				if(a+1==b && V2[j].second==V2[j+1].second) {
					ma=1<<30;
					continue;
				}
				if((b-a)%2==abs(V2[j].second-V2[j+1].second)) continue;
				
				int t=1<<30,z;
				for(z=a+1;z<b;z++) t=min(t,x[z]);
				ma=max(ma,t);
			}
			ret=min(ret,tmp+ma);
			
			FORR(c,V2) if(c.first==cur) c.second=1;
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6,7,8,9}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minCost(Arg0)); }
	void test_case_1() { int Arr0[] = {7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, minCost(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minCost(Arg0)); }
	void test_case_3() { int Arr0[] = {1,10,1,1,1,1,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, minCost(Arg0)); }
	void test_case_4() { int Arr0[] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 33; verify_case(4, Arg1, minCost(Arg0)); }
	void test_case_5() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; verify_case(5, Arg1, minCost(Arg0)); }
	void test_case_6() { int Arr0[] = {9450,7098,6048,1050,672,8232,5028,
672,672,42,42,42,42,42,9450,6048,
3402,3402,2688,9450,7098,6048,1050,
672,8232,5028,672,672,9450,6048,3402}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18900; verify_case(6, Arg1, minCost(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LineColoring ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

