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

typedef signed long long s64;
typedef unsigned long long u64;

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


class LeftRightDigitsGame2 {
	public:
	int N;
	string D;
	string L;
	string res;
	map<string,string> mp;
	map< pair<string, string>, string> mr;
	
	//1を足す
	string inc(string str) {
		int i,j;
		
		FOR(j,str.size()) {
			i = str.size()-1-j;
			if(str[i]=='9') str[i]='0';
			else {
				str[i]++;
				break;
			}
		}
		if(j==str.size()) return "";
		return str;
	}
	
	//最小文字列を探す
	string minstr(string str) {
		string res=string(str.size(),'a');
		string tres,l,r;
		int i,n,c;
		char mc='9';
		
		//最小
		n=str.size();
		if(n<=1) return str;
		FOR(i,n) if(str[i]<mc) mc=str[i];
		
		//同じ文字だけなら省略
		c=0;
		FOR(i,n) if(str[i]==mc) c++;
		if(c==n) return str;
		
		if(mp.find(str) != mp.end()) return mp[str];
		
		//mcが先頭にくる中で最小
		FOR(i,n) if(str[i]==mc) {
			l = minstr(str.substr(0,i));
			r = str.substr(i+1);
			tres = mc + l + r;
			if(tres<res) res = tres;
		}
		//_P("%s -> %s\n",str.c_str(),res.c_str());
		mp[str]=res;
		return res;
	}
	
	string func(string ld,string lb,bool ok0) {
		
		if(ld.size()==0) return "";
		if(ld.size()==1) {
			if(ok0==false && ld[0]=='0') return "a";
			if(ld[0]>=lb[0]) return ld;
			return "a";
		}
		
		string res = string(ld.size(),'a');
		string tres,lld,llb;
		
		//全部同じ？
		if(ld == string(ld.size(),ld[0])) {
			if(ld>=lb) return ld;
			return res;
		}
		pair<string, string> k = make_pair(ld,lb);
		if(ok0 && mr.find(k)!=mr.end()) return mr[k];
		
		//最後の文字で判定
		char c = ld[ld.size()-1];
		//左
		if(ok0 || c!='0') {
			lld = ld.substr(0,ld.size()-1);
			if(c==lb[0]) {
				//残り文字が満たすか？0もok
				llb = lb.substr(1);
				//_P("call left %s %s -> %s %s\n",ld.c_str(),lb.c_str(),lld.c_str(),llb.c_str());
				tres = c + func(lld,llb,true);
				if(tres.find('a',0) == string::npos && tres < res && tres>=lb) res=tres;
			}
			else if(c>lb[0]) {
				//残り文字で最小
				//_P("call min %s %s -> %s\n",ld.c_str(),lb.c_str(),lld.c_str());
				tres = c + minstr(lld);
				if(tres.find('a',0) == string::npos && tres < res && tres>=lb) res=tres;
			}
		}
		//右
		llb = lb.substr(0,lb.size()-1);
		lld = ld.substr(0,ld.size()-1);
		//繰り上がり
		if(c<lb[lb.size()-1]) llb=inc(llb);
		
		if(llb.size()>0) {
			//_P("call right %s %s -> %s %s\n",ld.c_str(),lb.c_str(),lld.c_str(),llb.c_str());
			tres = func(lld,llb,ok0) + c;
			if(tres.find('a',0) == string::npos && tres < res && tres>=lb) res=tres;
		}
		//_P("%s %s : %s\n",ld.c_str(),lb.c_str(),res.c_str());
		if(ok0) mr[k]=res;
		return res;
	}
	
	string minNumber(string digits, string lowerBound) {
		string res;
		D=digits;
		L=lowerBound;
		N=digits.size();
		mp.clear();
		mr.clear();
		
		res = func(D,L,false);
		
		//なかった場合
		if(res[0]=='a') res="";
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "565"; string Arg1 = "556"; string Arg2 = "556"; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "565"; string Arg1 = "566"; string Arg2 = "655"; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "565"; string Arg1 = "656"; string Arg2 = ""; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "9876543210"; string Arg1 = "5565565565"; string Arg2 = "5678943210"; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }
	//void test_case_4() { string Arg0 = "8016352"; string Arg1 = "1000000"; string Arg2 = "1086352"; verify_case(4, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "11011001001111100000100111000101110001101101100011"; string Arg1 = "10011110001010101101011101000111100101111011111110"; string Arg2 = "10011110001010101101011101001110000001110011001101"; verify_case(4, Arg2, minNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  LeftRightDigitsGame2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
