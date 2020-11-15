//
// Created by pedro on 13/11/2020.
//

#include<iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    unsigned char player_now = 0;
    long long int player_points[2] = {0, 0};
    short int player_wins[2] = {0, 0};
    char c;
    bool continua_jogo = true;

    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') { break; }
//        cout << c;
        switch (c*continua_jogo) {
            case 'S':
                player_points[player_now]++;
                if (player_points[player_now] == 10||(player_points[player_now] > 4 &&
                                player_points[player_now] >= player_points[player_now^1] + 2)){
                    player_wins[player_now]++;
                    player_points[0] = 0;
                    player_points[1] = 0;
                    continua_jogo = (player_wins[player_now] < 2);
                }
                cout << "teste\n";
                cout << player_wins[0] << " (" << player_points[0] << char ('*'*(player_now == 0)) << ")";
                cout << " - " <<player_wins[1] << " (" << player_points[1] << char ('*'*(player_now == 1)) << ")" << endl;
                break;
            case 'R':
                player_now = player_now^1;
                player_points[player_now]++;
                if (player_points[player_now] == 10||(player_points[player_now] > 4 &&
                                                      player_points[player_now] >= player_points[player_now^1] + 2)){
                    player_wins[player_now]++;
                    player_points[0] = 0;
                    player_points[1] = 0;
                    continua_jogo = (player_wins[player_now] < 2);
                }
                cout << "teste\n";
                cout << player_wins[0] << " (" << player_points[0] << char ('*'*(player_now == 0)) << ")";
                cout << " - " <<player_wins[1] << " (" << player_points[1] << char ('*'*(player_now == 1)) << ")" << endl;
                break;
            case 'Q':
                cout << player_wins[0] << " (" << player_points[0] << char ('*'*(player_now == 0)) << ")";
                cout << " - " <<player_wins[1] << " (" << player_points[1] << char ('*'*(player_now == 1)) << ")" << endl;
                break;

        }
        switch (c*(!continua_jogo)) {
            case 'Q':
                cout << player_wins[0];
                if (player_wins[0] == 2)
                    cout << " (winner)";
                cout << " - " <<player_wins[1];
                if (player_wins[1] == 2)
                    cout << " (winner)";
                cout << endl;
                break;

        }

    }


}