#include <stdbool.h>

typedef enum {
    YELLOW,
    BLUE,
    BLACK,
    RED,
    FAKE_OKEY
} Color;

typedef struct {
    Color color;
    int number;
    int id;
    bool is_empty;
} Tile;