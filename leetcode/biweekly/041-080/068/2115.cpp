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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		unordered_set<string> S;
		vector<string> R;
		FORR(a,supplies) S.insert(a);
		int i,j;
		int add=1;
		while(add) {
			add=0;
			FOR(j,recipes.size()) if(S.count(recipes[j])==0) {
				int ok=1;
				FORR(a,ingredients[j]) if(S.count(a)==0) ok=0;
				if(ok) {
					S.insert(recipes[j]);
					R.push_back(recipes[j]);
					add++;
				}
				
			}
		}
        return R;
    }
};
