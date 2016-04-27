//
// Created by Timothy Friberg Holmsten on 19/04/16.
//

#include "renderObject.h"

void render_walls(SDL_Window *window, Game * game)
{
    int i = 0;
    SDL_Renderer *renderer = SDL_GetRenderer(window);

    SDL_Texture *texture;
    texture = load_texture(renderer,"Wall.png");

    while(i < get_objects_count(game->map, "Walls")) {

        SDL_Rect rect = {256 + game->walls[i].x * 32, game->walls[i].y * 32, 32, 32};
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);

        i++;
    }
}

void render_bombs(SDL_Window * window, Game * game)
{
    int i = 0;
    SDL_Renderer * renderer = SDL_GetRenderer(window);

    SDL_Texture * texture;
    texture = load_texture(renderer,"Bomb.png");

    for (int pl_count = 0; pl_count < game->player_count; pl_count++) {
        while (i < 2) {
            SDL_Rect rect = {256 + game->players[pl_count].bombs[i].x * 32, game->players[pl_count].bombs[i].y * 32, 32, 32};
            SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
            i++;
        }
    }
};