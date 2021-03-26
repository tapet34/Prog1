#include "Simple_window.h"
#include "Graph.h"

double one(double x)
{
	return 1;
}
double slope(double x)
{
	return x/2;
}
double square(double x)
{
	return x*x;
}
double sloping_cos(double x)
{
	return slope(x)+cos(x);
}


int main()
{
	using namespace Graph_lib;

		int ablak_vaskos=600;
		int ablak_termet=600;
		Simple_window win{Point(500,500),ablak_vaskos,ablak_termet, "Fúró 15"};
		Point eredet{ablak_vaskos/2,ablak_termet/2};

		Axis xtengely {Axis::x, Point(100,300),400,20,"1 = = 20 képkocka"};
		Axis ytengely {Axis::y, Point(300,500),400,20,"1 = = 20 képkocka"};
		xtengely.set_color(Color::red);
		ytengely.set_color(Color::red);

		win.attach(xtengely);
		win.attach(ytengely);


		int legalabb=-10;
		int legfeljebb=11;
		int pontok=400;
		int x_pikkely=20;
		int y_pikkely=20;

		Text vinyetta {Point (100,380), "x/2"};
		win.attach(vinyetta);

		Function egy(one, legalabb, legfeljebb, eredet, pontok, x_pikkely, y_pikkely);
		win.attach(egy);
		Function csuszda(slope, legalabb, legfeljebb, eredet, pontok, x_pikkely, y_pikkely);
		win.attach(csuszda);
		Function negyzet(square, legalabb, legfeljebb, eredet, pontok, x_pikkely, y_pikkely);
		win.attach(negyzet);
		Function koszinusz([](double x){return cos(x);},
			legalabb, legfeljebb, eredet, pontok, x_pikkely, y_pikkely);
			koszinusz.set_color(Color::blue);
		win.attach(koszinusz);
		Function koszinusz_csuszda(sloping_cos, legalabb, legfeljebb, eredet, pontok, x_pikkely, y_pikkely);
		win.attach(koszinusz_csuszda);

	win.wait_for_button();
}
