#include "../sdl-widgets.h"

TopWin *top_win;
Button *but, *but2;
int fullscreen;

int main(int,char**) {
  top_win=new TopWin("Hello",Rect(100,100,120,100),0,0,false,
    []() {
      top_win->clear();
      draw_title_ttf->draw_string(top_win->render,L"안녕하세요!",Point(20,40));
    }
  );
  but=new Button(top_win,0,Rect(5,10,60,0),"catch me",
    [](Button *b) {
      static int dy=60;
      b->hide();
      b->move(0,dy);
      b->hidden=false;
      dy= dy==60 ? -60 : 60;
    });    
  but2=new Button(top_win,0,Rect(100,10,100,0), L"전체화면",
   [](Button *b) {
	   if (!fullscreen)
	   {
		top_win->fullscreen(SDL_WINDOW_FULLSCREEN);
		fullscreen = 1;
	   }
	   else
	   {
		top_win->fullscreen(0);
		fullscreen = 0;
	   }
		   
    });    
  
  get_events();
  return 0;
}
