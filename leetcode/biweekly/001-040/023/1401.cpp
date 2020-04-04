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
	ll dist(ll x1,ll y1,ll x2,ll y2) {
		return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	}
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(dist(x1,y1,x_center,y_center)<=radius*radius) return 1;
        if(dist(x1,y2,x_center,y_center)<=radius*radius) return 1;
        if(dist(x2,y1,x_center,y_center)<=radius*radius) return 1;
        if(dist(x2,y2,x_center,y_center)<=radius*radius) return 1;
        if(x1<=x_center&&x_center<=x2&&y1<=y_center&&y_center<=y2) return 1;
        
        if(x_center<x1 && abs(x1-x_center)<=radius) {
			double ya=y_center+sqrt(radius*radius-(x1-x_center)*(x1-x_center));
			double yb=y_center-sqrt(radius*radius-(x1-x_center)*(x1-x_center));
			cout<<ya<<yb<<endl;
			if(!(ya>y2||yb<y1)) return 1;
		}
        if(x2<x_center && abs(x2-x_center)<=radius) {
			double ya=y_center+sqrt(radius*radius-(x2-x_center)*(x2-x_center));
			double yb=y_center-sqrt(radius*radius-(x2-x_center)*(x2-x_center));
			if(!(ya>y2||yb<y1)) return 1;
		}
        if(y_center<y1 && abs(y1-y_center)<=radius) {
			double xa=x_center+sqrt(radius*radius-(y1-y_center)*(y1-y_center));
			double xb=x_center-sqrt(radius*radius-(y1-y_center)*(y1-y_center));
			if(!(xa>x2||xb<x1)) return 1;
		}
        if(y2<y_center && abs(y2-y_center)<=radius) {
			double xa=x_center+sqrt(radius*radius-(y2-y_center)*(y2-y_center));
			double xb=x_center-sqrt(radius*radius-(y2-y_center)*(y2-y_center));
			if(!(xa>x2||xb<x1)) return 1;
		}
		return 0;
        
    }
};

