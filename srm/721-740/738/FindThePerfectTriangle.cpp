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

int sq[1000005];

class FindThePerfectTriangle {
	public:
	vector <int> constructTriangle(int area, int perimeter) {
		ll a,b,c;
		ll A=area;
		
		int i,j,x,y;
		for(i=1;i<=1000;i++) sq[i*i]=i;
		
		
		vector<vector<int>> V;
		for(x=0;x<=500;x++) {
			for(y=0;y<=500;y++) {
				if(sq[x*x+y*y]>0 && sq[x*x+y*y]<500) {
					int s=sq[x*x+y*y];
					V.push_back({x,y,s});
					V.push_back({-x,y,s});
					V.push_back({x,-y,s});
					V.push_back({-x,-y,s});
				}
			}
		}
		
		vector<int> R;
		FOR(i,V.size()) {
			if(V[i][0]<0 || V[i][0]<0) continue;
			FOR(j,V.size()) if(i!=j) {
				int dx=V[i][0]-V[j][0];
				int dy=V[i][1]-V[j][1];
				
				int a=V[i][2];
				int b=V[j][2];
				int s=sq[dx*dx+dy*dy];
				if(s==0 || a+b+s!=perimeter) continue;
				if(a>=b+s) continue;
				if(b>=a+s) continue;
				if(s>=a+b) continue;
				
				
				ll A=V[i][0]*V[j][1]-V[i][1]*V[j][0];
				if(abs(A)!=area*2) continue;
				
				R.push_back(1500);
				R.push_back(1500);
				R.push_back(1500+V[i][0]);
				R.push_back(1500+V[i][1]);
				R.push_back(1500+V[j][0]);
				R.push_back(1500+V[j][1]);
				return R;
				
			}
		}
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 11; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, constructTriangle(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 12; int Arr2[] = {1, 1, 1, 4, 5, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, constructTriangle(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37128; int Arg1 = 882; int Arr2[] = {137, 137, 273, 410, 1, 410 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, constructTriangle(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 18; int Arr2[] = {1, 1, 4, 5, 1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, constructTriangle(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 18096; int Arg1 = 928; int Arr2[] = {1, 1, 1, 88, 417, 88 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, constructTriangle(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 1000; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, constructTriangle(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindThePerfectTriangle ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

