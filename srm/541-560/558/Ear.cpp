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


class Ear {
	public:
	vector<int> vrx,vbx,vby;
	char str[3000];
	
	long long calc(int P,int Q) {
		long long px,py,qx,qy;
		long long pbl,pbr;
		int pl,pr,i,c;
		int ql, qr;
		long long lc,rc;
		int res,N;
		
		N=vrx.size();
		px=vbx[P];
		qx=vbx[Q];
		py=vby[P];
		qy=vby[Q];
		if(py<=qy) return 0;
		
		if(px<=qx) {
			pbl=px*(py-qy);
			pbr=px*(py-qy) + (qx-px)*(py);
		}
		else {
			pbl=px*(py-qy) + (qx-px)*(py);
			pbr=px*(py-qy);
		}
		
		ql=-1;
		qr=1000;
		pl=-1;
		pr=1000;
		FOR(i,vrx.size()) {
			if(vrx[i]*(py-qy)<pbl) pl=i;
			if(vrx[i]*(py-qy)>pbr && pr==1000) pr=i;
			if(vrx[i]<qx) ql=i;
			if(vrx[i]>qx && qr==1000) qr=i;
		}
		if(pl<0 || pr==1000 || ql<0 || qr==1000) return 0;
		
		lc=rc=0;
		for(i=1;i<=ql;i++) {
			lc += max(min(i,pl+1),0);
		}
		for(i=qr;i<=N-2;i++) {
			rc += max(min(N-i-1,N-pr),0);
		}
		//_P("%d %d %lld %lld '%d %d %d %d\n",P,Q,lc,rc,ql,qr,pl,pr);
		return lc*rc;
		
	}
	
	
	long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
		string rx,bx,by;
		char* pc;
		int i;
		rx=redX[0];
		bx=blueX[0];
		by=blueY[0];
		for(i=1;i<redX.size();i++) rx += redX[i];
		for(i=1;i<blueX.size();i++) bx += blueX[i];
		for(i=1;i<blueY.size();i++) by += blueY[i];
		
		vrx.clear();
		vbx.clear();
		vby.clear();
		
		strcpy(str,rx.c_str());
		pc = strtok(str," ");
		while(pc) {
			vrx.push_back(atoi(pc));
			pc=strtok(NULL," ");
		}
		
		strcpy(str,bx.c_str());
		pc = strtok(str," ");
		while(pc) {
			vbx.push_back(atoi(pc));
			pc=strtok(NULL," ");
		}
		
		strcpy(str,by.c_str());
		pc = strtok(str," ");
		while(pc) {
			vby.push_back(atoi(pc));
			pc=strtok(NULL," ");
		}
		
		sort(vrx.begin(),vrx.end());
		
