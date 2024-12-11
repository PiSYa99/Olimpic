#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.txt");

#define isz(a) (int) a.size()
#define all(a) a.begin(),a.end()

int make_trail(vector<vector<int>> &map, int i, int j, vector<pair<int,int>> &s){
    uint16_t ans{};
    if (map[i][j] == 9 && count(all(s),pair<int,int>{i,j})==0){
        s.push_back(pair<int,int>{i,j});
        return 1;
    }  
    if(i-1 >= 0 && map[i-1][j] - map[i][j] == 1){
        ans += make_trail(map, i-1, j,s);
    }
    if(j+1 < isz(map[0]) && map[i][j+1] - map[i][j] == 1){
        ans += make_trail(map,i,j+1,s);
    }
    if(i+1 < isz(map) && map[i+1][j] - map[i][j] == 1){
        ans += make_trail(map, i+1, j,s);
    }
    if(j-1 >= 0 && map[i][j-1] - map[i][j] == 1){
        ans += make_trail(map,i, j-1,s);
    }
    return ans;
}

int make_trail2(vector<vector<int>> &map, int i, int j){ //Actually first genaration that counts                                                         
    uint16_t ans{};                                      //all possible routes
    if (map[i][j] == 9) return 1;
    if(i-1 >= 0 && map[i-1][j] - map[i][j] == 1){
        ans += make_trail2(map, i-1, j);
    }
    if(j+1 < isz(map[0]) && map[i][j+1] - map[i][j] == 1){
        ans += make_trail2(map,i,j+1);
    }
    if(i+1 < isz(map) && map[i+1][j] - map[i][j] == 1){
        ans += make_trail2(map, i+1, j);
    }
    if(j-1 >= 0 && map[i][j-1] - map[i][j] == 1){
        ans += make_trail2(map,i, j-1);
    }
    return ans;
}


void part1(){
    vector<vector<int>> map;
    vector<pair<int,int>> s;
    uint64_t ans{};
    for(string s; getline(fin,s);){
        vector <int> t;
        for (char c : s) t.push_back(c-'0');
        map.push_back(t);
    }
    for(int i = 0; i < isz(map[0]); i++){
        for(int j = 0; j < isz(map); j++){
            if(map[i][j] == 0){
                ans += make_trail(map, i, j, s);
                s.clear();
                
            }
        }
    }
    cout << ans << endl;

}

void part2(){
    vector<vector<int>> map;
    uint64_t ans{};
    for(string s; getline(fin,s);){
        vector <int> t;
        for (char c : s) t.push_back(c-'0');
        map.push_back(t);
    }
    for(int i = 0; i < isz(map[0]); i++){
        for(int j = 0; j < isz(map); j++){
            if(map[i][j] == 0){
                ans += make_trail2(map, i, j);
            }
        }
    }
    cout << ans << endl;
}

int main(){ // Actually easier than i thought
    part2();
}



