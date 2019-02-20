#include <iostream>
#include <vector>

class Phonebook
{
public:
	Phonebook() {
		int capacity = 10000000;
		_contacts.resize(capacity);
		for (int i = 0; i < capacity; ++i)
			_contacts[i] = "";
	}
	~Phonebook(){}

	void			add(unsigned number, std::string const& name) {
		_contacts[number] = name;
	}

	std::string		find(unsigned number) {
		if (_contacts[number] != "")
			return _contacts[number];
		return "not found";
	}

	void			del(unsigned number) {
		_contacts[number] = "";
	}
	
private:
	std::vector<std::string> _contacts;
};

int 	main(void) {
	std::string		command;
	unsigned		number;
	std::string		name;
	int 			n;
	Phonebook 		phonebook;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> command;
		if (command == "add") {
			std::cin >> number >> name;
			phonebook.add(number, name);
		}
		else if (command == "find") {
			std::cin >> number;
			std::cout << phonebook.find(number) << std::endl;
		}
		else if (command == "del") {
			std::cin >> number;
			phonebook.del(number);
		}
	}
	return 0;
}