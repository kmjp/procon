#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class RearrangeAndIncrement {
	public:
	int X;
	vector<int> ret;
	void go(int v) {
		if(v!=ret.back()) {
			X=v;
			ret.push_back(v);
		}
	}
	int ok(int a,int b) {
		if(b-a>=1&&b-a<=13) return 1;
		string A=to_string(a);
		string B=to_string(b);
		if(B.size()>A.size()) return 0;
		while(B.size()<A.size()) B+="0";
		sort(ALL(A));
		sort(ALL(B));
		return A==B;
	}
	vector <int> change(int X_, int Y) {
		X=X_;
		ret={X};
		int i;
		while(X>1) {
			go(X+(10-X%10));
			string S=to_string(X);
			sort(ALL(S));
			go(atoi(S.c_str()));
		}
		int T=1;
		while(1LL*T*10<=Y) T*=10;
		while(X<T) {
			while(X%10==0) {
				go(X+9);
				string S=to_string(X);
				sort(ALL(S));
				reverse(ALL(S));
				go(atoi(S.c_str()));
			}
			go(X+9);
		}
		
		if(Y%T==0) {
			if(Y>T) {
				int a=Y/T;
				while(X%10==0) {
					go(X+9);
					string S=to_string(X);
					sort(ALL(S));
					reverse(ALL(S));
					go(atoi(S.c_str()));
				}
				go(X+a-2);
				string S=to_string(X);
				sort(ALL(S));
				go(atoi(S.c_str()));
				go(X+1);
			}
		}
		else {
			string TY=to_string(Y);
			for(i=1;i<TY.size();i++) if(TY[i]!='0') {
				string XS=to_string(X);
				XS.back()=TY[i];
				go(atoi(XS.c_str()));
				swap(XS[i],XS.back());
				go(atoi(XS.c_str()));
			}
			if(Y/T>1) {
				int a=Y/T;
				string XS=to_string(X);
				for(i=1;i<XS.size();i++) if(XS[i]!='0') {
					if(i==XS.size()-1) {
						swap(XS[0],XS[i]);
					}
					else {
						swap(XS[0],XS[i]);
						swap(XS[i],XS.back());
					}
					go(atoi(XS.c_str()));
					XS.back()=a+'0';
					go(atoi(XS.c_str()));
					if(i==XS.size()-1) {
						swap(XS[0],XS[i]);
					}
					else {
						swap(XS[i],XS.back());
						swap(XS[0],XS[i]);
						go(atoi(XS.c_str()));
					}
					go(atoi(XS.c_str()));
					break;
				}
				
			}
		}
		
		cout<<"!"<<ret.size()<<endl;
		FOR(i,ret.size()-1) assert(ok(ret[i],ret[i+1]));
		assert(ret.size()<=200);
		assert(ret.back()==Y);
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10234; int Arg1 = 1247; int Arr2[] = {10234, 1234, 1247 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, change(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10234; int Arg1 = 10248; int Arr2[] = {10234, 10244, 10248 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, change(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999997; int Arg1 = 1000001; int Arr2[] = {999997, 999998, 999999, 1000000, 1000001 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, change(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 1000; int Arr2[] = {1000000, 1000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, change(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1111111; int Arg1 = 1111232; int Arr2[] = {1111111, 1111122, 1111221, 1111232 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, change(Arg0, Arg1)); }
	void test_case_5_() { int Arg0 = 47; int Arg1 = 47; int Arr2[] = {47 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, change(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 123456789; int Arg1 = 200000; int Arr2[] = {47 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, change(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RearrangeAndIncrement ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

