#include "Model.hpp"
#include "SDL/SDL.h"

//The attributes of the screen
const int SCREEN_BPP = 32;

//The surfaces that will be used

SDL_Surface *load_image( std::string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

int ui_show(Model *showModel, int n, int m) {
  SDL_Surface *message = NULL;
  SDL_Surface *screen = NULL;
  vector<vector<bool> > drawCells = showModel -> getModel();

  //Set up the screen
  screen = SDL_SetVideoMode( (n+5) * 10, (m+5) * 10, SCREEN_BPP, SDL_SWSURFACE );

  //If there was an error in setting up the screen
  if( screen == NULL )
  {
      return 1;
  }

  //Set the window caption
  SDL_WM_SetCaption( "Cells", NULL );

  //Load the images
  
  message = load_image( "img/Cell.bmp" );
  apply_surface(100, 140, message, screen);
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= m; col++) {
      if (drawCells[row][col] == true) {
        apply_surface(row*10, col*10, message, screen);
      }
    }
  }
  if( SDL_Flip( screen ) == -1 )
  {
      return 1;
  }
  SDL_Delay(100);

  SDL_FreeSurface( message );

}

int ShowModelMatrix(int n, int m) {
	Model *showModel = new Model(n, m);

  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
  {
      return 1;
  }
	showModel -> initModel();
	for (;;) {
    ui_show(showModel, n, m);
		showModel -> changeCellsStatus();
	}
  SDL_Quit();
}

int main(int argc, char* args[]) {
		ShowModelMatrix(160, 100);

    return 0;
}