#ifndef  SETTLEMENTINFO_H
#define  SETTLEMENTINFO_H

#include "EconomicStructure.h"
#include "ProvisionStructure.h"
#include "SocialStructure.h"
#include "Coordinates.h"
#include "Enviroment.h"
#include "Map.h"
#include <typeinfo.h>
#include <list>


class SettlementInfo{

public:
	//������� ����
	Block * SelectedBlock;

	//������ ����
	Map *map;

	int currentWeek, //������� �����
		sumWeek, //������� ������� �����
		targetWeek, //ֳ����� �����
		targetReligion, //ֳ����� ������� ���㳿
		targetFear, //ֳ����� ������� ������
		targetPopulation, //ֳ����� ���������
		targetPleasure; //ֳ������ ����� �����������

	//����� �������
	Resource *humanAmount; //����� ���������
	Resource *woodAmount; //������
	Resource *stoneAmount; //������
	Resource *goldAmount; //������
	Resource *ironAmount; //�����
	Resource *ironBarsAmount; //����� ������
	Resource *goldBarsAmount; //����� ������
	Resource *aammunitionAmount; //�������
	Resource *coinsAmount; //����� ������
	Resource *mealAmount; //������
	Resource *wheatGrainsAmount; //������� �����
	Resource *humulusAmount; //����
	Resource *flourAmount; //����
	Resource *AlcoholAmount; //��������
	Resource *totalPleasure; //�����������
	Resource *totalFear; //�����
	Resource *totalHumans; //���������
	Resource *totalReligion; //�����

	//����� ��� ��������� ���������� ������� �� �� �������
	std::list <WoodcutterHut<SettlementInfo>*>lstWoodCut; //������ ���������
	std::list <Quarry<SettlementInfo>*>lstQuarries; //������ �������
	std::list <Smeltery<SettlementInfo>*>lstSmelts; //������ ���������
	std::list <Armourer<SettlementInfo>*>lstArmors; //������ �������
	std::list <Mint<SettlementInfo>*>lstMints; //������ �������� �����

	//����� ��� ��������� �� �� �� �������
	std::list <HunterHouse<SettlementInfo>*> lstHunterHouses; //������ ���������
	std::list <Farm<SettlementInfo>*> lstFarms; //������ ����
	std::list <Field<SettlementInfo>*> lstFields; //������ �������� ����
	std::list <Mill<SettlementInfo>*> lstMills; //������
	std::list <Bakery<SettlementInfo>*> lstBakerys; //������
	std::list <Brewery<SettlementInfo>*> lstBrewerys; //�������

	//����� ��� ��������� ���������� �������
	std::list <Dugout<SettlementInfo>*>lstTents; //�������
	std::list <Church<SettlementInfo>*>lstChurchs; //������
	std::list <Outpost<SettlementInfo>*>lstOutposts; //������� �����
	std::list <Tavern<SettlementInfo>*>lstTaverns; //�������
	std::list <Grave<SettlementInfo>*>lstGraves; //���������


	//���������
	std::list<Tree*> trees; //������
	std::list<StoneEnv*> rockDepos; //������
	std::list<GoldEnv*> goldDepos; //����� ����
	std::list<IronEnv*>  ironDepos; //����� ����
	std::list<DeerEnv*> deerDepos; //�������� �����
	std::list<CowEnv*>  cowDepos; //�������� ����
	std::list<WolfEnv*>  wolfDepos; //����� ���
	std::list<FruitTree*> fruitDepos; //������� ������
	std::list<FishEnv*>  fishDepos; //������

	SettlementInfo(Graphics * _gfx);
	~SettlementInfo();

	void SaveSettlement();
	void LoadSettlement();
	//����� ��� ������ �����
	void SelectBlock(int _xPos, int _yPos, Graphics * _gfx);

	//���������� �������� �����
	Block * ReturnSelected();

	//��������� �����
	template <typename T> T* CreateStructure(std::string FileName, Graphics * _gfx);

	//������������ ����� �� ���� ���� ������������ ����������
	void SetBack(Graphics * _gfx);
};

template <typename T> T* SettlementInfo::CreateStructure(std::string FileName, Graphics * _gfx){

	T* obj = new T(FileName, _gfx);
	if (SelectedBlock){
		if (SelectedBlock->Check()){
			if (obj->CanBuild(this)){

				SelectedBlock->LocateStructure<T>(obj);
				obj->Construction(this);
				obj->InitBD(this);
				obj->Find(this);

				return obj;
			}
			else{

				delete obj;
				
				MessageBox(NULL, "Not enought resources!!!", "ERROR", MB_OK);
			}
		}
		else{

			MessageBox(NULL, "Block isn't empty!", "ERROR", MB_OK);
			return NULL;
		}
	}
	else{

		MessageBox(NULL, "Block isn't choosen!", "ERROR", MB_OK);
		return NULL;
	}
	return NULL;	
}

//��������� �������� ������ �� ���'��
template <typename �> void EraseLists(std::list <�*> * _lst){

	� * temp;
	
	if (_lst->size()>0)
	{
		auto iter = _lst->begin();
		while (iter != _lst->end())
		{
				temp = (*iter);
				iter = _lst->erase(iter);
				delete temp;
		}
	}
}


//���������� �� ���� ��'��� ��������
template <typename T> void SetEnv(std::list<T*> _lst, Graphics * _gfx, Map* _map){

	const auto blockBegin = _map->ReturnGameMap().begin();
	auto objIter = _lst.begin();
	auto blockIter = blockBegin;

	while (objIter != _lst.end()){
		while (blockIter != _map->ReturnGameMap().end()){
			if ((*objIter)->GetPos().x == (*blockIter)->GetPosition().x && (*objIter)->GetPos().y == (*blockIter)->GetPosition().y){

				(*blockIter)->LocateEnviroment((*objIter), _gfx);
				break;
			}
			++blockIter;
		}
		objIter++;
	}
}

//���������� �� ���� �������
template <typename T> void SetStr(std::list<T*> _lst, Map* _map){
	
	const auto blockBegin = _map->ReturnGameMap().begin();
	auto objIter = _lst.begin();
	auto blockIter = blockBegin;
	while (objIter != _lst.end()) {
		blockIter = blockBegin;
		while (blockIter != _map->ReturnGameMap().end()) {
			if ((*objIter)->coord.x == (*blockIter)->GetPosition().x-1 && (*objIter)->coord.y == (*blockIter)->GetPosition().y-1 ) {

				(*blockIter)->BackStructure((*objIter));
				break;
			}
			blockIter++;
		}
		objIter++;
	}
}


#endif // ! SETTLEMENTINFO_H