#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

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

typedef struct {
    Tile tiles[15];
    int size;
} TileSet;

typedef struct {
    TileSet players_tiles[4];
    Tile pool[106];
    int next_tile_index;
    Tile indicator_tile;
    Tile okey_tile;
} GameState;

void init_tiles(GameState *game) {
    int index = 0;

    for (int c = 0; c < 4; c++)
    {
        for (int n = 1; n <= 13; n++) 
        {
            for (int copy = 0; copy < 2; copy++) 
            {
                game->pool[index].color = (Color)c;
                game->pool[index].number = n;
                game->pool[index].id = index;
                game->pool[index].is_empty = false;
                index++;
            }
        }
    }

    for (int i = 0; i < 2; i++) 
    {
        game->pool[index].color = FAKE_OKEY;
        game->pool[index].number = 0;
        game->pool[index].id = index;
        game->pool[index].is_empty = false;
        index++;
    }

    game->next_tile_index = 0;
}

void shuffle_tiles(GameState *game) {
    for (int i = 105; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        Tile temp = game->pool[i];
        game->pool[i] = game->pool[j];
        game->pool[j] = temp;
    }
}

void deal_tiles(GameState *game) {
    game->players_tiles[0].size = 15;
    for (int i = 0; i < 15; i++) 
    {
        game->players_tiles[0].tiles[i] = game->pool[game->next_tile_index];
        game->players_tiles[0].tiles[i].is_empty = false;
        game->next_tile_index++;
    }

    for (int p = 1; p < 4; p++) 
    {
        game->players_tiles[p].size = 14;
        for (int i = 0; i < 14; i++) 
        {
            game->players_tiles[p].tiles[i] = game->pool[game->next_tile_index];
            game->players_tiles[p].tiles[i].is_empty = false;
            game->next_tile_index++;
        }

        game->players_tiles[p].size[14].is_empty = true;
    }
}

int main() {
    GameState game;
    srand(time(NULL));

    init_tiles(&game);
    printf("Tiles initialized and shuffled.\n");

    shuffle_tiles(&game);
    printf("Tiles shuffled.\n");

    deal_tiles(&game);
    printf("\n--- Player 0 Rack ---\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Tile %d: Color %d, Number %d, ID %d\n", i + 1, game.pool[i].color, game.pool[i].number, game.pool[i].id);
    }
    return 0;
}