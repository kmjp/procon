#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class StringGame {
	int L;
	int num[60][26];
	vector<string> Ss;
	public:
	int ok(int cur) {
		int i,j;
		vector<int> cand,c2;
		int vis[26];
		
		ZERO(vis);
		FOR(i,Ss.size()) if(i!=cur) cand.push_back(i);
		
		while(!cand.empty()) {
			int can=-1;
			FOR(i,26) {
				if(vis[i] || num[cur][i]==0) continue;
				int ok=1;
				FOR(j,cand.size()) if(num[cur][i]<num[cand[j]][i]) ok=0;
				if(ok) {
					can=i;
					break;
				}
			}
			if(can<0) return 0;
			
			vis[can]=1;
			c2=cand;
			cand.clear();
			FOR(i,c2.size()) if(num[cur][can]==num[c2[i]][can]) cand.push_back(c2[i]);
		}
		return 1;
	}
	
	
	vector <int> getWinningStrings(vector <string> S) {
		int i,x,y;
		vector<int> res;
		Ss=S;
		L=S[0].size();
		res.clear();
		
		ZERO(num);
		FOR(x,S.size()) FOR(y,L) num[x][S[x][y]-'a']++;
		
		FOR(i,S.size()) if(ok(i)) res.push_back(i);
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a", "b", "c", "d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinningStrings(Arg0)); }
	void test_case_1() { string Arr0[] = {"aabbcc", "aaabbb", "aaaccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinningStrings(Arg0)); }
	void test_case_2() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinningStrings(Arg0)); }
	void test_case_4() { string Arr0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinningStrings(Arg0)); }
	void test_case_3() { string Arr0[] = {"eygrkrbhoxcjajdycdmaacfajwfhsdajamwllvsdba", "omtacrszvbxtpbsyttsekjkizruiyffhrtbciiyklt", "xvygpxduqiwvescupbytfyzznckfupzmrudhdfegnm", "ricuijrexvhhjhhizffzkihygjmnmbawbklmjamcij", "ulbsaotriaipkmbjythyrwrfsafbjmebaankuquckd", "nhjwpqjrgotolarjbiigfaeattqdolxjcfpftrxyzj", "quhpjdicsprirvytjjwjgjnodelodecufffsdzsjtz", "jvhwefuqillweimfidcgoixlfvzjpxowofcyscupxa", "jmzqxgknkgorcfpkwlvmmqbplwepppokrdryxshcwt", "skseeyqjzcxrwucznjtoztjhgazefvjpelwizweplq", "tswyanqqfdzjibbfepfglaypufqbigmbbhvvdschag", "orrjhsnikibriklsdtetzmgapsejcrmukbwatpndkq", "gzevhcrylmtzetitqbkaslsmxulcjxqwfyzxmiazbo", "esyzrkscfdmbwszyrbnwstozvsnqstxhiqsxkrodlm", "wcyyrdyruytnfxtubcwmtpmuruurbiqvjbyprgwggn", "wpumdfzsvxutvyjcijjyoswagbuviwoxrqwpfoitdg", "owlehwdgekmalschioozaydinhewkswqryapndivzl", "fsrwwkdgfvmgjrrmddbiaqpytbwdthwwoxdjbshcsy", "lvwmclaqmrbbftfcqmcufxivxwurqljuketzkyqbvt", "dlbngvdhcjqtztgoorzxijsqcdjsiceceokxhierrz", "oxamlcnhuhxnsljqxioobogesjjsiwrmjatixwpoqf", "jfdfqyplaazyoyleasbhxrwdtpvpdripokszzusxqa", "eztxaazzljbqjczpipzrqhjaldovcmnjtbvqaugetl", "auuspotdwjcyppafdvqefsffddrcnwnhtxswqgdvbp", "wuystkxkqlxhscnscxsyclqychjiavqfvqvdamqmtp", "wgybrpjxbvcqmqzdobyaibtuwwwiczshqayzqgddso", "nzxogbasejtkpbpaboegbmzaqebrhqhlijxlkqqbjb", "oxblauzdxrkfhvoyhhblvoweukxsxgnqaglkyzkbhn", "lvwiiqzjywaumylpvwkzuesihsujyhlcgusbdvinit", "eidgaitabqirvyrzjfkllptnoalolsemuaolaooazm", "fgzrklejesqqwzgqbzigllrfmqcvihywuzxfmfgjmd", "ngxegszwkpjrjzfqlffzbtinnzeqdvahyojlwqoztc", "zkwxhiyhuqaweahnxebnngzrvtyupsbcdyhnwgslac"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 6, 8, 9, 13, 14, 17, 19, 20, 22, 23, 24, 26, 27, 28, 31, 32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinningStrings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  StringGame ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
