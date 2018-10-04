#include <iostream>
#include <string>
using namespace std;

class animal {
protected:
	string name; int age;
public:
	void set_value(int x, string y)
	{
		age = x; name = y;
	}
	string get_name() {
		return name;
	}
	int get_age() {
		return age;
	}
};

class zebra : public animal {
protected:
	string birthplace = "Africa";
public:
	string get_birthplace() {
		return birthplace;
	}
};

class dolphin : public animal {
protected:
	string birthplace = "Ocean";
public:
	string get_birthplace() {
		return birthplace;
	}
};

int main(){
	zebra zebra1;
	dolphin dolphin1;

	zebra1.set_value(5, "Lady");
	dolphin1.set_value(8, "Swimmer");

	cout << "The zebra named " << zebra1.get_name() << " is " << zebra1.get_age() << " years old and is from " << zebra1.get_birthplace() << '\n';

	cout << "The dolphin named " << dolphin1.get_name() << " is " << dolphin1.get_age() << " years old and is from " << dolphin1.get_birthplace() << '\n';



	return 0;
}