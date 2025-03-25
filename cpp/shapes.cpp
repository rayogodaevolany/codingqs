#include <iostream>
using namespace std;

int s1(){
    int num = 4;

    for(int i = 0; i < num; i++){
        for(int m = 0; m < i; m++){
            cout << " ";
        }
        for(int t = 0; t < 8 - 2*i; t++){
            cout << "#";
            }
        cout << "\n";
    }

    return 0;
}
int s2(){
    int num = 4;

    for(int i = 0; i < num; i++){
        for(int m = 0; m < 4 - i; m++){
            cout << " ";
        }
        for(int t = 0; t < 2*i; t++){
            cout << "#";
            }
        cout << "\n";
    }
    
    s1();
    return 0;
}

int s3top() {
    int num = 5;

    for(int i = 0; i < num; i++){
        for(int m = 0; m < i; m++){
            cout << " ";
        }
        for(int t = 0; t < i; t++){
            cout << "#";
            }
        for(int m = 0; m < (4 - i) * 4; m++){
            cout << " ";
        }
        for(int t = 0; t < i; t++){
            cout << "#";
            }
        cout << "\n";
    }
    return 0;
}

int s3bottom() {
    int num = 5;

    for(int i = 0; i < num; i++){
        for(int m = 0; m < 4 - i; m++){
            cout << " ";
        }
        for(int t = 0; t < 4 - i; t++){
            cout << "#";
            }
        for(int m = 0; m < i * 4; m++){
            cout << " ";
        }
        for(int t = 0; t < 4 - i; t++){
            cout << "#";
            }
        cout << "\n";
    }
    return 0;
}

int s4(){
    int rows = 7;
    for( int i = 0; i < rows; i++) {
        for (int space = 0; space < i; space++){
                cout << " ";
        }
        cout << "#";
        cout << "\n";
    }


    return 0;
}

int main () {
    s4();



}
