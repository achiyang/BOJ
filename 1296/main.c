#include <stdio.h>
#include <string.h>

int strcnt(const char *str, char c) {
    const char *cp = str;
    int ret = 0;

    while ((cp = strchr(cp, c))) {
        ret++;
        if (!cp) break;
        cp++;
    }

    return ret;
}

int main() {
    int N, L, O, V, E;
    char name[21];
    char team[21];
    int max = -1;
    char ans[21];

    scanf("%s", name);
    scanf("%d", &N);

    L = strcnt(name, 'L');
    O = strcnt(name, 'O');
    V = strcnt(name, 'V');
    E = strcnt(name, 'E');

    for (int i = 0; i < N; i++) {
        scanf("%s", team);
        int l = L + strcnt(team, 'L');
        int o = O + strcnt(team, 'O');
        int v = V + strcnt(team, 'V');
        int e = E + strcnt(team, 'E');

        int fuck = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
        if (fuck > max) {
            strcpy(ans, team);
            max = fuck;
        }
        else if (fuck == max && strcmp(team, ans) < 0) {
            strcpy(ans, team);
        }
    }

    printf("%s\n", ans);

    return 0;
}