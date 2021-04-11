#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	Menu szin_menu;
	Menu vonal_menu;

	Button szin_gomb;
	Button vonal_gomb;

	bool wait_for_button();

	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_yellow(Address, Address pw){reference_to<Lines_window>(pw).yellow_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_green(Address, Address pw) {reference_to<Lines_window>(pw).green_pressed();}
	static void cb_black(Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}
	static void cb_white(Address, Address pw){reference_to<Lines_window>(pw).white_pressed();}
	static void cb_color(Address, Address pw){reference_to<Lines_window>(pw).color_pressed();}

	static void cb_line(Address, Address pw){reference_to<Lines_window>(pw).line_pressed();}
	static void cb_solid(Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_dashdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dot_pressed();}
	static void cb_dashdotdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dotdot_pressed();}

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

	void change(Color c) {lines.set_color(c);}

	void red_pressed() {change(Color::red);hide_menu();}
	void yellow_pressed(){change(Color::yellow);hide_menu();}
	void blue_pressed(){change(Color::blue);hide_menu();}
	void green_pressed(){change(Color::green);hide_menu();}
	void white_pressed(){change(Color::white);hide_menu();}
	void black_pressed(){change(Color::black);hide_menu();}

	void hide_menu(){szin_menu.hide();szin_gomb.show();vonal_gomb.show();}
	void color_pressed(){szin_gomb.hide();vonal_gomb.hide();szin_menu.show();}

	void hide_style_menu(){vonal_menu.hide();vonal_gomb.show();szin_gomb.show();}
	void line_pressed(){vonal_gomb.hide();szin_gomb.hide();vonal_menu.show();}

	void change_ls(Line_style s) {lines.set_style(s);hide_style_menu();}

	void solid_pressed(){change_ls(Line_style::solid);}
	void dash_pressed(){change_ls(Line_style::dash);}
	void dot_pressed(){change_ls(Line_style::dot);}
	void dash_dot_pressed(){change_ls(Line_style::dashdot);}
	void dash_dotdot_pressed(){change_ls(Line_style::dashdotdot);}
};