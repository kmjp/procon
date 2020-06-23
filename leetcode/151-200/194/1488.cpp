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
    vector<int> avoidFlood(vector<int>& rains) {
		vector<int> R=rains,day=rains;
		map<int,int> pre;
		
		int i;
		FOR(i,R.size()) if(rains[i]) {
			if(pre.count(rains[i])) {
				day[i]=pre[rains[i]];
			}
			else {
				day[i]=-1;
			}
			pre[rains[i]]=i;
		}
		
		priority_queue<pair<int,int>> Q;
		
		for(i=rains.size()-1;i>=0;i--) {
			if(Q.size() && Q.top().first==i) return {};
			if(rains[i]>0) {
				if(day[i]>=0) Q.push({day[i],rains[i]});
				R[i]=-1;
			}
			else {
				R[i]=1;
				if(Q.size()) {
					R[i]=Q.top().second;
					Q.pop();
				}
			}
		}
		return R;
        
    }
};
