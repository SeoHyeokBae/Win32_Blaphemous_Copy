#include "skSkillBook.h"
#include "skResources.h"
#include "skSpriteRenderer.h"
#include "skInput.h"
#include "skNpcDeosgracias.h"
#include "skPlayer.h"
#include "skSound.h"


namespace sk
{
	SkillBook::SkillBook()
		: _mCount(0)
	{
	}
	SkillBook::~SkillBook()
	{
	}
	void SkillBook::Initialize()
	{
		Texture* SkillBook = Resources::Load<Texture>(L"SkillBook", L"..\\Resources\\image\\npc\\skillbook.bmp");
		Texture* SkillBook2 = Resources::Load<Texture>(L"SkillBook2", L"..\\Resources\\image\\npc\\skillbook2.bmp");
		Texture* SkillBook3 = Resources::Load<Texture>(L"SkillBook3", L"..\\Resources\\image\\npc\\skillbook3.bmp");
		SpriteRenderer* sr = AddComponent<SpriteRenderer>();
		sr->SetAffectCamera(false);
		sr->SetScale(Vector2(2.0f, 2.0f));

		Resources::Load<Sound>(L"USE_QUEST_ITEM", L"..\\Resources\\sound\\USE_QUEST_ITEM.wav");

	}
	void SkillBook::Update()
	{
		GameObject::Update();
		if (_mCount== 0)
		{
			GetComponent<SpriteRenderer>()->SetImage(Resources::Find<Texture>(L"SkillBook"));
		}
		else if (_mCount == 1)
		{
			GetComponent<SpriteRenderer>()->SetImage(Resources::Find<Texture>(L"SkillBook2"));

		}
		else if (_mCount == 2)
		{
			GetComponent<SpriteRenderer>()->SetImage(Resources::Find<Texture>(L"SkillBook3"));
		}

		if (Input::GetKeyDown(eKeyCode::D))
		{
			if (_mCount == 0)
				_mCount = 1;
			else if (_mCount == 1)
				_mCount = 2;
			else if (_mCount == 2)
				_mCount = 0;
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			if (_mCount == 0)
				_mCount = 2;
			else if (_mCount == 1)
				_mCount = 0;
			else if (_mCount == 2)
				_mCount = 1;
		}


		if (Input::GetKeyDown(eKeyCode::K))
		{
			//TODO
			Resources::Find<Sound>(L"USE_QUEST_ITEM")->Play(false);
			Resources::Find<Sound>(L"USE_QUEST_ITEM")->SetVolume(15);
			Player::SetCharge(true);
			NpcDeosgracias::SetCanActive(true);
			Destroy(this);
		}
	}
	void SkillBook::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}