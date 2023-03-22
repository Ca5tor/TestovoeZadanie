#include <iostream>
#include <string>
#include <sstream>

bool printError(const std::string &msg) { 
	std::cout << "Error: " << msg << std::endl; 
	return false;	
}

bool cheсkSymbols (const std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!(std::isalpha(str[i]) || str[i] == ' ' || str[i] == '-'))
			return printError("Only letters, space and dash are allowed!");
	}
	return true;
}

bool checkSpace(const std::string &str) {
	if (str[0] == ' ' || str[str.length() - 1] == ' ')
		return printError("Space at the beginning or end of a line");
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' && str[i + 1] == ' ')
			return printError("Double space in string");
		if (std::islower(str[i]) && str[i + 1] == ' ' && std::islower(str[i + 2]))
			return printError("incorrect space");
		if (str[i] == ' ' && !std::isupper(str[i + 1]))
			return printError("can't find capital letters after spaces");
	}
	return true;
}

bool checkDash(const std::string &str) {
	if (str[0] == '-' || str[str.length() - 1] == '-')
		return printError("Dash at the beginning or end of a line");
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == ' ' && str[i + 1] == '-')
			return printError("incorrect dash");
		if (str[i] == '-' && str[i + 1] == '-')
			return printError("incorrect double dash");
		if (std::islower(str[i]) && str[i + 1] == '-' && !std::isupper(str[i + 2]))
			return printError("can't find capital letters after dash");
	}
	return true;
}

bool checkWord(const std::string &str) {
	if (!std::isupper(str[0]))
		return printError("Name must start with a capital letter");
	if (str.length() == 1)
		return printError("suspiciously short name");
	for (size_t i = 1; i < str.length(); i++) {
		if (std::isupper(str[i]) && std::isupper(str[i + 1]))
			return printError("name contains more than 1 capital letter in a row");
		if (!std::islower(str[i]) && (str[i] == '-' && !std::isupper(str[i + 1])))
			return printError("Capital letters must be followed by uppercase letters");
		if(str[i] == '-' && !std::isupper(str[i + 1]))
			return printError("after the dash in the word Must be a capital letter");
		if(std::islower(str[i]) && std::isupper(str[i + 1]))
			return printError("missing delimiter or space");
		if(std::isupper(str[i]) && str[i + 1] == '-'  && std::isupper(str[i + 2]))
			return printError("suspect dash abuse");
	}	
	return true;
}

bool checkStrFIO(const std::string &str) {
	std::string word = "";
	size_t countWord = 0;
	for (std::stringstream ss(str); !ss.eof();) {
		ss >> word;
		if (!checkWord(word)) return false;
		countWord++;
	}
	//Есть возможность проверки на дубликат имени, Например "Sergey Sergey Sergey"
	//или черезмерную длину ФИО
	//в задании такое не оговаривалось но ремарку тут оставлю)
	if (countWord < 2)
		return printError("suspiciously few words in the full name");
	return true;
}

bool checkEmptyStr(const std::string &str) {
	if (str.empty()) return printError("input string is empty");
	return true;
}
bool checkersStrFIO(const std::string &str) {
	bool (*checers[])(const std::string &str) = {
		&checkEmptyStr,
		&cheсkSymbols,
		&checkStrFIO,
		&checkDash,
		&checkSpace
	};
	bool flag = true;

	for (int i = 0; i < 5 && flag; i++)
		flag = checers[i](str);
	return flag;
}

void Zadanie_2(std::string str) {
	if (checkersStrFIO(str)) {
		std::cout << "True\n";
		return;
	}
	std::cout << "False\n";
}

void TESTS(void) {
	const int SIZE_BAD_NAME = 28;
	std::string badName[SIZE_BAD_NAME] = {
		"",
		" ",
		" -",
		"-",
		"               -",
		"123 123 123",
		"Abc12",
		"Avsf12 3123 ***",
		"aaa AaaA Aaaa",
		"AaaaA Baaa F-F",
		"N_A_M_E L_A_S_T W_O_R_D",
		"N-A-M-E N-A-M-E",
		" Name Name Name",
		"Name  Name Name",
		"Name Name-Name Name ",
		"Name",
		" Name",
		"Name ",
		"                          Name Name Name",
		"Name               Name           Name",
		"-Name -Name -Name",
		"Name- Name Name",
		"Name Name Name-",
		"Name - Name Name",
		"Name Name Name -",
		"Name Name Name - ",
		"Name Name-L-L-NA Naaa",
		"NaMe Name Name"
	};

	for (size_t i = 0; i < SIZE_BAD_NAME; i++) {
		Zadanie_2(badName[i]);
		std::cout << "=====================================================\n";
	}
		
	
	// const int SIZE_GOOD_NAME = 5;
	// std::string goodName[SIZE_GOOD_NAME] = {
	// 	"Name-N Name-Na Na-Na",
	// 	"Name Name Name",
	// 	"Name Name-K Name NAme",
	// 	"Name Name Name Name",
	// 	"Name Name"
	// };

	// for (size_t i = 0; i < SIZE_GOOD_NAME; i++) {
	// 	Zadanie_2(goodName[i]);
	// 	std::cout << "=====================================================\n";
	// }
	
}

int main(void) {
	// std::string str("");
	// std::cout << "Enter your Name for Checked\n => ";
	// std::getline(std::cin, str);
	// //std::cout << "Get str = " << str << std::endl; 
	// Zadanie_2(str);

	TESTS();
}