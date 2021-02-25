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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class PolylineCover {
	public:
	vector<double> hoge(vector<pair<int,int>> V) {
		sort(ALL(V));
		unique(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		
		if(V.size()==1) {
			auto p=*V.begin();
			return {p.first-100000.0,p.second+50000.0,p.first+100000.0,p.second+50000.0,p.first+100000.0,p.second-50000.0};
		}
		
		int N=V.size();
		pair<ll,ll> S,T;
		double mad=-1;
		int a,b;
		FORR(a,V) FORR(b,V) if(a<b) {
			double dx=b.first-a.first;
			double dy=b.second-a.second;
			double d=hypot(dx,dy);
			if(d>mad) {
				S=a;
				T=b;
				mad=d;
			}
		}
		
		double dx=(T.first-S.first)/mad;
		double dy=(T.second-S.second)/mad;
		double ex=dy;
		double ey=-dx;
		double ma=0,mi=0;
		FORR(c,V) {
			double fx=c.first-S.first;
			double fy=c.second-S.second;
			double cr=fx*ex+fy*ey;
			ma=max(ma,cr);
			mi=min(mi,cr);
		}
		ma=mi+100000;
		vector<double> ret;
		ret.push_back(S.first+mi*ex);
		ret.push_back(S.second+mi*ey);
		ret.push_back(S.first+200000*dx+mi*ex);
		ret.push_back(S.second+200000*dy+mi*ey);
		ret.push_back(S.first+200000*dx+ma*ex);
		ret.push_back(S.second+200000*dy+ma*ey);
		return ret;
	}
	
	
	vector <double> cover(vector <int> L, vector <int> X, vector <int> Y) {
		int cur=0;
		vector <double> ret;
		FORR(v,L) {
			vector<pair<int,int>> V;
			int i;
			FOR(i,v) {
				V.push_back({X[cur],Y[cur]});
				cur++;
			}
			auto r=hoge(V);
			FORR(a,r) ret.push_back(a);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 200010}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.0, 0.0, 0.0, 100.0, 1.23456789E8, 100.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, cover(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 200010, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 200010, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.0, 0.0, 0.0, 100.0, 1.23456789E8, 100.0, 90.0, 10.0, -10.0, 10.0, -10.0, 1.23456799E8 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, cover(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 200010, 10, 10, 0, 30000, 60000, 90000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 200010, 10, 0, 30000, 0, 30000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.0, 0.0, 0.0, 30000.0, 300000.0, 30000.0, 30000.0, 0.0, 0.0, 0.0, 0.0, 300000.0, 0.0, 0.0, 0.0, 30000.0, 300000.0, 30000.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, cover(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arr3[] = {0.0, -85.0, -85.0, 0.0, 0.0, 85.0, 0.0, -85.0, -85.0, 0.0, 0.0, 85.0, 0.0, -80.0, -85.0, 5.0, 0.0, 90.0 }; vector <double> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, cover(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PolylineCover ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

