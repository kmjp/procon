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
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		vector<int> R(queries.size());
		vector<pair<int,int>> ev;
		int i;
		FOR(i,rooms.size()) {
			ev.push_back({rooms[i][1],1000000+i});
		}
		FOR(i,queries.size()) {
			ev.push_back({queries[i][1],i});
		}
		sort(ALL(ev));
		reverse(ALL(ev));
		set<int> S;
		S.insert(-(1<<30));
		S.insert((1<<30));
		
		FORR(e,ev) {
			int x=e.second;
			if(x<1000000) {
				auto it=S.lower_bound(queries[x][0]);
				if(*it==queries[x][0]) {
					R[x]=queries[x][0];
				}
				else {
					int a=*it;
					it--;
					int b=*it;
					int y=queries[x][0];
					if(abs(b-y)<=abs(a-y)) R[x]=b;
					else R[x]=a;
					if(abs(R[x])>100000000) R[x]=-1;
				}
			}
			else {
				S.insert(rooms[x-1000000][0]);
			}
			
		}
        return R;
    }
};

