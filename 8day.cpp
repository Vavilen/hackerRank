#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, long> phoneBook;
    int cnt;
    long num;
    string name;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> name;
        cin >> num;
        phoneBook.insert(pair<string, long>(name, num) );
    }
    string input;
    while (cin >> input) {
        if (phoneBook.find(input) != phoneBook.end()) {
             cout << input << "=" << phoneBook.at(input) << "\n";
         } else {
             cout << "Not found\n";
        };
    };
}
