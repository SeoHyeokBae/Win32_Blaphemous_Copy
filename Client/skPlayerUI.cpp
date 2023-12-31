#include "skPlayerUI.h"
#include "skTransform.h"
#include "skMonster.h"
#include "skObject.h"
#include "skTimeMgr.h"
#include "skCamera.h"
#include "skResources.h"
#include "skSpriteRenderer.h"
#include "skTexture.h"

namespace sk
{
	PlayerUI::PlayerUI() :
		_mPlayer(nullptr)
		, _mHpBar(nullptr)
		, _mHp(nullptr)
		, _mMp(nullptr)
		, _mFlask1(nullptr)
		, _mFlask2(nullptr)
		, _mTime(0.f)
		, _mState(Player::eState::NONE)
		, _mFlask(2)
	{
	}
	PlayerUI::~PlayerUI()
	{
	}
	void PlayerUI::Initialize()
	{
		Texture* Player_HpBar = Resources::Load<Texture>(L"Player_HpBar", L"..\\Resources\\image\\ui\\Player_HpBar.bmp");
		Texture* Player_Hp = Resources::Load<Texture>(L"Player_HP", L"..\\Resources\\image\\ui\\Player_HP.bmp");
		Texture* Player_Mp = Resources::Load<Texture>(L"Player_Mp", L"..\\Resources\\image\\ui\\Player_Mp.bmp");
		Texture* Full_Flask = Resources::Load<Texture>(L"Full_Flask", L"..\\Resources\\image\\ui\\Full_Flask.bmp");
		Texture* Empty_Flask = Resources::Load<Texture>(L"Empty_Flask", L"..\\Resources\\image\\ui\\Empty_Flask.bmp");

		_mHp = AddComponent<SpriteRenderer>();
		_mHp->SetImage(Player_Hp);		
		_mHp->SetAffectCamera(false);
		_mHp->SetOffset(Vector2(245.f, 53.f));

		_mMp = AddComponent<SpriteRenderer>();
		_mMp->SetImage(Player_Mp);
		_mMp->SetAffectCamera(false);
		_mMp->SetOffset(Vector2(274.f, 75.f));

		_mHpBar = AddComponent<SpriteRenderer>();
		_mHpBar->SetImage(Player_HpBar);
		_mHpBar->SetAffectCamera(false);
		_mHpBar->SetOffset(Vector2(200.f, 85.f));

		_mFlask1 = AddComponent<SpriteRenderer>();
		_mFlask2 = AddComponent<SpriteRenderer>();
		_mFlask1->SetAffectCamera(false);
		_mFlask2->SetAffectCamera(false);
	}
	void PlayerUI::Update()
	{
		GameObject::Update();

		Hp();
		Mp();
		Flask();
	}
	void PlayerUI::Hp()
	{
		float curhpratio = (float)(_mPlayer->GetInfo().Hp / 200.f);
		_mHp->SetUIratio(curhpratio);
	}
	void PlayerUI::Mp()
	{
		float curhpratio = (float)(_mPlayer->GetInfo().Mp / 100.f);
		_mMp->SetUIratio(curhpratio);
	}

	void PlayerUI::Flask()
	{
		if (_mPlayer->GetInfo().Flask == 0)
		{
			_mFlask1->SetImage(Resources::Find<Texture>(L"Empty_Flask"));
			_mFlask1->SetOffset(Vector2(160.f, 115.f));
			_mFlask2->SetImage(Resources::Find<Texture>(L"Empty_Flask"));
			_mFlask2->SetOffset(Vector2(200.f, 115.f));
		}
		else if (_mPlayer->GetInfo().Flask == 1)
		{
			_mFlask1->SetImage(Resources::Find<Texture>(L"Full_Flask"));
			_mFlask1->SetOffset(Vector2(160.f, 115.f));
			_mFlask2->SetImage(Resources::Find<Texture>(L"Empty_Flask"));
			_mFlask2->SetOffset(Vector2(200.f, 115.f));
		}
		else if (_mPlayer->GetInfo().Flask == 2)
		{
			_mFlask1->SetImage(Resources::Find<Texture>(L"Full_Flask"));
			_mFlask1->SetOffset(Vector2(160.f, 115.f));
			_mFlask2->SetImage(Resources::Find<Texture>(L"Full_Flask"));
			_mFlask2->SetOffset(Vector2(200.f, 115.f));
		}
	}

	void PlayerUI::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}