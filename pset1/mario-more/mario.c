#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int read_height() {
    return get_int("Height: ");
}

void print_pyramid(int height)
{
    for (int i = 1; i <= height; i++) {
        printf(" %.*s%.*s %.*s\n", height-i, "        ", i, "########", i, "########");
    }
}

int main(int argc, char *argv[])
{
    int height = 0;
    if (argc > 1) height = atoi(argv[1]);
    while (height < 1 || height > 8) height = read_height();
    print_pyramid(height);
}
