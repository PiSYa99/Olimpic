#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.txt");
#define to_int(a) a - '0'
#define isz(a) (int)a.size()

void part1(){
    uint64_t t,id = 0;
    bool file = 1;
    uint64_t ans{};
    vector<int> map;

    for (char n; fin >> n;){
        t = to_int(n);
        if (file){
            for (int i = 0; i < t; i++){
                map.push_back(id);
            }
            id++;
            file = 0;
        } else {
            for (int i = 0; i < t; ++i){
                map.push_back(-1);
            }
            file = 1;
        } 
    }
    for(uint64_t l = 0, r = isz(map)-1; l < r;){
    if(map[l] == -1){
            if(map[r] != -1){
                map[l] = map[r];
                map.pop_back();
                r--;
                l++;
            } else {
                r--;
                map.pop_back();
            }
        } else {
            l++;
        }
    }
    for(uint64_t i = 0; i < isz(map); i++){
        if(map[i] != -1){
            ans += map[i]*i;
        }
    }
    cout << ans;
    
}


void part2(){ // bRute FoRce iS mY haPpy colour
    uint64_t id = 0;
    bool file = 1;
    uint64_t ans{};
    int diff;
    vector<pair<int,int>> map; 

    for (char n; fin >> n;){
        if(file){
            map.push_back({to_int(n),id});
            file = 0;
            id++;
        } else {
            map.push_back({to_int(n),-1});
            file = 1;
        }
    }
    
    for(uint64_t r = isz(map)-1; r > 0;){
        if(map[r].second == -1){
            r--;
            continue;
        }
        for(int l = 0; l < r; l++){
            if(map[l].second != -1) continue;
            if(map[l].first < map[r].first) continue;
            if(map[l].first == map[r].first){
                map[l] = map[r];
                map[r].second = -1;
                r--;
                break;
            }
            diff = map[l].first - map[r].first;
            map[l] = map[r];
            map[r].second = -1;
            map.insert(map.begin()+l+1, pair<int,int> {diff,-1});
            r++;
            break;
        }
        r--;
    }

    id = 0;
    
    for (pair<int,int> p : map){
        for(int i = 0; i < p.first; i++) {
            if (p.second != -1)ans += p.second*id;
            id++;    
        }
    }
    cout << ans;
}

int main(){
    part2();

}