/* Compile com a flag -lncurses */
#include <ncurses.h>
#include <ctype.h> 
 
int found[4096], i;
char word[] = "TESTE", uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef enum { STARTING, RUNNING, WAITING, VICTORY, GAME_OVER } State;

void print(int tries, State state) {
    const char header[] = "Descubra a palavra secreta:";

    clear();
    mvprintw(1, 2, header);

    for (i = 0; word[i]; ++i) {
        addch(' ');
        found[i] ? addch(word[i] | A_BOLD) : addch('_');
    }

    mvprintw(3, 0, "Chances restantes: %d", tries);
    mvprintw(4, 0, "Letras disponíveis:");

    for (i = 0; uppercase[i]; ++i) {
        if (uppercase[i] != '*')
            printw(" %c", uppercase[i]);
    }

    mvprintw(6, 0, "Digite uma das letras disponíveis: ");

    if (state == VICTORY)
        mvprintw(8, 10, "Você descobriu a palavra secreta!");
    else if (state == GAME_OVER)
        mvprintw(8, 10, "Game Over!");

    refresh();
}

State update(State state, int *tries) {
    int left = 0, hits = 0, c;

    if (state == STARTING)
        return RUNNING;

    c = getch();

    if (c < 'a' || c > 'z' || uppercase[c - 'a'] == '*')
        return WAITING;

    uppercase[c - 'a'] = '*';

    for (i = 0; word[i]; ++i) {
        if (!found[i] && word[i] == toupper(c)) {
            ++hits;
            found[i] = 1;
        } 

        left += (!found[i] ? 1 : 0);
    }

    if (left == 0)
        return VICTORY;
    else if (hits == 0)
        *tries -= 1;

    if (*tries == 0)
        return GAME_OVER;

    return RUNNING;
}

void init() {
    initscr();
    noecho();
}

void close() {
    getch();
    endwin();
}

int main()
{
    int tries = 7;
    State state = STARTING;

    init();

    while (state != VICTORY && state != GAME_OVER) {
        state = update(state, &tries);
        print(tries, state);
    } 

    close();

    return 0;
}
