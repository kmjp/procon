#include <bits/stdc++.h>
using namespace std;
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

vector<vector<int>> fin;

void dfs(vector<vector<int>>& state,int cur) {
	if(cur==81) {
		fin=state;
		return;
	}
	if(state[cur/9][cur%9]!=0) {
		dfs(state,cur+1);
	}
	else {
		int y=cur/9;
		int x=cur%9;
		int mask=(1<<9)-1;
		int z,i;
		FOR(z,9) if(z!=y && state[z][x]!=0) mask &= ~(1<<(state[z][x]-1));
		FOR(z,9) if(z!=x && state[y][z]!=0) mask &= ~(1<<(state[y][z]-1));
		FOR(z,9) if(z!=y%3*3+x%3 && state[y/3*3+z/3][x/3*3+z%3]!=0) mask &= ~(1<<(state[y/3*3+z/3][x/3*3+z%3]-1));
		
		for(i=1;i<=9;i++) if(mask&(1<<(i-1))) {
			state[y][x]=i;
			dfs(state,cur+1);
			if(fin.size()) return;
		}
		state[y][x]=0;
	}
}



vector<vector<int>> sudokuSolver(vector<vector<int>>& state) {
	dfs(state,0);
	return fin;
}

int main() {
    vector<vector<int>> state(9, vector<int>(9));
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            cin >> state[i][j];
        }
    }
    
    vector<vector<int>> finalState = sudokuSolver(state);
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            cout << finalState[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
