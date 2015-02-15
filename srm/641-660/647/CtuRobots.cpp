#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

pair<int,int> P[502];
double dp[2][10002];

class CtuRobots {
	public:
	double maxDist(int B, vector <int> cost, vector <int> cap) {
		int i,x,y;
		
		int N=cost.size();
		FOR(i,N) P[i]=make_pair(cap[i],cost[i]);
		sort(P,P+N);
		
		FOR(i,B+1) dp[0][i]=-1;
		double ma=0;
		dp[0][B]=0;
		FOR(i,N) {
			int cur=i%2,tar=cur^1;
			FOR(x,B+1) dp[tar][x]=-1;
			FOR(x,B+1) if(dp[cur][x]>=0) {
				dp[tar][x]=max(dp[tar][x],dp[cur][x]);
				if(x>=P[i].second) {
					dp[tar][x-P[i].second]=max(dp[tar][x-P[i].second],P[i].first+dp[cur][x]/3);
					ma=max(ma,dp[tar][x-P[i].second]);
				}
			}
		}
		
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arr1[] = {50,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.6666666666666666; verify_case(0, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 25; int Arr1[] = {23,5,8,20,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {108,30,42,100,94}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 55.0; verify_case(1, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1382; int Arr1[] = {0,0,0,1000,1000,0,1000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2039,4819,5923,1577,8749,9182,3652,4918}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 6503.238683127572; verify_case(2, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 209; int Arr1[] = {185,130,109,1,45,117,127,13,2,37,6,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93,5,278,4,20,54,93,213,103,5,225,32,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 190.48376771833563; verify_case(3, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9956; int Arr1[] = {3229,736,1325,2680,410,1227,1378,499,1525,1722,1262,2080,2581,1505,1019,
480,3155,836,2697,616,136,2032,2345,3154,1953,1654,344,3079,1426,199,2857,
1714,2952,996,1567,2674,2054,2110,949,2412,2148,1016,234,1932,1554,1943,
1625,1266,258,2924,49,1693,3140,309,557,12,2760,227,2497,330,646,1935,3032,
2671,2433,164,1472,3080,717,221,2483,1309,1174,12,917,2335,3086,148,64,189,
2628,1660,2983,109,1920,2470}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {934850,214,15807606,2426,176520,1900009,1184867,40550,1774843,2953,77834310,
7276,3139890,695,213862217,13,193864,189,557664,1206555,85133,381662,4887,
115027,2186890,218075,1,2024,9,95244962,7,906,3485642,52962078,58645759,785706,
303,18,189,819600,17528041,11616471,92719012,82351,12752,634,26122233,215485,
58,5506810,101874,130429471,2,1,68966,76303,321766922,463,26,225,207,52,1739,
246841,496,228,4749453,191,79,10560,1414194,7529,13,521935,1,2,11590618,4020,
105,3,28,3,2855,189909573,1,295052}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2.1034261053998655E8; verify_case(4, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 8852; int Arr1[] = {2547,912,2592,1085,296,523,2257,2347,1822,261,334,2159,528,2739,201,964,427,
2038,26,2361,234,2063,2885,2178,2708,730,2902,326,306,2794,1725,13,137,2169,
388,1124,1464,2120,2357,1544,2794,2260,185,650,2852,124,1767,453,1331,1397,
1991,1166,413,1428,2862,1194,1139,571,1299,1232,267,2027,746,1971,2695,2586,
185,1319,1088,2818,2604,1798,475,1252,1767,2277,545,601,2160,325,2749,1161,
1172,1075,1925,2468,1596,1116,1558,2226,1302,796,775,1105,418,334,2872,1921,
2830,2448,2914,2634,1386,2516,492,1029,1134,2934,2017,1741,1675,2593,2233,
2401,68,683,2053,155,183,923,2276,1823,65,2290,2448,92,2468,819,837,303,1440,
705,291,2348,2562,765,1926,14,2514,2403,2671,1143,1358,121,376,2874,2447,1769,
1686,967,967,2492,2472,2014,1686,2291,1093,1801,818}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {263268,256181,476791,365614,265352,19307,243180,84909,98175,367524,241474,479623,
277638,111229,155356,415525,234382,97870,451466,58375,268277,404582,484789,458230,
529286,449840,103208,199505,319373,294746,78005,326456,14418,257144,135669,238651,
411723,99122,20421,298154,278407,153564,24778,73065,110408,392693,510192,362399,
333830,125893,130946,345134,261418,230632,306751,451242,175675,459988,150787,349338,
134594,255227,263645,180770,436965,502871,242085,318340,220576,189202,395789,390659,
101649,337117,440471,466547,513054,316694,30382,38826,472506,67698,223953,397305,
325564,57949,194651,443500,443188,431386,220061,400640,286085,189461,324214,171813,
420711,260549,426526,208052,83343,429483,366076,52443,224742,333286,544259,335276,
93282,326772,82841,225256,270357,547610,397526,193336,182374,439866,255860,111363,
509167,228847,218257,39438,212242,378338,88972,127544,59230,428847,155553,116333,
255176,396356,223463,226360,38283,6238,173455,447707,332111,60485,398523,462205,
55397,148417,529738,460063,177715,404809,336155,50750,24165,530386,394811,512481,
230296,45797,370008}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 408339.73124862404; verify_case(5, Arg3, maxDist(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CtuRobots ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
