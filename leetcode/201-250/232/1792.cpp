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
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		priority_queue<pair<double,int>> Q;
		int i;
		FOR(i,classes.size()) {
			double v=1.0*(classes[i][1]-classes[i][0])/(1.0*classes[i][1]*(classes[i][1]+1));
			Q.push({v,i});
			
		}
		while(extraStudents--) {
			auto p=Q.top();
			Q.pop();
			int i=p.second;
			classes[i][0]++;
			classes[i][1]++;
			double v=1.0*(classes[i][1]-classes[i][0])/(1.0*classes[i][1]*(classes[i][1]+1));
			Q.push({v,i});
		}
		
		double D=0;
		FORR(c,classes) {
			D+=c[0]*1.0/c[1];
		}
		
		
		return D/classes.size();
		
        
    }
};
