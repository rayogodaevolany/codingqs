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

    int num2 = 4;

    for(int i = 0; i < num2; i++){
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

int s2fix(){
    int num = 8;

    for(int i = 0; i < num; i++){
        for(int m = 0; m < abs(4 - i); m++){
            cout << " ";
        }
        for(int t = 0; t < 2*(4-abs(4 - i)); t++){
            cout << "#";
            }
        cout << "\n";
    }

    // for(int i = 0; i < num; i++){
    //     for(int m = 0; m < i; m++){
    //         cout << " ";
    //     }
    //     for(int t = 0; t < 8 - 2*i; t++){
    //         cout << "#";
    //         }
    //     cout << "\n";
    // }

    
    return 0;
}

int s3() {
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
    for( int row = 0; row < rows; row++) {
        if (row > 0 && row < 6) {
            cout << " ";
        } 
        if (row > 1 && row < 5){
            cout << " ";
        }
        cout << "#";
        cout << "\n";
    }


    return 0;
}

int main () {
    s3();



}
