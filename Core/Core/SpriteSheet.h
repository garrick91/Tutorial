#ifndef  SPRITESHEET_H
#define SPRITESHEET_H

#include "Graphics.h" 
#include <wincodec.h> // Component (WIC) ����� ��� ������������� ����������� �� �����

class SpriteSheet
{

	Graphics* gfx; //��������� �� ����������� �����
	ID2D1Bitmap* bmp; //��������� ���� � ������������ � direct2d ������
public:
	float frame;
	int spriteWidth, spriteHeight, spritesAccross;

	SpriteSheet(wchar_t* filename, Graphics* gfx);
	SpriteSheet(wchar_t* filename, Graphics* gfx, int spriteWidth, int spriteHeight);

	~SpriteSheet();

	//���������� ����� � ���� ������������
	void Draw();
	void Draw(int x, int y);
	void DrawAnimation(float x, float y);
	void Update();
};

#endif