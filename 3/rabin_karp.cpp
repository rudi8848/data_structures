#include <iostream>
#include <vector>

#define q 1000000007l
#define x 31

class RabinKarp
{
public:
	RabinKarp(std::string const & pattern, std::string const & text): _pattern(pattern) {
		//std::cout << __FUNCTION__ << std::endl;
		_length = pattern.length();
		_patternHash = hash(pattern.c_str());
		check(text);
		_occ.shrink_to_fit();
	}

	~RabinKarp() {}

	void	showOccurences() {
		//std::cout << __FUNCTION__ << std::endl;
		for (unsigned i : _occ)
			std::cout << i << " ";
		std::cout << std::endl;
	}

	std::vector<unsigned> const & getOccurences() {
		return _occ;
	}
private:
	std::vector<unsigned>	_occ;
	size_t					_length;
	unsigned				_patternHash;
	std::string				_pattern;

	void		check(std::string const & str) {
		//std::cout << __FUNCTION__ << std::endl;
		size_t		i = 1;
		long long	newHash;
		long long	oldHash;
		long long	tmp;
		char 		newChar;
		char 		oldChar;
		size_t		len = str.length() - _length + 1;

		oldChar = str[0];
		oldHash = hash(str.c_str());
		if (oldHash == _patternHash && equal(str, 0))
			_occ.push_back(0);
		while (i < len) {
			newChar = str[i + _length -1]; 
			tmp = oldHash - oldChar;
			tmp = ((tmp % q) + q) %q;
			tmp /= x;
			
			newHash = tmp + ( ((newChar * pow(x, _length - 1))%q) + q) % q;
			newHash %= q;
			std::cout << "i = " << i <<"; oldChar = " << oldChar << "; oldHash = " << oldHash
			<< "; newChar = " << newChar << "; newHash " << newHash << "; _patternHash: "
			<< _patternHash << std::endl;
			if ( newHash == _patternHash && equal(str, i))
				_occ.push_back(i);
			oldHash = newHash;
			oldChar = str[i];
			++i;
		}
	}

	bool		equal(std::string const & str, size_t index) {
		//std::cout << __FUNCTION__ << std::endl;
		size_t i = 0;
		while (i < _length) {
			if (_pattern[i] != str[index])
				return false;
			++index;
			++i;
		}
		return true;
	}

	long long	pow(long long base, size_t power) {
		//std::cout << __FUNCTION__ << std::endl;
		long long res = 1;
		if (power == 0 || base == 1)
			return 1;
		for (size_t i = 0; i < power; ++i) {
			res *= base;
			res %= q;
		}
		return res;
	}

	long long	hash(char const* str) {
		//std::cout << __FUNCTION__ << std::endl;
		size_t i = 0;
		long long res = 0;
		long long tmp;

		while (i < _length) {
			tmp = str[i]  * pow(x, i);
			res += tmp %q;
			tmp = ((tmp%q) + q) %q;
			++i;
		}
		res = ((res%q) + q)% q;
		return res;
	}
};

int		main(void)
{
	std::string		pattern;
	std::string		text;

	std::cin >> pattern >> text;

	RabinKarp(pattern, text).showOccurences();

	return 0;
}