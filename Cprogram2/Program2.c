#include <stdio.h>

void outputs(int scores) {
	printf("\npossible combinations of scoring plays:\n");
    for (int a = 0; a < scores; a++)
    {
        for (int b = 0; b <= scores; b++)
        {
            for (int c = 0; c <= scores; c++)
            {
                for (int d = 0; d <= scores; d++)
                {
                    for (int e = 0; e <= scores; e++)
                    {
                        int total = (a*8) + (b*7) + (c*6) + (d*3) + (e*2);
                       if (total == scores) printf("\n%d TD + 2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n",a, b, c, d, e);
                    }

                }
            }
        }
    }
}

int main() {
	int scores = 2;
	while (scores > 1) {
		printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d", &scores);
		if (scores > 1) outputs(scores);
	}
	return 0;
}
