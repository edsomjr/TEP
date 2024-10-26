#include <bits/stdc++.h>

int main() {
    std::istringstream is("123.456.789-10");
    std::string token;

    getline(is, token, '.');
    std::cout << token << '\n';      // token = "123";

    getline(is, token, '.');
    std::cout << token << '\n';      // token = "456";

    getline(is, token, '-');
    std::cout << token << '\n';      // token = "789";

    getline(is, token);
    std::cout << token << '\n';      // token = "10";

    return 0;
}
