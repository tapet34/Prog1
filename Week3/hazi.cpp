#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	//1. feladat
	Simple_window win{Point(500,500),800,1000, "Swockwickdus"};

	//2.feladat
	int x_size = 800;
	int y_size = 800;
	int x_grid=100;
	int y_grid=100;

	Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point(x,0),Point(x,y_size));
	for(int y=y_grid; y<=y_size; y+=y_grid)
		grid.add(Point(0,y),Point(x_size,y));

	win.attach(grid);

	//3. feladat
	Rectangle piros1 (Point(0,0),100,100);
	piros1.set_fill_color(Color::red);
	Rectangle piros2 (Point(100,100),100,100);
	piros2.set_fill_color(Color::red);
	Rectangle piros3 (Point(200,200),100,100);
	piros3.set_fill_color(Color::red);
	Rectangle piros4 (Point(300,300),100,100);
	piros4.set_fill_color(Color::red);
	Rectangle piros5 (Point(400,400),100,100);
	piros5.set_fill_color(Color::red);
	Rectangle piros6 (Point(500,500),100,100);
	piros6.set_fill_color(Color::red);
	Rectangle piros7 (Point(600,600),100,100);
	piros7.set_fill_color(Color::red);
	Rectangle piros8 (Point(700,700),100,100);
	piros8.set_fill_color(Color::red);

	win.attach(piros1);
	win.attach(piros2);
	win.attach(piros3);
	win.attach(piros4);
	win.attach(piros5);
	win.attach(piros6);
	win.attach(piros7);
	win.attach(piros8);

	//4.feladat
	Image gif1 {Point{300,100},"wow.jpg"};
	Image gif2 {Point{500,300},"wow.jpg"};
	Image gif3 {Point{100,300},"wow.jpg"};
	Image gif4 {Point{300,500},"wow.jpg"};

	win.attach(gif1);
	win.attach(gif2);
	win.attach(gif3);
	win.attach(gif4);

	//5.feladat
	Image goblin {Point{0,0},"goblin.jpg"};

	win.attach(goblin);

	win.wait_for_button();
	int sorok = 0;
	int oszlopok = 0;

	while(true)
	{
		for(int i = 0; i < 7; i++)
		{
		if(sorok==0 && oszlopok<7)
		{
			goblin.move(100,0);
			win.wait_for_button();
			oszlopok++;
		}
		else if(sorok<7 && oszlopok==7)
		{
			goblin.move(0,100);
			win.wait_for_button();
			sorok++;
		}
		else if(sorok==7 && oszlopok>0)
		{
			goblin.move(-100,0);
			win.wait_for_button();
			oszlopok--;
		}
		else
		{
			goblin.move(0,-100);
			win.wait_for_button();
			sorok--;
		}
		}
		win.wait_for_button();
	}

}
