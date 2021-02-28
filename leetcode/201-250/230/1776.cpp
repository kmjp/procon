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

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=0; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return 1^cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		while(Q.size()&&Q.front().first>=a) Q.pop_front();
		Q.push_front({a,b});
		while(Q.size()>=3 && !dodo(Q[0],Q[1],Q[2]))
			Q[1]=Q[0], Q.pop_front();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((cmptype^((calc(Q[M],x)>=calc(Q[M+1],x))))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};



class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
		int N=cars.size();
		ConvexHull<double> ch;
		vector<double> ret(N,0);
		int i,j;
		for(i=N-1;i>=0;i--) {
			ch.add(cars[i][1],cars[i][0]);
			if(ch.Q.size()==1) {
				ret[i]=-1;
			}
			else {
				double a=ch.Q[1].first;
				double b=ch.Q[1].second;
				ret[i]=(b-cars[i][0])/(cars[i][1]-a);
				
			}
		}
		return ret;
        
    }
};
