# SDL3

## Coordinates

(0, 0) is the top left of the window, and larger numbers go down and to the right.

## Rendering

Rendering draws over whatever was drawn before it.

After calling all rendering functions you must do:
```c
SDL_RenderPresent(renderer);
```


## rectangles

Rectangles are comprised of set of X and Y coordinates, plus width and height.


## background

To render a background with a solid color you can do:
```c
SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
SDL_RenderClear(renderer); 
```