#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    szin_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    szin_gomb{Point{x_max()-140,40}, 140, 45, "color menu", cb_color},
    vonal_menu{Point{x_max()-70,60},70,20,Menu::vertical,"linestyle"},
    vonal_gomb{Point{x_max()-140,85},140,45,"linestyle menu",cb_line}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    szin_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    szin_menu.attach(new Button{Point{0,0},0,0,"yellow",cb_yellow});
    szin_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    szin_menu.attach(new Button{Point{0,0},0,0,"green",cb_green});
    szin_menu.attach(new Button{Point{0,0},0,0,"white",cb_white});
    szin_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});

    vonal_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    vonal_menu.attach(new Button{Point{0,0},0,0,"dashed",cb_dash});
    vonal_menu.attach(new Button{Point{0,0},0,0,"dotted",cb_dot});
    vonal_menu.attach(new Button{Point{0,0},0,0,"dash-dot",cb_dashdot});
    vonal_menu.attach(new Button{Point{0,0},0,0,"dashed-dotdot",cb_dashdotdot});

    attach(szin_menu);
    attach(vonal_menu);
    szin_menu.hide();
    vonal_menu.hide();
    attach(szin_gomb);
    attach(vonal_gomb);


}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}