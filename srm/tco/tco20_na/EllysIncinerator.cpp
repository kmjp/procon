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

int N;
vector <double> X,Y,R;

class EllysIncinerator {
	public:
	
	int ok2(double cx,double cy,double r) {
		int i;
		if(0>cx||0>cy||cx>1000||cy>1000) return 0;
		
		FOR(i,N) {
			double r2=hypot(X[i]-cx,Y[i]-cy);
			if(r2<R[i]+r-(1e-9)) return 0;
		}
		return 1;
	}
	
	int ok(int a,int b,double D) {
		double r=hypot(X[a]-X[b],Y[a]-Y[b]);
		
		double tx,ty;
		
		if(r>R[a]+R[b]+2*D) {
			double dx=X[b]-X[a];
			double dy=Y[b]-Y[a];
			double dl=hypot(dx,dy);
			dx/=dl;
			dy/=dl;
			dx=X[a]+dx*(R[a]+D);
			dy=Y[a]+dy*(R[a]+D);
			if(ok2(dx,dy,D)) return 1;
		}
		else {
			double dx=X[b]-X[a];
			double dy=Y[b]-Y[a];
			double r1=R[a]+D;
			double r2=R[b]+D;
			double A=(dx*dx+dy*dy+r1*r1-r2*r2)/2;
			double d=(dx*dx+dy*dy)*r1*r1-A*A+1e-9;
			if(d<0) d=0;
			
			tx=X[a]+(A*dx+dy*sqrt(d))/(dx*dx+dy*dy);
			ty=Y[a]+(A*dy-dx*sqrt(d))/(dx*dx+dy*dy);
			if(ok2(tx,ty,D)) return 1;
			tx=X[a]+(A*dx-dy*sqrt(d))/(dx*dx+dy*dy);
			ty=Y[a]+(A*dy+dx*sqrt(d))/(dx*dx+dy*dy);
			if(ok2(tx,ty,D)) return 1;
			
			
			
		}
		return 0;
	}
	
	double ok3(int a,double D) {
		D+=R[a];
		if(X[a]<D) {
			double dy=sqrt(D*D-X[a]*X[a]);
			if(ok2(0,Y[a]+dy,D-R[a])) return 1;
			if(ok2(0,Y[a]-dy,D-R[a])) return 1;
		}
		if(X[a]+D>1000) {
			double dy=sqrt(D*D-(1000-X[a])*(1000-X[a]));
			if(ok2(1000,Y[a]+dy,D-R[a])) return 1;
			if(ok2(1000,Y[a]-dy,D-R[a])) return 1;
		}
		if(Y[a]<D) {
			double dx=sqrt(D*D-Y[a]*Y[a]);
			if(ok2(X[a]+dx,0,D-R[a])) return 1;
			if(ok2(X[a]-dx,0,D-R[a])) return 1;
		}
		if(Y[a]+D>1000) {
			double dx=sqrt(D*D-(1000-Y[a])*(1000-Y[a]));
			if(ok2(X[a]+dx,1000,D-R[a])) return 1;
			if(ok2(X[a]-dx,1000,D-R[a])) return 1;
		}
		return 0;
	}
	
