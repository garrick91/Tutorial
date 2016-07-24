#ifndef  GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "SettlementInfo.h"
#include <iostream>


class GameController {
	GameController() {};
	static SettlementInfo *Settlement;  //Current settlement
public:

	//����������� ������ ���
	static void Init(Graphics* _gfx);

	//���� ����� �� ��������� ������������
	static void ChooseBlock(int _xPos, int _yPos, Graphics * _gfx);
	
	//���������� ��������� �� ��'��� ����� SettlementInfo
	static SettlementInfo* ReturnSettlement() { return Settlement; }   

	//�������� �������� �����
	static void Clear();

	//��������� �� ������������ ������ �������� ��'���� - �������
	template <typename T> static T* Build (std::string FileName,Graphics * _gfx);

	//��������� �񳺿 �������
	static void UpdateSystem(Graphics * _gfx);

	//�������� ����� ������� �� ����������
	static bool CheckGoals();

	//�������� �������� ��������� ���
	static void Load(Graphics * _gfx);

	//���������� �������� ���������� ���
	static void Save();

	//��������� ��'����
	static void Render(int _xPos, int _yPos);

	//��������� �������
	static void Update();

	//��������� �������
	static void Release();

	//�������� �� �������� ����� ����������
	static bool CheckFiles();
};

template <typename T>
T* GameController::Build(std::string FileName, Graphics * _gfx){

	return Settlement->CreateStructure<T>(FileName, _gfx);
}

//��������� ��� �������� ������
template <typename T> 
void RenderObject(std::list<T*> _lst, int _xPos, int _yPos){

	if (_lst.size()>0){

		for (auto iter = _lst.begin(); iter != _lst.end(); iter++){

			if ((*iter)){

				(*iter)->Render(_xPos, _yPos);
			}
		}
	}
}

//��������� ������� ��� ��������� �������� ������
template <typename T> 
void UpdateObject(std::list<T*>  _lst){

	if (_lst.size()>0){

		for (auto iter = _lst.begin(); iter != _lst.end(); iter++){

			if ((*iter)){

				(*iter)->Update();
			}
		}
	}
}

//��������� �������� �������� �� ���� ������ �� ��������� ���'��, �������� �� �����
template <typename TP> void InStList(std::list<TP*> * _lst, Block * _obj, SettlementInfo * SI){
	TP * temp;
	bool Stop = false;
	if (_lst->size()>0){

		auto iter = _lst->begin();
		while (!Stop || iter != _lst->end()){
			if (_obj->ReturnStructure() == (*iter)){

				temp = (*iter);
				_obj->Clear();
				iter = _lst->erase(iter);
				Stop = true;
				temp->Destruction(SI);
				delete temp;
			}
			else{

				++iter;
			}
		}
	}
}

//�������� �� ��� ����� ������� � ������
template <typename STL> 
void UpdateList(std::list<STL*> * _lst, SettlementInfo * _SI, Graphics* _gfx){

	if (_lst->size()>0){

		for (auto iter = _lst->begin(); iter != _lst->end(); iter++){

			if ((*iter)){

				(*iter)->Action(_SI, _gfx);
			}
		}
	}
}

//���������� ������� ��'���
template <typename ST>
void StSave(std::string _countFile, std::string _dataFile, std::list<ST*> *_lst){
	int size;
	std::string *ToSave;
	size = _lst->size();
	std::ofstream foutC(_countFile);
	std::ofstream foutD(_dataFile);
	foutC << size;
	foutC.close();
	ToSave = new std::string[size];
	if (size){
		
		auto iter = _lst->begin();
	    int 	i = 0;
		while (iter != _lst->end()){
			ToSave[i] = (*iter)->Save();
			foutD << ToSave[i] << std::endl;
			i++;
			iter++;
		}
		foutD.close();
	}
	delete[] ToSave;
}


//������������ ������� ������
template <typename ST>
void StLoad(std::string _countFile, std::string _dataFile, std::list<ST*> *_lst, std::string _paramName, Graphics * _gfx){
	int size;
	std::string *ToLoad;
	ST* sTmp;
	std::ifstream fin(_countFile);
	fin >> size;
	fin.close();
	ToLoad = new std::string[size];
	std::ifstream finD (_dataFile);
	if (size){	
		
		auto i = 0;
		while (i != size){

			sTmp = new ST(_paramName, _gfx);
			finD >> ToLoad[i];
			sTmp->Load(ToLoad[i]);
			_lst->push_back(sTmp);
			i++;

		}
		finD.close();
	}
	delete[] ToLoad;
}


//������������ ��'���� ��������
template <typename ST>
void EnvLoad(std::string _countFile, std::string _dataFile, std::list<ST*> *_lst, std::string _paramName, Graphics * _gfx){
	int size;
	std::string *ToLoad;
	ST* sTmp;
	std::ifstream fin(_countFile);
	fin >> size;
	fin.close();
	ToLoad = new std::string[size];
	std::ifstream finD(_dataFile);
	if (size){

		auto i = 0;
		while (i != size){

			sTmp = new ST(_paramName, _gfx);
			finD >> ToLoad[i];
			sTmp->Load(ToLoad[i], _gfx);
			_lst->push_back(sTmp);
			i++;
		}
		finD.close();
	}
	delete[] ToLoad;
}

#endif // ! GAMECONTROLLER_H