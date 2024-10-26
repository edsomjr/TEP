// Esta implementação assume que o alfabeto é composto pelas 26 letras maiúsculas do alfabeto
void histogram(int h[26], const std::string& s)
{
    memset(h, 0, sizeof h);

    for (auto c : s)
        ++h[c - 'A'];
}
