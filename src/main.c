#define SDL_MAIN_USE_CALLBACKS 1  // Using SDL callbacks instead of main.
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "MainMenu.h"

const static char* appName = "Flipfinity";
const static char* appVersion = "1.0.0";
const static char* appIdentitifier = "ir.iliyabadri.flipfinity";

// We use this renderer to draw into this window every frame.
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// SDL global initialization callback.
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata(appName, appVersion, appIdentitifier);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer(appName, WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

// SDL global event handler callback. (for mouse input, keypresses, etc)
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

// SDL global update callback. (Runs every frame)
SDL_AppResult SDL_AppIterate(void *appstate)
{
    RenderMainMenu(renderer);
    // SDL_FRect rects[16];
    // const Uint64 now = SDL_GetTicks();
    // int i;

    // const float direction = ((now % 2000) >= 1000) ? 1.0f : -1.0f; // Triangle wave direction
    // const float scale = ((float) (((int) (now % 1000)) - 500) / 500.0f) * direction;

    // SDL_SetRenderDrawColor(renderer, 0, 60, 0, SDL_ALPHA_OPAQUE);
    // SDL_RenderClear(renderer); 

    // rects[0].x = rects[0].y = 100;
    // rects[0].w = rects[0].h = 100 + (100 * scale);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);  /* red, full alpha */
    // SDL_RenderRect(renderer, &rects[0]);

    // /* Now let's draw several rectangles with one function call. */
    // for (i = 0; i < 3; i++) {
    //     const float size = (i+1) * 50.0f;
    //     rects[i].w = rects[i].h = size + (size * scale);
    //     rects[i].x = (WINDOW_WIDTH - rects[i].w) / 2;  /* center it. */
    //     rects[i].y = (WINDOW_HEIGHT - rects[i].h) / 2;  /* center it. */
    // }
    // SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);  /* green, full alpha */
    // SDL_RenderRects(renderer, rects, 3);  /* draw three rectangles at once */

    // /* those were rectangle _outlines_, really. You can also draw _filled_ rectangles! */
    // rects[0].x = 400;
    // rects[0].y = 50;
    // rects[0].w = 100 + (100 * scale);
    // rects[0].h = 50 + (50 * scale);
    // SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);  /* blue, full alpha */
    // SDL_RenderFillRect(renderer, &rects[0]);

    // /* ...and also fill a bunch of rectangles at once... */
    // for (i = 0; i < SDL_arraysize(rects); i++) {
    //     const float w = ((float)WINDOW_WIDTH / (float)SDL_arraysize(rects));
    //     const float h = i * 8.0f;
    //     rects[i].x = i * w;
    //     rects[i].y = WINDOW_HEIGHT - h;
    //     rects[i].w = w;
    //     rects[i].h = h;
    // }
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    // SDL_RenderFillRects(renderer, rects, SDL_arraysize(rects));

    SDL_RenderPresent(renderer); 

    return SDL_APP_CONTINUE;
}

// SDL global shutdown callback.
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}

void RenderMainMenu(SDL_Renderer *renderer);