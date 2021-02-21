#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{100,100},600,400,"Az ablakom"};

	Axis xa {Axis::x, Point(20,300),280,10,"X tengely"};
	Axis ya {Axis::y, Point(20,300),280,10,"Y tengely"};
	xa.set_color(Color::green);
	ya.set_color(Color::red);

	Function szinusz {sin,0,100,Point{20,150},1000,50,50};
	szinusz.set_color(Color::white);

	Polygon sokszeg1;
	sokszeg1.add(Point{500,500});
	sokszeg1.add(Point{500,650});
	sokszeg1.add(Point{950,650});
	sokszeg1.add(Point{950,500});
	sokszeg1.set_fill_color(Color::red);

	Polygon sokszeg2;
	sokszeg2.add(Point{500,650});
	sokszeg2.add(Point{500,800});
	sokszeg2.add(Point{950,800});
	sokszeg2.add(Point{950,650});
	sokszeg2.set_fill_color(Color::white);

	Rectangle teglalap {Point{500,800},450,150};
	teglalap.set_fill_color(Color::green);

	Text szoveg {Point{612,1000}, "Hidratálj! kiváltva tapet által"};
	szoveg.set_font_size(20);

	Image kripto {Point{950,500},"kripto.jpg"};

	Circle karika {Point{250,250},50};
	karika.set_fill_color(Color::yellow);

	Mark jel {Point{120,120},'o'};

	win.attach(xa);
	win.attach(ya);
	win.attach(szinusz);
	win.attach(sokszeg1);
	win.attach(sokszeg2);
	win.attach(teglalap);
	win.attach(szoveg);
	win.attach(kripto);
	win.attach(karika);
	win.attach(jel);
	win.wait_for_button();
}