		long long res=0,x,y;
		FOR(x,vbx.size()) {
			FOR(y,vbx.size()) {
				res += calc(x,y);
			}
		}
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2 6 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 6 8 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 5 4 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 4LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10000 9999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10000 9999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"15", "0 250 ", "349"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4", " ", "5", " ", "6", " 7 ", "8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1", " 2 ", "3 4", " 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 204LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }
	//void test_case_5() { string Arr0[] = {"47 106 101 130 224 149 283 53 81 267 131 39 200 14", "3 138 139 145 258 248 63 180 197 19 161 88 261 260", " 264 11 84 116 133 91 40 30 87 208 167 56 204 246 ", "49 194 72 207 228 21 187 75 9 250 113 216 86 95 8 ", "71 238 36 147 76 4 288 23 171 205 44 64 213 65 210", " 157 286 191 85 46 80 107 24 263 166 124 14 245 25", "3 190 62 175 99 215 233 284 221 110 35 257 119 137", " 195 42 68 281 141 100 7 184 278 126 43 2 169 140 ", "128 13 206 230 214 189 18 150 199 5 274 12 152 117", " 293 144 134 203 16 160 6 109 55 89 219 78 31 198 ", "223 231 83 41 142 77 164 59 153 22 280 247 244 45 ", "241 183 25 92 57 269 52 61 136 186 188 51 271 34 2", "12 165 155 237 27 146 277 178 292 60 173 90 211 98", " 259 299 129 181 285 67 291 179 93 122 229 170 209", " 227 296 236 82 235 3 108 1 15 176 158 217 255 114", " 234 225 174 20 50 279 148 239 201 70 294 115 202 ", "251 79 132 182 252 254 297 74 168 32 121 226 273 1", "96 94 287 123 104 242 193 276 270 26 185 290 111 2", "65 172 28 249 192 127 17 33 275 135 289 105 298 15", "6 163 96 66 266 118 300 54 48 69 102 268 112 73 17", "7 295 151 222 10 218 97 58 256 125 29 162 272 243 ", "159 103 38 240 120 262 282 37 220 232 154"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] =  {"130 45 79 167 48 50 208 270 94 88 6 153 89 93 232 ", "144 91 195 294 128 9 264 141 276 15 113 105 26 151", " 27 209 254 212 159 299 115 188 249 85 177 87 135 ", "21 12 216 96 41 86 171 181 278 59 246 192 84 129 7", "0 231 269 4 103 240 238 133 76 266 137 168 173 290", " 32 214 5 218 46 147 182 78 245 160 282 271 18 215", " 74 179 279 119 292 102 275 127 201 82 22 222 228 ", "62 61 229 29 126 287 25 189 162 248 233 114 145 22", "7 13 142 196 121 31 180 184 131 169 175 107 92 244", " 277 80 176 14 24 235 118 124 185 140 211 207 117 ", "170 10 236 250 37 260 42 165 268 257 58 243 143 17", " 68 225 297 47 221 166 1 286 52 39 122 252 178 283", " 202 65 224 210 7 291 186 258 35 8 247 54 265 71 1", "93 156 190 298 157 2 20 194 134 33 154 109 274 263", " 273 11 150 110 242 81 49 123 204 125 104 64 288 2", "56 158 67 51 293 251 217 77 146 149 267 261 259 34", " 234 44 23 98 199 152 205 112 148 281 111 101 28 2", "80 164 106 138 3 284 219 73 191 253 213 226 66 161", " 60 262 99 100 295 223 198 36 289 19 56 63 108 38 ", "75 203 57 90 83 120 172 183 132 95 40 139 220 43 5", "5 136 300 187 239 206 16 230 200 285 237 69 116 16", "3 296 174 197 97 255 30 155 72 272 53 241"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"111 291 12 70 210 143 18 294 165 102 116 40 109 3 ", "76 282 60 167 154 117 144 87 58 134 170 193 28 276", " 105 214 31 97 274 289 253 115 72 287 202 281 67 2", "28 227 80 260 177 107 1 286 271 183 166 164 44 17 ", "203 50 106 150 133 172 250 142 238 54 283 9 34 169", " 16 26 178 197 32 83 213 248 232 256 288 24 123 78", " 20 127 45 121 132 195 2 239 265 5 219 158 6 226 1", "94 156 180 266 233 181 249 141 252 189 11 224 114 ", "93 49 62 128 191 68 264 125 64 244 159 160 75 55 1", "52 192 201 204 298 25 4 126 247 205 188 51 63 284 ", "245 171 119 206 182 155 47 13 100 237 241 148 234 ", "173 267 33 211 162 157 179 222 79 86 136 146 53 21", "2 29 277 42 38 15 23 30 35 186 251 37 268 269 196 ", "145 65 236 296 243 218 221 122 95 279 273 208 124 ", "151 295 98 209 71 85 187 7 225 10 61 176 163 129 1", "30 88 138 290 262 27 242 280 246 139 73 46 22 261 ", "278 94 270 84 161 199 104 81 77 74 168 292 216 220", " 120 257 198 185 223 175 255 215 113 207 263 48 21", "7 112 149 275 230 101 131 56 285 293 36 153 59 297", " 43 92 99 41 272 8 135 82 254 39 231 96 21 14 184 ", "137 19 174 240 259 140 57 229 147 300 258 103 118 ", "69 235 52 108 91 299 66 89 90 200 110 190"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  Ear ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
