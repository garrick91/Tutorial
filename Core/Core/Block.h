#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <string>
#include <typeinfo>
#include "Types.h"
#include "Coordinates.h"
#include "SpriteSheet.h"
#include "Graphics.h"
#include <string>

#include "jsoncons\json.hpp"
using jsoncons::json;
using jsoncons::json_serializer;
using jsoncons::json_deserializer;

class  Block{
	Coordinates coordinates; //���������� ����� �� ���
	void* structure; //�������� �� ������
	void* resourceSource; //�������� �� ��'��� ��������
	BlockBackground Background; //��� ��������
	SpriteSheet *blockTexture; //�������� �����
	bool accessibility; //����� ��� �������� ����� �� ����������
public:
	bool isSelected; //����� ��� �������� ����� ����� (������� �� �)
	EnviromentType blockEnvType; //���� ��������, �� ������ ����
	StructureType structureType; //��� �����, �� ������ ����
	Coordinates screen; //������ ���������� �����
	Block(Graphics * _gfx);
	void Select(Graphics * _gfx);
	void Deselect(Graphics * _gfx);
	~Block();

	//�������� �� ��������� ����������
	bool Check (); 

	//������� ��� ��'���� ��������
	EnviromentType GetResourcesType(); 

	//������� � ������ ������ ��� �����
	std::string GetStructureType(); 

	//������� ������� ����� �� ���
	Coordinates GetPosition();

	//���� ������� ����� �� ���
	void AddBlock(Coordinates newPosition); 

	//��������� �����
	void RenderBlock(int _xPos, int _yPos);

	//���������� ��'��� �������� �� ����
	template <typename ENV> void LocateEnviroment(ENV *_env, Graphics * _gfx);

	//��������� �� ���� ������
	template <typename STR> void BackStructure(STR *_str);

	//���������� ������ �� ����
	template <typename STR> void LocateStructure(STR *_str);

	//��������� �������� �� ��'��� ��������
	void* ReturnEnviroment() { return this->resourceSource; }

	//��������� �������� �� ���������
	void* ReturnStructure() { return this->structure; }

	//���������, �� �������� ����� �����
	bool MyDot(int _xPos, int _yPos);

	//�������� ����
	void Clear();

	//�������� ��� �����
	std::string SaveBlock();
};



template <typename ENV>
void  Block ::LocateEnviroment(ENV *_env, Graphics * _gfx){

	if (_env->envType != Fish){

		this->resourceSource = _env;
		blockEnvType = _env->envType;
		accessibility = false;
		_env->ChoosePosition(this->coordinates.x, this->coordinates.y);
	}
	else{

		delete blockTexture;
		blockTexture = new SpriteSheet(L"Textures/Block/water.png", _gfx, 128, 80);
		this->resourceSource = _env;
		blockEnvType = _env->envType;
		accessibility = false;
		_env->ChoosePosition(this->coordinates.x, this->coordinates.y);
	}
	
}

template <typename STR>
void Block::LocateStructure(STR *_str){

	this->structureType = _str->ReturnType();
	this->structure = _str;
	accessibility = false;
	_str->InitPosition(this->coordinates.x, this->coordinates.y);
}


template <typename STR>
void Block::BackStructure(STR *_str){

	this->structureType = _str->ReturnType();
	this->structure = _str;
	accessibility = false;
	//_str->InitPosition(this->coordinates.x, this->coordinates.y);
}

#endif // !BLOCK_H
