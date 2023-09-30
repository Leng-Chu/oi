#include <iostream>
#include <cstdlib>
#include <string>

int main() {
    freopen("title.in", "r", stdin);
    freopen("title.out", "w", stdout);

    std::string s;
    std::getline(std::cin, s);
    int cnt = 0;
    if (s.length() > 0 && s[0] != ' ') ++cnt;
    if (s.length() > 1 && s[1] != ' ') ++cnt;
    if (s.length() > 2 && s[2] != ' ') ++cnt;
    if (s.length() > 3 && s[3] != ' ') ++cnt;
    if (s.length() > 4 && s[4] != ' ') ++cnt;
    std::cout << cnt << std::endl;

    return 0;
}
