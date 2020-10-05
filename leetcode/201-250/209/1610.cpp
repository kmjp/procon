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
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
		vector<double> V;
		double pi=4*atan(1);
		double d=pi*angle/180;
		int add=0;
		FORR(p,points) {
			p[0]-=location[0];
			p[1]-=location[1];
			if(p[0]==0&&p[1]==0) {
				add++;
			}
			else {
				double a=atan2(p[1],p[0]);
				V.push_back(a-2*pi);
				V.push_back(a);
				V.push_back(a+2*pi);
				
			}
		}
		sort(ALL(V));
		int ma=0;
		int i,j=0;
		FOR(i,V.size()) {
			while(j<V.size() && V[j]-V[i]<=d) j++;
			ma=max(ma,j-i);
		}
        return ma+add;
    }
};
