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

	vector<string> split(const string &str, char delim=' '){
		vector<string> res;
		size_t current = 0, found;
		while((found = str.find_first_of(delim, current)) != string::npos){
			res.push_back(string(str, current, found - current));
			current = found + 1;
		}
		res.push_back(string(str, current, str.size() - current));
		return res;
	}

class AqaAsadiNames {
	public:
	string getName(string Dad, string Mom, string FirstChild, string Gender) {
		auto D=split(Dad);
		auto M=split(Mom);
		auto C=split(FirstChild);
		string V="AIUEOY";
		map<char,int> girl;
		FORR(c,V) girl[c]=1;
		
		if(girl[C[0][0]] && Gender=="Girl") {
			return M[0]+" "+C[1];
		}
		if(girl[C[0][0]] && Gender=="Boy") {
			return D[1]+" "+D[0];
		}
		if(girl[C[0][0]]==0 && Gender=="Girl") {
			return M[1]+" "+M[0];
		}
		if(girl[C[0][0]]==0 && Gender=="Boy") {
			return D[0]+" "+C[1];
		}
		return "";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Mohammad Reza"; string Arg1 = "Yasaman Sadat"; string Arg2 = "Baqer Ali"; string Arg3 = "Boy"; string Arg4 = "Mohammad Ali"; verify_case(0, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "Mohammad Reza"; string Arg1 = "Yasaman Sadat"; string Arg2 = "Baqer Ali"; string Arg3 = "Girl"; string Arg4 = "Sadat Yasaman"; verify_case(1, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "Mohammad Reza"; string Arg1 = "Yasaman Sadat"; string Arg2 = "Umi Kulsum"; string Arg3 = "Girl"; string Arg4 = "Yasaman Kulsum"; verify_case(2, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "Mohammad Reza"; string Arg1 = "Yasaman Sadat"; string Arg2 = "Umi Kulsum"; string Arg3 = "Boy"; string Arg4 = "Reza Mohammad"; verify_case(3, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "Mohammad Ali"; string Arg1 = "Yasaman Sadat"; string Arg2 = "Mohammad Reza"; string Arg3 = "Boy"; string Arg4 = "Mohammad Reza"; verify_case(4, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "Dhikrullah Ali"; string Arg1 = "Umi Kulsum"; string Arg2 = "Reza Hosseinzadeh"; string Arg3 = "Boy"; string Arg4 = "Dhikrullah Hosseinzadeh"; verify_case(5, Arg4, getName(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AqaAsadiNames ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

