#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.txt");

#define isz(a) (int)a.size()

unordered_map<char,char> turn {
    {'^','>'},
    {'>','v'},
    {'v','<'},
    {'<','^'}
};

void print(vector<vector<char>> v){
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "\n\n";
    this_thread::sleep_for(10ms);
}

int check_for_loop(char state, pair<int, int> coord, vector<vector<char>> m){
    const pair <int,int> COORD = coord;
    const char STATE = state;
    for (int i = 0; i < 100000; ++i){
        char *g = &m[coord.first][coord.second];
        if (state == '^'){
            if(coord.first == 0) return 0;
            if(m[coord.first-1][coord.second] == '#' || m[coord.first-1][coord.second] == '0'){
                state = turn[state];
                continue;
            }
            *g = 'X';
            coord.first --;
        }
        else if (state == '>'){
            if(coord.second == isz(m[0])-1) return 0;
            if(m[coord.first][coord.second+1] == '#' || m[coord.first][coord.second+1] == '0'){
                state = turn[state];
                continue;
            }
            *g = 'X';
            coord.second ++;
        }
        else if (state == '<'){
            if(coord.second == 0) return 0;
            if(m[coord.first][coord.second-1] == '#' || m[coord.first][coord.second-1] == '0'){
                state = turn[state];
                continue;
            }
            *g = 'X';
            coord.second --;
        }
        else if (state == 'v'){
            if(coord.first == isz(m)-1) return 0;
            if(m[coord.first+1][coord.second] == '#' || m[coord.first+1][coord.second] == '0'){
                state = turn[state];
                continue;
            }
            *g = 'X';
            coord.first ++;
        }
        //print(m);
    }
    return 1;

}

void part1(){
    vector<vector<char>> m;
    uint64_t ans = 1;
    pair<int,int> coord;
    char state;
    for(string s; getline(fin,s);){
        vector<char> t;
        istringstream sin(s);
        for (char c; sin >> c;){
            if (c == '^' || c == '>' || c == 'v' || c == '<'){
                coord.first = isz(m);
                coord.second = isz(t);
                state = c;
            }
            t.push_back(c);
        }
        m.push_back(t);
    }  
    while(1){
        char *g = &m[coord.first][coord.second];
        if (state == '^'){
            if(coord.first == 0) break;
            if(m[coord.first-1][coord.second] == '#'){
                state = turn[state];
                continue;
            }
            if(m[coord.first-1][coord.second] == 'X'){
                *g = 'X';
                coord.first --;
                continue;
            }
            *g = 'X';
            coord.first --;
            ans++;
        }
        else if (state == '>'){
            if(coord.second == isz(m[0])-1) break;
            if(m[coord.first][coord.second+1] == '#'){
                state = turn[state];
                continue;
            }
            if(m[coord.first][coord.second+1] == 'X'){
                *g = 'X';
                coord.second ++;
                continue;
            }
            *g = 'X';
            coord.second ++;
            ans++;
        }
        else if (state == '<'){
            if(coord.second == 0) break;
            if(m[coord.first][coord.second-1] == '#'){
                state = turn[state];
                continue;
            }
            if(m[coord.first][coord.second-1] == 'X'){
                *g = 'X';
                coord.second --;
                continue;
            }
            *g = 'X';
            coord.second --;
            ans++;
        }
        else if (state == 'v'){
            if(coord.first == isz(m)-1) break;
            if(m[coord.first+1][coord.second] == '#'){
                state = turn[state];
                continue;
            }
            if(m[coord.first+1][coord.second] == 'X'){
                *g = 'X';
                coord.first ++;
                continue;
            }
            *g = 'X';
            coord.first ++;
            ans++;
        }
        //for (int i = 0; i < 10; ++i){
        //  for (int j = 0; j < 10; ++j){
        //      cout << m[i][j] << ' ';
        //  }
        //    cout << endl;
        //}
    //cout << state << ' ' << coord.first <<' '<< coord.second << "\n\n";

    }
    
    //cout << m[coord.first][coord.second] << endl;
    cout << ans << endl;
    
}

void part2(){
    vector<vector<char>> m;
    uint64_t ans = 0;
    pair<int,int> coord;
    char state;
    for(string s; getline(fin,s);){
        vector<char> t;
        istringstream sin(s);
        for (char c; sin >> c;){
            if (c == '^' || c == '>' || c == 'v' || c == '<'){
                coord.first = isz(m);
                coord.second = isz(t);
                state = c;
            }
            t.push_back(c);
        }
        m.push_back(t);
    }
    for (int i = 0; i < isz(m); ++i){
        for (int j = 0; j < isz(m[0]); ++j){
            if (m[i][j] == '.'){
                m[i][j] = '0';
                if (check_for_loop(state, coord, m)) ans ++;
                m[i][j] = '.';
            }
        }
    }
    cout << ans << endl;

 
}


int main(){
    part2();
}