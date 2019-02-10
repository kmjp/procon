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

string S[]={
"one",
"ten",
"hundred",
"myriad",
"myllion",
"byllion",
"tryllion",
"quadryllion",
"quintyllion",
"sextyllion",
"septyllion",
"octyllion",
"nonyllion",
"decyllion",
};

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

class Yllion {
	public:
	string getPower(string a, string b) {
		map<string,int> M;
		int i;
		M["one"]=0;
		M["ten"]=1;
		for(i=2;i<=13;i++) M[S[i]]=1<<(i-1);
		
		int A=0;
		auto as=split(a);
		auto bs=split(b);
		FORR(a,as) A+=M[a];
		cout<<A<<" ";
		FORR(b,bs) A+=M[b];
		cout<<A<<endl;
		
		string R=S[A%2];
		for(i=2;i<=13;i++) if(A&(1<<(i-1))) R+=" "+S[i];
		return R;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "one"; string Arg1 = "one"; string Arg2 = "one"; verify_case(0, Arg2, getPower(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "one"; string Arg1 = "ten"; string Arg2 = "ten"; verify_case(1, Arg2, getPower(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "one hundred"; string Arg1 = "one hundred"; string Arg2 = "one myriad"; verify_case(2, Arg2, getPower(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ten hundred"; string Arg1 = "one hundred"; string Arg2 = "ten myriad"; verify_case(3, Arg2, getPower(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ten hundred myriad myllion"; string Arg1 = "one hundred myllion tryllion"; string Arg2 = "ten myllion byllion tryllion"; verify_case(4, Arg2, getPower(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ten hundred myriad myllion byllion tryllion quadryllion quintyllion sextyllion septyllion octyllion nonyllion"; string Arg1 = "ten"; string Arg2 = "one decyllion"; verify_case(5, Arg2, getPower(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Yllion ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

