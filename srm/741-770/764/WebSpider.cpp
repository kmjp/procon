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

class WebSpider {
	public:
	
	vector<string> split(string V) {
		vector<string> R;
		R.push_back("");
		FORR(c,V) {
			if(c=='/') {
				R.push_back("");
			}
			else {
				R.back()+=c;
			}
		}
		return R;
	}
	
	int countPages(vector <string> firstPass, vector <string> secondPass, vector <string> thirdPass) {
		set<vector<string>> S;
		
		vector<vector<string>> V,V2;
		FORR(s,firstPass) {
			V.push_back(split(s));
			S.insert(V.back());
		}
		
		FORR(s,secondPass) {
			int v=0;
			while(s[0]!=' ') {
				v=v*10+s[0]-'0';
				s=s.substr(1);
			}
			s=s.substr(1);
			vector<string> A=V[v];
			A.pop_back();
			vector<string> B=split(s);
			while(B[0]=="..") {
				B.erase(B.begin());
				A.pop_back();
			}
			FORR(b,B) A.push_back(b);
			V2.push_back(A);
			S.insert(A);
		}
		
		FORR(s,thirdPass) {
			int v=0;
			while(s[0]!=' ') {
				v=v*10+s[0]-'0';
				s=s.substr(1);
			}
			s=s.substr(1);
			vector<string> A=V2[v];
			A.pop_back();
			vector<string> B=split(s);
			while(B[0]=="..") {
				B.erase(B.begin());
				A.pop_back();
			}
			FORR(b,B) A.push_back(b);
			S.insert(A);
		}
		return S.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"home.htm", "sitemap.htm", "contact.htm", "support/login.jsp"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 locations.htm", "3 ../home.htm"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 contact.htm"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"index.html","products/all/INDEX.HTML","images/products/A101.GIF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 ../../index.html","1 ../../products"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {".rc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(2, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 ../a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a",
 "0 ..a/a",
 "0 a../a.."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(3, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"abc/ccba","ab/cba","..a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 cba","1 ccba"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 cba","1 ccba"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"a","ab/ab","ab/ab/abc","abc/abc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 ab/ab","1 ab","1 ../ab/ab","2 ../../ab/abc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 ../ab/ab","2 ../abc/abc","1 ab/ab"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(5, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a/a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 ../../../../../../../../a/a/a/a/a/a/a/a/a"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(6, Arg3, countPages(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {"index.asp", "contact.asp", "about/index.asp", "users/support.asp",
 "company/executiveteam.asp", "products/catalog.asp"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 index.asp", "1 requestinfo.asp", "2 ../index.asp", "2 history.asp",
"3 ../index.asp", "3 helpdesk.asp", "4 ../index.asp", "4 boardofdirectors.asp",
"4 location.asp", "5 ../index.asp", "5 new/index.asp",  "5 ../index.asp", "5 sale.asp"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10 ../../index.asp", "11 products/index.asp", "11 products/catalog.asp"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 14; verify_case(7, Arg3, countPages(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  WebSpider ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

