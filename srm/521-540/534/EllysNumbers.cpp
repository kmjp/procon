#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

vector<ll> split_int(const string &str, char delim){
	vector<ll> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		string s = string(str, current, found - current);
		res.push_back(atoi(s.c_str()));
		current = found + 1;
	}
	string s = string(str, current, str.size() - current);
	res.push_back(atoi(s.c_str()));
	return res;
}
string concatvec(vector <string> expr) { return accumulate(expr.begin(),expr.end(),string("")); }
map<ll,int> enumdiv(ll n) {
	map<ll,int> V;
	while(n%2==0) V[2]++,n/=2;
	for(ll i=3;i*i<=n;i+=2) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

ll dpdp[1<<20];
map<ll,int> T[501];

class EllysNumbers {
	public:
	long long getSubsets(long long n, vector <string> special) {
		int i,mask;
		
		ZERO(dpdp);
		dpdp[0]=1;
		
		vector<ll> S=split_int(concatvec(special),' ');
		sort(S.begin(),S.end());
		
		set<ll> S2;
		map<ll,int> D;
		
		FOR(i,S.size()) {
			T[i] = enumdiv(S[i]);
			ITR(it,T[i]) S2.insert(it->first);
		}
		
		ITR(it,S2) while(n%*it==0) D[*it]++, n/=*it;
		if(n>1) return 0;
		
		map<ll,int> D2;
		ITR(it,D) D2[it->first]=D2.size()-1;
		vector<int> B;
		FOR(i,S.size()) {
			int nm=0,ng=0;
			ITR(it,T[i]) {
				if(D.find(it->first)==D.end()) ng++;
				else {
					ng += D[it->first]!=it->second;
					nm |= 1<<D2[it->first];
				}
			}
			if(ng==0) B.push_back(nm);
		}
		FOR(i,B.size()) {
			for(mask=(1<<D.size())-1;mask>=0;mask--) {
				if((mask & B[i])==0) dpdp[mask|B[i]]+=dpdp[mask];
			}
		}
		
		return dpdp[(1<<D.size())-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 12LL; string Arr1[] = {"4 2 5 6 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 42LL; string Arr1[] = {"1 2 3 4 5 6 7 13 14 21 42"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1337LL; string Arr1[] = {"1 13 42 666 2674"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 1073741824LL; string Arr1[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
 "6384 32768 65536 131072 262144 524288 1048576 2097",
 "152 4194304 8388608 16777216 33554432 67108864 134",
 "217728 268435456 536870912"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_42() { long long Arg0 = 7420738134810LL; string Arr1[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
 "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
 "476379795 1001 5 435274114 38264554 7429 239906525",
 " 3 227183706 887045414 606786670 3795 797605175 29",
 " 30 747186719 19 2 562347843 74 2294 588002688 743",
 "6429 703 591740547 36657492 37 444178205 1002001 2",
 "17626404"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 110LL; verify_case(4, Arg2, getSubsets(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 614889782588491410; string Arr1[] = {"1 2 3 5 6 7 10 11 13 14 15 17 19 21 22 23 26 29 30", " 31 33 34 35 37 38 39 41 42 43 46 47 51 55 57 58 6", "2 65 66 69 70 74 77 78 82 85 86 87 91 93 94 95 102", " 105 110 111 114 115 119 123 129 130 133 138 141 1", "43 145 154 155 161 165 170 174 182 185 186 187 190", " 195 203 205 209 210 215 217 221 222 230 231 235 2", "38 246 247 253 255 258 259 266 273 282 285 286 287", " 290 299 301 310 319 322 323 329 330 341 345 357 3", "70 374 377 385 390 391 399 403 406 407 410 418 429", " 430 434 435 437 442 451 455 462 465 470 473 481 4", "83 493 494 506 510 517 518 527 533 546 551 555 559", " 561 570 574 589 595 598 602 609 611 615 627 629 6", "38 645 646 651 658 663 665 667 682 690 697 703 705", " 713 714 715 731 741 754 759 770 777 779 782 798 7", "99 805 806 814 817 851 858 861 870 874 893 897 899", " 902 903 910 930 935 943 946 957 962 966 969 986 9", "87 989 1001 1015 1023 1034 1045 1054 1066 1073 108", "1 1085 1102 1105 1110 1118 1122 1131 1147 1155 117", "3 1178 1189 1190 1209 1218 1221 1222 1230 1235 124", "7 1254 1258 1265 1271 1290 1295 1302 1309 1311 132", "6 1330 1333 1334 1353 1363 1365 1394 1406 1410 141", "9 1426 1430 1435 1443 1457 1462 1463 1479 1482 149", "5 1505 1517 1518 1547 1551 1554 1558 1581 1591 159", "5 1598 1599 1610 1615 1634 1645 1653 1677 1702 170", "5 1722 1729 1739 1763 1767 1771 1785 1786 1794 179", "8 1806 1833 1870 1885 1886 1887 1914 1927 1938 195", "5 1974 1978 1995 2001 2002 2015 2021 2030 2035 204", "6 2090 2091 2093 2109 2139 2145 2146 2162 2170 218", "5 2193 2210 2233 2255 2261 2262 2294 2310 2337 234", "6 2365 2378 2387 2397 2405 2415 2418 2431 2442 245", "1 2465 2470 2494 2530 2542 2553 2585 2590 2618 262", "2 2635 2639 2665 2666 2679 2697 2706 2717 2726 273", "0 2737 2755 2795 2805 2821 2829 2838 2849 2870 288", "6 2914 2926 2945 2958 2967 2990 3003 3010 3034 304", "5 3055 3059 3094 3102 3135 3145 3157 3162 3182 319", "0 3198 3219 3230 3243 3255 3289 3290 3306 3311 331", "5 3335 3354 3367 3410 3441 3451 3458 3478 3485 351", "5 3526 3534 3542 3553 3565 3567 3570 3619 3655 366", "6 3689 3705 3731 3741 3770 3774 3795 3813 3854 385", "7 3885 3895 3910 3913 3927 3990 3995 3999 4002 403", "0 4042 4070 4085 4089 4123 4147 4182 4186 4199 421", "8 4255 4277 4278 4290 4301 4305 4370 4371 4386 438", "9 4403 4433 4465 4466 4485 4495 4510 4515 4522 455", "1 4641 4669 4674 4715 4730 4773 4774 4785 4794 480", "7 4810 4830 4845 4862 4879"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 205672286; verify_case(4, Arg2, getSubsets(Arg0, Arg1)); }



// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysNumbers ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
