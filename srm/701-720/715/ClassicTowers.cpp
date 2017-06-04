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

ll ma[53][53][53];
ll mi[53][53][53];

class ClassicTowers {
	public:
	ll getma(int A,int B,int C) {
		if(ma[A][B][C]>=0) return ma[A][B][C];
		ll ret=0;
		if(A) ret=max(ret,getma(A-1,C,B)+1+getma(0,A+B+C-1,0));
		if(B) ret=max(ret,getma(B-1,C,A)+1+getma(0,A+B+C-1,0));
		if(C) ret=max(ret,getma(A,B,C-1));
		return ma[A][B][C]=ret;
	}
	ll getmi(int A,int B,int C) {
		if(mi[A][B][C]>=0) return mi[A][B][C];
		if(A+B+C==0) return 0;
		ll ret=1LL<<60;
		if(A) ret=min(ret,getmi(A-1,C,B)+1+getmi(0,A+B+C-1,0));
		if(B) ret=min(ret,getmi(B-1,C,A)+1+getmi(0,A+B+C-1,0));
		if(C) ret=min(ret,getmi(A,B,C-1));
		return mi[A][B][C]=ret;
	}
	
	string hoge(int A,int B,int C,string a,string b,string c,ll k) {
		if(A<0 || B<0 || C<0) return string(51,'Z');
		if(A+B+C==0 && k==0) return "";
		if(k<getmi(A,B,C) || getma(A,B,C)<k) return string(51,'Z');
		
		int cnt=A+B+C;
		string s=string(51,'z');
		if(s.size()>cnt) s=hoge(A-1,C,B,a,c,b,k-(1LL<<(cnt-1)))+a;
		if(s.size()>cnt) s=hoge(B-1,C,A,b,c,a,k-(1LL<<(cnt-1)))+b;
		if(s.size()>cnt) s=hoge(A,B,C-1,a,b,c,k)+c;
		return s;
	}
	
	string findTowers(long long k, vector <int> count) {
		MINUS(ma);
		MINUS(mi);
		
		string s=string(51,'z');
		int c=count[0]+count[1]+count[2];
		if(s.size()>c) s=hoge(count[0],count[1],count[2]-1,"A","B","C",k)+"C";
		if(s.size()>c) s=hoge(count[1],count[0],count[2]-1,"B","A","C",k)+"C";
		if(s.size()>c) s=hoge(count[0],count[2],count[1]-1,"A","C","B",k)+"B";
		if(s.size()>c) s=hoge(count[2],count[0],count[1]-1,"C","A","B",k)+"B";
		if(s.size()>c) s=hoge(count[1],count[2],count[0]-1,"B","C","A",k)+"A";
		if(s.size()>c) s=hoge(count[2],count[1],count[0]-1,"C","B","A",k)+"A";
		if(s.size()>c) return "";
		return s;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; int Arr1[] = {1,1,2}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CCAB"; verify_case(0, Arg2, findTowers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 0LL; int Arr1[] = {0, 0, 50}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"; verify_case(1, Arg2, findTowers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 0LL; int Arr1[] = {10,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(2, Arg2, findTowers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 123456123456123LL; int Arr1[] = {10,10,30}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CCACCCACCABACCABBACCCBBCCBCCCBACCCCABBACCCCCACBCCC"; verify_case(3, Arg2, findTowers(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 314159265358979LL; int Arr1[] = {15,16,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, findTowers(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ClassicTowers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

