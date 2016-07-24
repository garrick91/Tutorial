#ifndef TYPES_H
#define TYPES_H

enum Seasons
{
	Winter,
	Spring,
	Summer,
	Autumn
};


enum EnviromentType {
	None,
	Trees, //+
	CoalDepo, //-
	Rock, //+
	GoldDepo, //+
	IronDepo, //+
	Deer, //+
	Cow,//+
	Fish,//+
	Wolf,//+
	Shrub, //+
	FruitTrees
};

enum BlockBackground {
	Ground,
	GrassLT,
	GrassT,
	GrassRT,
	GrassLM,
	GrassM,
	GrassRM,
	GrassLL,
	GrassL,
	GrassRL,
	Sand,
	WaterLT,
	WaterT,
	WaterRT,
	WaterLM,
	WaterM,
	WaterRM,
	WaterLL,
	WaterL,
	WaterRL
};

enum StructureType {
	StNone,	


	StTQuarry,
	StWoodCut,
	StSmeltery,
	StArmourer,
	StMint,

	//--------
	StHunter,
	StFarm,
	StField,
	StMill,
	StBaker,
	StBrewer,

	//--------
	StTents,
	StChurch,
	StOutpost,
	StTavern,
	StGrave
};

enum ResourceType {

	////**************�������� ������******************////
	Human, //�������


//-----------------------------------------------//

	//������������ � ������������� �������


	/**************�������� ������******************/
	Coal, //�����
	Wood, //������
	Stone, //������
	Iron, //������
	Gold, //������


	/************�������������� ������***************/
	Boards, //�����
	Bricks, //�������
	IronBars, //�������� ������
	GoldBars, //������� ������
	Skin, //�����
	Clothes,

	ArmorAndWeapon, //������ � �����
	Coins, //������


//-----------------------------------------------//


	//������� �������


/**************�������� ������******************/
	Meal, //��������
	WheatGrains, //��������� ����
	Humulus, //�����
	Water, //����


/************�������������� ������***************/
	Flour, //����
	Alcohol, //��������

			
//-----------------------------------------------//


			//�������������� �������
		
	Pleasure, //������������
	Fear, //�����
	Religion, //�������
	Enlightenment, //��������������

	Empty
};

enum FoodPortion
{
	VerySmall=1,
	Small = 2,
	Normal = 3,
	Big = 4,
	VeryBig = 5
};

#endif // !TYPES_H