	double getMax(vector <double> X, vector <double> Y, vector <double> R) {
		::X=X;
		::Y=Y;
		::R=R;
		N=X.size();
		
		int x,y,i;
		double ma=0;
		FOR(y,N) FOR(x,y) {
			double L=0,R=2000;
			FOR(i,60) {
				double M=(L+R)/2;
				if(ok(x,y,M)) L=M;
				else R=M;
			}
			ma=max(ma,L);
		}
		FOR(x,N) {
			double L=0,R=2000;
			FOR(i,60) {
				double M=(L+R)/2;
				if(ok3(x,M)) L=M;
				else R=M;
			}
			ma=max(ma,L);
		}

		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arr0[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 111.0, 111.0, 111.0, 111.0, 111.0, 111.0, 111.0, 111.0, 111.0, 111.0, 222.0, 222.0, 222.0, 222.0, 222.0, 222.0, 222.0, 222.0, 222.0, 222.0, 333.0, 333.0, 333.0, 333.0, 333.0, 333.0, 333.0, 333.0, 333.0, 333.0, 444.0, 444.0, 444.0, 444.0, 444.0, 444.0, 444.0, 444.0, 444.0, 444.0, 555.0, 555.0, 555.0, 555.0, 555.0, 555.0, 555.0, 555.0, 555.0, 555.0, 666.0, 666.0, 666.0, 666.0, 666.0, 666.0, 666.0, 666.0, 666.0, 666.0, 777.0, 777.0, 777.0, 777.0, 777.0, 777.0, 777.0, 777.0, 777.0, 777.0, 888.0, 888.0, 888.0, 888.0, 888.0, 888.0, 888.0, 888.0, 888.0, 888.0, 999.0, 999.0, 999.0, 999.0, 999.0, 999.0, 999.0, 999.0, 999.0, 999.0}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0, 0.0, 111.0, 222.0, 333.0, 444.0, 555.0, 666.0, 777.0, 888.0, 999.0}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0}; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 320.33719645669953; verify_case(0, Arg3, getMax(Arg0, Arg1, Arg2)); }

	void test_case_0_() { double Arr0[] = {42.1337, 543.21, 987.987, 0, 666.666, 133.331, 888.8}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {13.666, 765.432, 666.666, 1000, 66.66, 666.666666666, 88.8}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {191.17, 55.555, 321.321, 100, 16.6, 123.321, 8.8}; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 320.33719645669953; verify_case(0, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_1() { double Arr0[] = {0, 1000}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0, 1000}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {666, 666}; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 334.0000000000005; verify_case(1, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_2() { double Arr0[] = {0, 0, 1000, 1000}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {0, 1000, 0, 1000}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {13, 42, 17, 55}; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 673.3140001931692; verify_case(2, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_3() { double Arr0[] = {827.471, 14.129, 618.708, 476.184, 809.486, 159.701, 43.542, 217.328, 520.811, 487.601,
 304.607, 71.408, 580.637, 431.44, 24.895, 56.299, 9.497, 739.488, 662.694, 120.741,
 926.914, 339.471, 276.891, 283.293, 992.381, 900.847, 923.426, 245.573, 990.897, 272.343,
 137.418, 165.462, 977.63, 865.129, 434.287, 660.135, 698.627, 58.002, 606.568, 336.6,
 993.813, 90.582, 585.609, 269.735, 992.49, 659.948, 526.141, 81.724, 223.153, 469.335}; vector <double> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arr1[] = {880.162, 746.768, 230.709, 795.253, 586.775, 959.95, 117.509, 677.183, 548.965, 24.335,
 470.169, 788.348, 361.403, 576.748, 642.461, 875.51, 318.453, 666.799, 724.513, 400.208,
 26.04, 209.771, 272.209, 638.333, 759.456, 499.977, 332.563, 946.253, 919.925, 34.973,
 685.423, 847.907, 405.094, 342.004, 187.919, 67.409, 502.555, 747.495, 45.324, 296.785,
 636.987, 985.778, 594.304, 849.649, 299.628, 985.759, 415.145, 488.322, 825.231, 338.399}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {133.779, 11.522, 120.985, 180.029, 53.259, 1.206, 191.179, 43.29, 21.854, 70.408,
 133.972, 6.499, 10.191, 14.466, 54.393, 44.575, 1.007, 32.116, 3.19, 48.873,
 187.111, 29.704, 41.875, 32.19, 1.18, 52.696, 37.619, 16.1, 1.864, 17.377,
 5.939, 23.41, 49.367, 4.069, 48.236, 3.956, 71.83, 14.036, 13.614, 2.498,
 73.595, 14.513, 43.772, 4.456, 16.72, 24.049, 41.104, 14.412, 19.842, 50.129}; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 86.72241709552333; verify_case(3, Arg3, getMax(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysIncinerator ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

