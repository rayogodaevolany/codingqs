#include <iostream>
#include <string>
#include <vector>
using namespace std;
// # is black
// . is white
// ? is wildcard

void solve(){
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    // get the shape of the rectangle
    int top = 1001, bottom = -1, left = 1001, right = -1;
    for (int i = 0; i < h; i++){
        string row; cin >> row;
        for (int j = 0; j < w; j++){
            if (row[j] == '#'){
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(j, left);
                right = max(j, right);
            }
        }
        grid[i] = row;
    }

    // empty grid
    if (top == 1001 || bottom == -1 || left == 1001 || right == -1) {
        cout << "No" << endl;
        return;
    }
    // check that the rectangle is paintable
    for (int i = top; i <= bottom; i++){
        for (int j = left; j <= right; j++){
            if (grid[i][j] == '.'){
                cout << "No" << endl;
                return;
            }
            
        }
    }
    cout << "Yes" << endl;
    return;


}

int main(){
    solve();
    return 0;
}
