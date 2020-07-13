typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
	double dist(vector<vector<int>>& pos, double x,double y) {
		double ret=0;
		FORR(p,pos) ret+=hypot(x-p[0],y-p[1]);
		return ret;
	}
	double dist1(vector<vector<int>>& pos,double x) {
        int N=pos.size();
        int i;
        double U=0,D=100;
        FOR(i,60) {
			double M1=(U*2+D)/3;
			double M2=(U+D*2)/3;
			double V1=dist(pos,x,M1);
			double V2=dist(pos,x,M2);
			if(V1<=V2) D=M2;
			else U=M1;
		}
        return dist(pos,x,U);
	}
    double getMinDistSum(vector<vector<int>>& pos) {
        int N=pos.size();
        int i;
        double L=0,R=100;
        FOR(i,60) {
			double M1=(L*2+R)/3;
			double M2=(L+R*2)/3;
			double V1=dist1(pos,M1);
			double V2=dist1(pos,M2);
			if(V1<=V2) R=M2;
			else L=M1;
		}
        return dist1(pos,L);
    }
};

