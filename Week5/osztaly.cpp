#include "std_lib_facilities.h"

using namespace std;

struct Person
{
	private:
	string first_name,last_name;
	int age;

	public:
	Person(){};
	Person(string n1, string n2, int a)
	{
		first_name=n1;
		last_name=n2;
		age=a;
	}

	string get_first_name() const {return first_name;}
	string get_last_name() const {return last_name;}
	int get_age() const {return age;}

	void set_first_name(string n){first_name=n;}
	void set_last_name(string n){last_name=n;}
	void set_age(int a){age=a;}
};

	ostream& operator<< (ostream& os, Person& p)
	{
		os<<"Név: "<<p.get_first_name()<<" "<<p.get_last_name()<<" Kor: "<<p.get_age();
		return os;
	}

	istream& operator>> (istream& is, Person& p)
	{
		string first,last;
		int a;
		is>>first>>last;

		for(auto letter : first)
		{
			if(!isalpha(letter) && !isdigit(letter))
			{
				cout<<letter<< " letter"<<endl;
				error("Hibásan megadott név");
			}
		}
		p.set_first_name(first);

		for(auto letter : last)
		{
			if(!isalpha(letter))
			{
				cout<<letter<< " letter"<<endl;
				error("Hibásan megadott név, hiányzik a vezetéknév!");
			}
		}
		p.set_last_name(last);

		is>>a;

		if(0<=a && a<=150)
			{
				p.set_age(a);
			}
		else
		{
			error("Hibásan megadott kor!");
		}
		return is;
	}

int main()
{
/*	Person p1;
	p1.name="Goofy";
	p1.age=63;

	cout<<p1.name<<" "<<p1.age<<endl;
	cout<<p1<<endl;
*/

	Person p2;

	cout<<"Adja meg a nevét és korát:"<<endl;
	cin>>p2;
	cout<<p2<<endl;

/*	Person XD ("BD",33);
	cout<<XD<<endl;
*/
	cout<<"Adjon nevet a vektornak:"<<endl;

	vector<Person> people;
	Person temp;
	int numOfPeople=0;
	while(cin>>temp)
	{
		people.push_back(temp);
		cout<<people[numOfPeople]<<endl;
	}


	return 0;
}