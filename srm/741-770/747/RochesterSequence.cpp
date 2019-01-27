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

int mo=1000000007;

template<class V,int MA> class BIT_2d {
public:
	V val[1<<MA][1<<MA];
	BIT_2d(){ZERO(val);};
	V add(V a,V b) {
		if(a.first>b.first) return a;
		if(a.first<b.first) return b;
		a.second+=b.second;
		if(a.second>=mo) a.second-=mo;
		return a;
	}
	V total(int x,int y) {
		V s={0,0};
		for(int i=x+1;i>0;i-=i&-i) for(int j=y+1;j>0;j-=j&-j) s=add(s,val[i-1][j-1]);
		return s;
	}
	void update(int x,int y,V v) {
		for(int i=x+1;i<=1<<MA;i+=i&-i) for(int j=y+1;j<=1<<MA;j+=j&-j) val[i-1][j-1]=add(val[i-1][j-1],v);
	}
};
BIT_2d<pair<int,int>,10> bit;


class RochesterSequence {
	public:
	
	vector <int> solve(vector <int> S, int n, int a, int b, int m) {
		while(S.size()<n) S.push_back((1LL*S.back()*a+b)%m);
		ZERO(bit.val);
		vector<vector<ll>> C;
		int i,j;
		FOR(j,n) FOR(i,j) C.push_back({(S[i]+S[j])*1000LL+1000+i-j,i,j});
		sort(ALL(C));
		
		pair<int,int> ret={0,1};
		FORR(c,C) {
			int L=c[1],R=c[2];
			auto a=bit.total(L-1,n-R-1);
			if(a.first==0) a.second++;
			a.first+=2;
			ret=bit.add(ret,a);
			bit.update(L,n-R,a);
		}
		
		return {ret.first,ret.second};
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10, 5, 9, 9, 12, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arr5[] = {6, 1 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {10, 20, 30, 40, 50, 60, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 0; int Arg3 = 0; int Arg4 = 474747; int Arr5[] = {6, 5 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {64, 32, 16, 8, 4, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arr5[] = {2, 21 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 1000; int Arg3 = 1; int Arg4 = 1000000007; int Arr5[] = {8, 10 }; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(3, Arg5, solve(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RochesterSequence ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

