#include <iostream>
#include <vector>

#define q 1000000007l
#define x 31			/* <--- overflow with large numbers, all tests passed with x = 1 only; pow() is slow */

class RabinKarp
{
public:
	RabinKarp(std::string const & pattern, std::string const & text): _pattern(pattern) {

		_length = pattern.length();
		_patternHash = hash(pattern);
		check(text);
		_occ.shrink_to_fit();
	}

	~RabinKarp() {}

	void	showOccurences() {

		for (unsigned i : _occ)
			std::cout << i << " ";
		std::cout << std::endl;
	}

	std::vector<unsigned> const & getOccurences() {	return _occ; }
private:
	std::vector<unsigned>	_occ;
	size_t					_length;
	long long				_patternHash;
	std::string				_pattern;

	void		check(std::string const & str) {

		size_t		i = 1;
		long long	newHash;
		long long	oldHash;
		long long	tmp;
		char 		newChar;
		char 		oldChar;
		size_t		len = str.length() - _length + 1;

		oldChar = str[0];
		oldHash = hash(str);
		if (oldHash == _patternHash && equal(str, 0))
			_occ.push_back(0);
		while (i < len) {
			newChar = str[i + _length -1]; 
			tmp = ((oldHash - oldChar)%q +q)%q;
			tmp /= x;
			newHash = tmp +  ((newChar * pow(x, _length - 1))%q)  % q;
			newHash %= q;
			if ( newHash == _patternHash && equal(str, i))
				_occ.push_back(i);
			oldHash = newHash;
			oldChar = str[i];
			++i;
		}
	}

	bool		equal(std::string const & str, size_t index) {

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

		long long res = 1;
		if (power == 0 || base == 1)
			return 1;
		for (size_t i = 0; i < power; ++i) {
			res = (res * base)%q;
		}
		return res % q;
	}

	long long	hash(std::string const & str) {

		size_t i = 0;
		long long res = 0;
		long long tmp;

		while (i < _length) {
			tmp = str[i]  * pow(x, i);
			res = (res + tmp) % q;
			++i;
		}
		return res % q;
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