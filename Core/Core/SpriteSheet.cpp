#include "SpriteSheet.h"


SpriteSheet::SpriteSheet(wchar_t* filename, Graphics* gfx)
{
	//Init 
	this->gfx = gfx; // ��������� gfx �������� �� �����
	bmp = NULL; //��������� �������� ID2D1Bitmap
	HRESULT hr; // HRESULT ��� �������� �� ������

	CoInitialize(NULL);

	//������� WIC factory � ������� ������ CoCreateInstance
	IWICImagingFactory *wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory, //CLSID �������, ������� �� ������
		NULL, //������ �� �������� ��� ����� ������������
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,//dll �������� � ��� �� ��������, ��� � ���������� �������
		(LPVOID*)&wicFactory); //��������� ������� ����� ��������� factory

							   //������������� wicFactory ��� �������� ��������
							   //������� ��������
	IWICBitmapDecoder *wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		filename, //��� �����
		NULL, //���������������� ���������
		GENERIC_READ, //������ ������ �����
		WICDecodeMetadataCacheOnLoad, //��� ��� ��������
		&wicDecoder); //������ �� ����������� �������

					  //������ ������ �� �����������
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	//�������� ����������
	IWICFormatConverter *wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	//��������� ��������� ��� �������� 32��� BGRA bitmap
	hr = wicConverter->Initialize(
		wicFrame, //�����
		GUID_WICPixelFormat32bppPBGRA, //������ ��������
		WICBitmapDitherTypeNone,
		NULL, //�������
		0.0, //�����
		WICBitmapPaletteTypeCustom);

	//������������� ���������� ��� �������� D2D1Bitmap
	hr = gfx->renderTarget->CreateBitmapFromWicBitmap(
		wicConverter,
		NULL,
		&bmp);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();

	spriteWidth = bmp->GetSize().width;
	spriteHeight = bmp->GetSize().height;
	spritesAccross = 1;
}

SpriteSheet::SpriteSheet(wchar_t* filename, Graphics* gfx, int spriteWidth, int spriteHeight) :SpriteSheet(filename, gfx)
{
	this->spriteHeight = spriteHeight;
	this->spriteWidth = spriteWidth;
	this->spritesAccross = (int)bmp->GetSize().width / spriteWidth;
}

SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
}

void SpriteSheet::Update()
{
	
	if (this->frame<((int)bmp->GetSize().width / spriteWidth) - 1)
	{
		this->frame += 0.1;
	}
	else
	{
		this->frame = 0;
	}
}

//��������� ��������� ����������� �� (0,0)
void SpriteSheet::Draw()
{
	gfx->GetRenderTarget()->DrawBitmap(
		bmp, //bitmap
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height), //destination rect
		1.0f, //opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0.0f, 0.0f, bmp->GetSize().width, bmp->GetSize().height) //source rect
	);

}

void SpriteSheet::Draw(int x, int y)
{
	D2D_RECT_F src = D2D1::RectF(
		(float)(((int)frame % spritesAccross)*spriteWidth),
		(float)(((int)frame / spritesAccross)*spriteHeight),
		(float)(((int)frame %spritesAccross)*spriteWidth) + spriteWidth,
		(float)(((int)frame / spritesAccross)*spriteHeight) + spriteHeight);

	D2D_RECT_F dest = D2D1::RectF(
		x, y,
		x + spriteWidth, y + spriteHeight);

	gfx->GetRenderTarget()->DrawBitmap(
		bmp, //bitmap
		dest,//destination rect
		1.0f, //opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		src); //source rect

}

void SpriteSheet::DrawAnimation(float x, float y)
{
	gfx->GetRenderTarget()->DrawBitmap(
		bmp, //bitmap
		D2D1::RectF(x, y, x + spriteWidth, y + bmp->GetSize().height),
		1.0f, //opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF((float)frame * spriteWidth, 0, (float)(frame * spriteWidth + spriteWidth), bmp->GetSize().height) //destination rect //source rect
	);
}