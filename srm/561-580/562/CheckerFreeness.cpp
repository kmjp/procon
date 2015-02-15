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


class CheckerFreeness {
	public:
	string concatvec(vector <string> expr) {
		int i;
		string st="";
		FOR(i,expr.size()) st += expr[i];
		return st;
	}
	vector<int> split_int(const string &str, char delim){
		vector<int> res;
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
	
	vector< pair<int, int> > wp;
	vector< pair<int, int> > bp;
	vector<int> wi,bi;
	
	vector<int> wx,wy,bx,by;
	int nw,nb;
	
	
	int ischecker(int w1,int w2,int b1,int b2) {
		ll dx,dy,t1x,t1y,t2x,t2y,cr1,cr2;
		int i;
		
		dx = wx[w2]-wx[w1];
		dy = wy[w2]-wy[w1];
		t1x = bx[b1]-wx[w1];
		t1y = by[b1]-wy[w1];
		t2x = bx[b2]-wx[w1];
		t2y = by[b2]-wy[w1];
		
		cr1 = ((t1x*dy-t1y*dx)>0)?1:-1;
		cr2 = ((t2x*dy-t2y*dx)>0)?1:-1;
		if(cr1==cr2) return 0;
		
		dx = bx[b2]-bx[b1];
		dy = by[b2]-by[b1];
		t1x = wx[w1]-bx[b1];
		t1y = wy[w1]-by[b1];
		t2x = wx[w2]-bx[b1];
		t2y = wy[w2]-by[b1];
		
		cr1 = ((t1x*dy-t1y*dx)>0)?1:-1;
		cr2 = ((t2x*dy-t2y*dx)>0)?1:-1;
		if(cr1==cr2) return 0;
		
		return 1;
	}
	
	ll veccross(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3) {
		p3.first-=p1.first;p2.first-=p1.first;
		p3.second-=p1.second;p2.second-=p1.second;
		return p3.first*(ll)p2.second-p2.first*(ll)p3.second;
	}
	vector<int> convex_hull(vector< pair<int, int> >& vp) {
		vector<pair<pair<int, int>, int> > sorted;
		vector<int> res;
		int i,k=0,rb;
		FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
		sort(sorted.begin(),sorted.end());
		res.resize(vp.size()*2);
		/* bottom */
		FOR(i,vp.size()) {
			while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
			res[k++]=sorted[i].second;
		}
		/* top */
		for(rb=k, i=vp.size()-2;i>=0;i--) {
			while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
			res[k++]=sorted[i].second;
		}
		res.resize(k-1);
		return res;
	}
	
	string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
		wx = split_int(concatvec(whiteX),' ');
		wy = split_int(concatvec(whiteY),' ');
		bx = split_int(concatvec(blackX),' ');
		by = split_int(concatvec(blackY),' ');
		nw = wx.size();
		nb = bx.size();
		
		int i;
		wp.clear();
		bp.clear();
		FOR(i,wx.size()) wp.push_back(make_pair(wx[i],wy[i]));
		FOR(i,bx.size()) bp.push_back(make_pair(bx[i],by[i]));
		
		sort(wp.begin(),wp.end());
		sort(bp.begin(),bp.end());
		
		
		wi = convex_hull(wp);
		//FOR(i,wi.size()) _P("%3d:{%3d (%7d,%7d)}\n",i,wi[i],wp[wi[i]].first,wp[wi[i]].second);
		bi = convex_hull(bp);
		//FOR(i,bi.size()) _P("%3d:{%3d (%7d,%7d)}\n",i,bi[i],bp[bi[i]].first,bp[bi[i]].second);
		
		int w1,w2,b1,b2;
		FOR(w1,wi.size()) FOR(b1,nb) for(b2=b1+1;b2<nb;b2++) {
			if(ischecker(wi[w1],wi[(w1+1)%wi.size()],b1,b2)) return "NO";
		}
		FOR(b1,bi.size()) FOR(w1,nw) for(w2=w1+1;w2<nw;w2++) {
			if(ischecker(w1,w2,bi[b1],bi[(b1+1)%bi.size()])) return "NO";
		}
		
		
		
		/*
		
		int w1,w2,b1,b2;
		FOR(w1,nw) for(w2=w1+1;w2<nw;w2++) {
			FOR(b1,nb) for(b2=b1+1;b2<nb;b2++) {
				if(ischecker(w1,w2,b1,b2)) return "NO";
			}
		}
		*/
		
		return "YES";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(0, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"2", "5", "3", " ", "1", "7", "3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"180 254"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"32", "5 1", "42"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"462 423"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(1, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1 10000000 9999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 9999999 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 5000000 9999998"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2 5000001 9999999"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(2, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(3, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(4, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"219211 1996214 1706774 3634920 909831 1774128 8503"
,"52 2233050 2099138 3380396 1128982 3682525 1483700"
," 763080 487867 8203 1791027 463556 1103323 1406861"
," 6374234 760949 4340236 727393 2073832 1289052 103"
,"8147 4448130 151066 412440 1068735 377239 2677933 "
,"1299598 339843 289973 3707319 555280 230418 431719"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1638083 5698739 3105504 9726902 9745795 5049444 15"
,"80592 3952120 6606668 7460527 7239299 8726128 4913"
,"547 6264100 5701660 8865937 4969114 8014845 327236"
,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
,"5832197 1571976 8779325 3306446 948271 5133709 949"
,"394 6919798 7525636 3568024 6833196 9237472 733313"
,"1 9939064 9720014"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"5860334 8007503 7455523 4864927 9573526 2718360 81"
,"12104 6684287 9921506 4840886 5415948 3451454 5320"
,"996 9268757 9261724 8254668 2292750 8035828 233352"
,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
,"5569360 8519168 3100295 9351613 7733878 7579030 32"
,"46775 7297460 8370542 7099759 5782969 2978083 3390"
,"488 7482758 1332401 6094629 9717305 5503121 572842"
,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
,"4111694 5171296 6847697 4601273 7599828 5515929 94"
,"60593 9332762 5389080 4512091 8668538 5711743 5838"
,"534 4825079 8145628 3810005 2964724 5594550 785748"
,"3 6283769"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"5911694 8009943 212555 5838688 9896256 607434 5857"
,"663 4616750 1477573 7168026 3090917 4379806 326465"
,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
,"360 3344176 3223317 2624498 4883494 1532240 732937"
,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
,"623264 8830827 2030444 3002706 83058 4475866 20876"
,"25 1790695 4034441 5409379 3571098 4600050 736561 "
,"250475 3733256 3011439 2144994 4523046 3119883 607"
,"582 8361403 6525451 7518329 926803 4884524 8424659"
," 7088689 5762049 9532481 4914186 7314621 4339084 3"
,"741685 3837953 3177252 612550 9688871 5872931"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(5, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  CheckerFreeness ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
