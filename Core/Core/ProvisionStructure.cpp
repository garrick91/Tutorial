//#include "stdafx.h"
//
//#include "ProvisionStructure.h"
//#include "SettlementInfo.h"
//#include "Templates.h"
//
////�������
//template <typename T> void Find(T _obj, std::list<Enviroment*>* _lst)
//{
//	for (int i = 0; i < (int)SettlementInfo::map.ReturnGameMap().size() / 2; i++)
//	{
//		for (int j = 0; j < (int)SettlementInfo::map.ReturnGameMap().size() / 2; j++)
//		{
//			if ((SettlementInfo::map.ReturnGameMap()[i][j]->GetResourcesType() == _obj->type) &&
//				(SettlementInfo::map.ReturnGameMap()[i][j]->GetPosition().x <= (_obj->coord.x - _obj->workAreaRadius)) &&
//				(SettlementInfo::map.ReturnGameMap()[i][j]->GetPosition().x >= (_obj->coord.x + _obj->workAreaRadius)) &&
//				(SettlementInfo::map.ReturnGameMap()[i][j]->GetPosition().y <= (_obj->coord.y - _obj->workAreaRadius)) &&
//				(SettlementInfo::map.ReturnGameMap()[i][j]->GetPosition().y >= (_obj->coord.y + _obj->workAreaRadius)))
//			{
//				_lst->push_back(SettlementInfo::map.ReturnGameMap()[i][j]->ReturnEnviroment());
//			}
//		}
//	}
//}
//
//template <typename T> void Action(T _obj, std::list<Enviroment*>* _lst, int _resAmount)
//{
//	Enviroment* tmp = new Enviroment();
//	if ((_obj->workStatus == true) && (!_lst->empty()))
//	{
//		for (auto iter = _lst->begin(), end = _lst->end(); iter != end; ++iter)
//		{
//			tmp = *iter;
//			if (tmp->resource->currentCount >= _obj->resIncrease)
//			{
//				tmp->resource->currentCount -= _obj->resIncrease;
//				_resAmount += _obj->resIncrease;
//				break;
//			}
//			else
//			{
//				iter = _lst->erase(iter);
//				end = _lst->end();
//				continue;
//			}
//		}
//	}
//	delete tmp;
//}
//
//
////********************************** ����� **********************************************//
//
//void Farm::MakeAction()
//{
//	if (this->workStatus == true )
//	{
//		SettlementInfo::mealAmount.currentCount += this->resIncrease;
//	}
//}
//
//
////********************************** ������ �������� **********************************************//
//
//void HunterHouse::MakeAction()
//{
//	Action <HunterHouse*>(this, MainHerd, SettlementInfo::mealAmount.currentCount);
//	SettlementInfo::skinAmount.currentCount += this->skinIncrease;
//}
//
//void HunterHouse::FindAnimals()
//{
//	Find <HunterHouse*> (this, this->MainHerd);
//}
//
////********************************** ������ ������ **********************************************//
//
//
//void FishermanHut::MakeAction()
//{
//	Action <FishermanHut*>(this, MainFishPlace, SettlementInfo::mealAmount.currentCount);
//}
//
//void FishermanHut::FindFish()
//{
//	Find <FishermanHut*>(this, MainFishPlace);
//}
//
////********************************** ��������� ��� **********************************************//
//
//void Orchard::MakeAction()
//{
//	if (this->workStatus == true)
//	{
//		SettlementInfo::mealAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ������ **********************************************//
//
//void Garden::MakeAction()
//{
//	if (this->workStatus == true)
//	{
//		SettlementInfo::mealAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ��������� ���� **********************************************//
//
//void WheatField::MakeAction()
//{
//	if (this->workStatus == true)
//	{
//		SettlementInfo::wheatGrainsAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ���� ����� **********************************************//
//
//void HumulusField::MakeAction()
//{
//	if (this->workStatus == true)
//	{
//		SettlementInfo::humulusAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ������� **********************************************//
//
//void Well::MakeAction()
//{
//	if (this->workStatus == true)
//	{
//		SettlementInfo::waterAmount.currentCount += this->resIncrease;
//	}
//}
//
//
////********************************** �������� **********************************************//
//
//void Mill::MakeAction()
//{
//	if (this->workStatus == true && SettlementInfo::wheatGrainsAmount.currentCount && (SettlementInfo::wheatGrainsAmount.currentCount>0))
//	{
//		SettlementInfo::wheatGrainsAmount.currentCount -= this->sourceAmount;
//		SettlementInfo::flourAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ��������� **********************************************//
//
//void Brewery::MakeAction()
//{
//	if (this->workStatus == true && SettlementInfo::humulusAmount.currentCount && (SettlementInfo::humulusAmount.currentCount>0))
//	{
//		SettlementInfo::humulusAmount.currentCount -= this->sourceAmount;
//		SettlementInfo::AlcoholAmount.currentCount += this->resIncrease;
//	}
//}
//
////********************************** ������� **********************************************//
//
//void Bakery::MakeAction()
//{
//	if (this->workStatus == true && SettlementInfo::flourAmount.currentCount && (SettlementInfo::flourAmount.currentCount>0))
//	{
//		SettlementInfo::flourAmount.currentCount -= this->sourceAmount;
//		SettlementInfo::mealAmount.currentCount += this->resIncrease;
//	}
//}