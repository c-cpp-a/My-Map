#ifndef EGGS_H_
#define EGGS_H_
//include STL
//导入标准库 
#include<string>
#include<iostream>
#include<fstream>
//include custom library
//导入自定义库
using namespace std;
class Egg{
	private:
		bool has_ach=false;
		bool achs[10]={};
	public:
		int isegg(const int &,People &,Map &);
		void check_run(const int &,People &,Map &);
		void print_ach(); 
		void imports(ifstream &);
		void save(ofstream &);
		inline bool is_ach(){
			return has_ach;
		}
		inline bool &operator[](size_t i){
			return achs[i];
		}
};
#endif
