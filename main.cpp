#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
class DataManager {
public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _key.size(); i++){
			const auto& [it,isInserted]= keyAmount.insert({_key[i],1});//�������� �������� � ���� ���� �� _key �� [i] �������� 1. � it ��������
			//�� ���������� ���� isInserted = ������� �������� ���������� ��� ���			
			if (!isInserted) {
				auto value = it->second;//� ���������� value  ����������� �������� �� ����������� ���� 
				value++;
				keyAmount[_key[i]] = value;//��������� ��������� �������� �� ����� ������� � ���� 
			}
		}
		std::pair<int, int> key_beggestValue = {0,0};
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin();it != keyAmount.end();it++) {
			if(key_beggestValue.second<it->second)
				key_beggestValue = std::make_pair(it->first, it->second);
			}
		return key_beggestValue.first;
	}
private:
	std::vector<int> _key = { 1,1,1,2,1,6,4,2,3,12,4,2,2,2 };
};
int errorFunc() {
	throw 0;
	return 1;
}
int divide(int a, int b) {
	if (b == 0)
		throw "division by zero";
	return a / b;
}

int main() {
	setlocale(LC_ALL, "Russian");
	//tuple
	std::tuple<int, std::string, double, float> t{ 1,"key",3.5,2.3f };
	const auto& [a, b, c, d] = t;
	std::cout << a << " " << b << " " << c << " " << d << "\n";
	std::cout << std::get<0>(t) << '\n';
	std::vector<std::tuple<int, std::string, int>> vec_t;
	vec_t.push_back({ 3,"key",6 });
	vec_t.push_back({ 56,"try",1 });
	for (size_t i = 0; i < vec_t.size(); i++)
	{
		const auto& [x, y, z] = vec_t[i];//������������ � ���������� x,y,z �������� �� �������
		std::cout << x << '\t' << y << '\t' << z << '\n';
	}
	//��-������
	DataManager dm;
	std::cout << dm.mostSearchedKey()<< '\n';
	//try catch
	int x = 10, y = 0;
	try {
		errorFunc();
		std::cout << divide(x, y) << std::endl;
	}
	catch(const char* msg){
		std::cerr << msg << std::endl;//cerr-���������� ��� ������ ������
	}
	catch (...) {//catch all - bad practice
		std::cerr << "Some exception has occured" << std::endl;
	}
	std::vector<int> v{ 1,2,3 };
	try	{
		int z = v.at(10);//������ �� ������� = v[10]  � ���� ������� �� ���������� ������� ����������
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}