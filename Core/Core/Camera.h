#pragma once

#include <d3dx9.h>

class CFPCamera
{
private:
	D3DXVECTOR3 m_position; // �������
	float m_yaw;  //������ y
	float m_pitch; // ������ �
	float m_roll; // ������ z
	D3DXVECTOR3 m_up, m_look, m_right; // ���

	float RestrictAngleTo360Range(float angle) const;
public:
	CFPCamera(D3DXVECTOR3 startPos);
	~CFPCamera(void);

	void CalculateViewMatrix(D3DXMATRIX *viewMatrix);

	float GetYaw() const { return m_yaw; }
	float GetPitch() const { return m_pitch; }
	float GetRoll() const { return m_roll; }
	D3DXVECTOR3 GetPosition() const { return m_position; }

	// ��������
	void MoveForward(float amount) { m_position += m_look*amount; }
	void MoveRight(float amount) { m_position += m_right*amount; }
	void MoveUp(float amount) { m_position += m_up*amount; }

	// �������
	void Yaw(float amount); // ������� �� ��� x
	void Pitch(float amount); // ������� �� ��� y	
	void Roll(float amount); // ������� �� ��� z	
};
