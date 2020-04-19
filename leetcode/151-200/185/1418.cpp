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
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		map<int,vector<string>> M;
		set<string> meal;
		FORR(o,orders) {
			int x=atoi(o[1].c_str());
			M[x].push_back(o[2]);
			meal.insert(o[2]);
		}
		vector<vector<string>> R;
		vector<string> V;
		V.push_back("Table");
		FORR(m,meal) V.push_back(m);
		R.push_back(V);
		FORR(t,M) {
			V.clear();
			V.push_back(to_string(t.first));
			map<string,int> C;
			FORR(s,t.second) C[s]++;
			FORR(m,meal) {
				V.push_back(to_string(C[m]));
			}
			R.push_back(V);
			
			
		}
		return R;
		
		
        
    }
};

