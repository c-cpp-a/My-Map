#ifndef EGGS_H_
#define EGGS_H_
//include STL
//�����׼�� 
#include<string>
#include<iostream>
#include<fstream>
//include custom library
//�����Զ����
#include "def"
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
