#include <iostream>
#include <algorithm>

int main() {
    std::string text { "Exemplo de uso da STL" }, vowels { "aeiou" }, ans;

    std::transform(text.begin(), text.end(), text.begin(),
        [](char c) { return tolower(c); });

    std::copy_if(text.begin(), text.end(), back_inserter(ans),
        [&](char c) { return vowels.find(c) != std::string::npos; }); 

    std::sort(ans.begin(), ans.end());

    auto n = std::unique(ans.begin(), ans.end()) - ans.begin();
    ans.resize(n);

    std::cout << n << " vogais unicas: " << ans << std::endl;

    return 0;
}
