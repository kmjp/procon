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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		map<ll,vector<int>> S;
		priority_queue<pair<int,int>> Q;
		vector<int> ret;
		int i;
		FOR(i,servers.size()) {
			Q.push({-servers[i],-i});
		}
		FOR(i,tasks.size()) {
			S[i].push_back(i);
		}
		deque<int> D;
		while(S.size()) {
			ll cur=S.begin()->first;
			vector<int> V=S.begin()->second;
			S.erase(S.begin());
			if(cur>tasks.size()&&D.empty()) break;
			
			FORR(x,V) {
				if(x<tasks.size()) {
					D.push_back(x);
				}
				else {
					int y=x-tasks.size();
					Q.push({-servers[y],-y});
				}
			}
			while(Q.size()&&D.size()) {
				int x=-Q.top().second;
				Q.pop();
				int y=D.front();
				D.pop_front();
				ret.push_back(x);
				S[cur+tasks[y]].push_back(x+tasks.size());
			}
		}
		
        return ret;
    }
};
