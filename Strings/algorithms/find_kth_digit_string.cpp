using ull = unsigned long long;
using vull = vector<ull>;
vull pow10;
vector<array<ull, 4>> memo;
void precompute(int maxpow = 18) {
  ull qtd = 1; // quantidade de dígitos
  ull start = 1; // primeiro número com qtd dígitos
  ull end = 9; // último número com qtd dígitos
  ull curlenght = 9; // quantdiade de números entre start e end
  ull startstr = 1; // primeira posicao da string que aparece um número com qtd dígitos
  ull endstr = 9; // última posição da string que aparece um número com qtd dígitos

  for (ull i = 0, j = 1ll; (int)i < maxpow; i++, j *= 10ll) pow10.eb(j);

  for (ull i = 0; i < maxpow - 1ull; i++) {
    memo.push_back({start, end, startstr, endstr});

    start = end + 1ll;
    end = end + (9ll * pow10[qtd]);
    curlenght = end - start + 1ull;

    qtd++;
    startstr = endstr + 1ull;
    endstr = (endstr + 1ull) + (curlenght)*qtd - 1ull;
  }
}
char kthDigit(ull k) {
  int qtd = 1;
  for (auto [s, e, ss, es] : memo) {
    if (k >= ss and k <= es) {
      ull pos = k - ss; // qual da string que vai de ss até es
      ull index = pos / qtd; // qual posicao esta o número que possúi a k-ésima posição
      ull nmr = s + index; //  qual o número de fato
      int i = k - ss - qtd * index; // qual posição no número está a késima

      // i-ésimo dígito do número
      return ((nmr / pow10[qtd - i - 1]) % 10) + '0';
    }
    qtd++;
  }

  return 'X';
}
