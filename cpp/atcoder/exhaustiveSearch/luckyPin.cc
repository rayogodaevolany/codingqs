#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const set<T>& set){
     if (set.empty())
        return out << "{}";
    out << "{ " << *set.begin();
    std::for_each(std::next(set.begin()), set.end(), [&out](const T& element)
    {
        out << ", " << element;
    });
    return out << " }";
}

int main() {
    int digits;
    set<string> container;
    string input;
    // digits can be up to 30000
    cin >> digits;
    cin.ignore();
    getline(cin, input);

    // how can I optimize this to run much faster?
    for(int i=0;i<digits; i++){
        for(int j=i+1;j<digits;j++){
            for(int m=j+1;m<digits;m++){
                        // add string into set
                        string temp = "";
                        temp += input[i];
                        temp += input[j];
                        temp += input[m];
                        container.insert(temp);
            }
        }
    }
    cout << container.size();
    // cout << container << '\n';
    return 0;
}

