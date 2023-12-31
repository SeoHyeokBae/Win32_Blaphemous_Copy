#include "skTutorialScene.h"
#include "skSpriteRenderer.h"
#include "skObject.h"
#include "skInput.h"
#include "skTexture.h"
#include "skTransform.h"
#include "skResources.h"
#include "skBackGround.h"
#include "skFrontBackGround.h"
#include "skFloor.h"
#include "skCollider.h"
#include "skCollisionMgr.h"
#include "skWall.h"
#include "skLadder.h"
#include "skDownSpace.h"
#include "skPortal.h"
#include "skShieldMan.h"
#include "skLionHead.h"
#include "skSound.h"
#include "skCamera.h"
#include "skTimeMgr.h"


namespace sk
{
	TutorialScene::TutorialScene()
		: _mPlayer(nullptr)
		, _mLImitLeftX(0)
		, _mLimitRightX(1280)
		, _mTime(0.f)
	{
	}
	TutorialScene::~TutorialScene()
	{
	}
	void TutorialScene::Initialize()
	{
		Texture* tutorialbackground = Resources::Load<Texture>(L"tutorialbackground", L"..\\Resources\\image\\Scene02\\tutorialbackground.bmp");

		BackGround* back_bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* back_sr = back_bg->AddComponent<SpriteRenderer>();
		back_sr->SetImage(tutorialbackground);
		back_sr->SetScale(Vector2(2.f, 2.f));
		back_bg->GetComponent<Transform>()->SetPosition(Vector2(1030.f, 360.f));
		back_sr->SetCameraRatio(Vector2(2.5f, 2.5f));



		Texture* tutorialMiddle2 = Resources::Load<Texture>(L"tutorialMiddle2", L"..\\Resources\\image\\Scene02\\middle2.bmp");

		BackGround* StageMiddle_bg1 = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* StageMiddle_sr1 = StageMiddle_bg1->AddComponent<SpriteRenderer>();
		StageMiddle_sr1->SetImage(tutorialMiddle2);
		StageMiddle_sr1->SetScale(Vector2(2.f, 2.f));
		StageMiddle_bg1->GetComponent<Transform>()->SetPosition(Vector2(1600.f, 360.f));
		StageMiddle_sr1->SetCameraRatio(Vector2(1.1f, 1.1f));

		Texture* tutorialMiddle1 = Resources::Load<Texture>(L"tutorialMiddle1", L"..\\Resources\\image\\Scene02\\middle1.bmp");

		BackGround* StageMiddle_bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* StageMiddle_sr = StageMiddle_bg->AddComponent<SpriteRenderer>();
		StageMiddle_sr->SetImage(tutorialMiddle1);
		StageMiddle_sr->SetScale(Vector2(2.f, 2.f));
		StageMiddle_bg->GetComponent<Transform>()->SetPosition(Vector2(1650.f, 360.f));
		StageMiddle_sr->SetCameraRatio(Vector2(1.2f, 1.2f));

		// 타일 이미지
		Texture* Background = Resources::Load<Texture>(L"TutorialBackground", L"..\\Resources\\image\\Scene02\\scene2bg.bmp");

		BackGround* bg = object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Background);
		bgsr->SetScale(Vector2(2.f, 2.f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(1715.f,360.f));
		//bgsr->SetAffectCamera(true);

		// 카메라 제한거리
		_mLImitLeftX = bg->GetComponent<Transform>()->GetPosition().x - Background->GetWidth();
		_mLimitRightX = bg->GetComponent<Transform>()->GetPosition().x + Background->GetWidth();

		// 앞 이미지
		Texture* frontBackground = Resources::Load<Texture>(L"frontBackground", L"..\\Resources\\image\\Scene02\\scene2fbg.bmp");

		FrontBackGround* fbg = object::Instantiate<FrontBackGround>(eLayerType::FrontBackground);
		SpriteRenderer* fbgsr = fbg->AddComponent<SpriteRenderer>();
		fbgsr->SetImage(frontBackground);
		fbgsr->SetScale(Vector2(2.f, 2.f));
		fbg->GetComponent<Transform>()->SetPosition(Vector2(1715.f, 360.f));
		//fbgsr->SetAffectCamera(true);

		// Player
		Player* player = object::Instantiate<Player>(eLayerType::Player);
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(130.0f, 300.0f));
		//player->GetComponent<Animator>()->SetAffectedCamera(true);
		_mPlayer = player;

		// Monster
		ShieldMan* shieldman1 = object::Instantiate<ShieldMan>(eLayerType::Monster);
		tr = shieldman1->GetComponent<Transform>();	
		tr->SetPosition(Vector2(300.f, 450.f));

		LionHead* lionhead = object::Instantiate<LionHead>(eLayerType::Monster);
		tr = lionhead->GetComponent<Transform>();
		tr->SetPosition(Vector2(1424.f, 450.f));



		//Floor
		Floor* floor1 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor1 = floor1->AddComponent<Collider>();
		colfloor1->SetSize(Vector2(760.0f, 50.0f));
		Transform* floortr1 = floor1->GetComponent<Transform>();
		floortr1->SetPosition(Vector2(390.0f, 515.0f));

		Floor* floor2 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor2 = floor2->AddComponent<Collider>();
		colfloor2->SetSize(Vector2(240.0f, 50.0f));
		Transform* floortr2 = floor2->GetComponent<Transform>();
		floortr2->SetPosition(Vector2(910.0f,380.0f));

		Floor* floor3 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor3 = floor3->AddComponent<Collider>();
		colfloor3->SetSize(Vector2(460.0f, 50.0f));
		Transform* floortr3 = floor3->GetComponent<Transform>();
		floortr3->SetPosition(Vector2(1265.f, 250.0f));

		Floor* floor4 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor4 = floor4->AddComponent<Collider>();
		colfloor4->SetSize(Vector2(760.0f, 50.0f));
		Transform* floortr4 = floor4->GetComponent<Transform>();
		floortr4->SetPosition(Vector2(1700.f, 634.0f));

		Floor* floor5 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor5 = floor5->AddComponent<Collider>();
		colfloor5->SetSize(Vector2(1000.0f, 50.0f));
		Transform* floortr5 = floor5->GetComponent<Transform>();
		floortr5->SetPosition(Vector2(2450.f, 250.0f));

		Floor* floor6 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor6 = floor6->AddComponent<Collider>();
		colfloor6->SetSize(Vector2(120.0f, 30.0f));
		Transform* floortr6 = floor6->GetComponent<Transform>();
		floortr6->SetPosition(Vector2(2890.f, 395.0f));

		Floor* floor7 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor7 = floor7->AddComponent<Collider>();
		colfloor7->SetSize(Vector2(250.0f, 50.0f));
		Transform* floortr7 = floor7->GetComponent<Transform>();
		floortr7->SetPosition(Vector2(2540.f, 515.0f));

		Floor* floor8 = object::Instantiate<Floor>(eLayerType::Floor);
		Collider* colfloor8 = floor8->AddComponent<Collider>();
		colfloor8->SetSize(Vector2(760.0f, 50.0f));
		Transform* floortr8 = floor8->GetComponent<Transform>();
		floortr8->SetPosition(Vector2(3050.f, 640.0f));

		///////////////// Wall
		Wall* wall_left = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwallL = wall_left->AddComponent<Collider>();
		colwallL->SetSize(Vector2(50.0f, 600.0f));
		Transform* wltr = wall_left->GetComponent<Transform>();
		wltr->SetPosition(Vector2(_mLImitLeftX, 360.0f));

		Wall* wall_right = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwallR = wall_right->AddComponent<Collider>();
		colwallR->SetSize(Vector2(50.0f, 600.0f));
		Transform* wrtr = wall_right->GetComponent<Transform>();
		wrtr->SetPosition(Vector2(_mLimitRightX, 360.0f));
		wall_right->SetRight(false);

		Wall* wall1 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall1 = wall1->AddComponent<Collider>();
		colwall1->SetSize(Vector2(25.0f, 170.0f));
		tr = wall1->GetComponent<Transform>();
		tr->SetPosition(Vector2(790.f, 445.0f));
		wall1->SetRight(false);

		Wall* wall2 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall2 = wall2->AddComponent<Collider>();
		colwall2->SetSize(Vector2(25.0f, 170.0f));
		tr = wall2->GetComponent<Transform>();
		tr->SetPosition(Vector2(1040.f, 315.0f));
		wall2->SetRight(false);

		Wall* wall3 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall3 = wall3->AddComponent<Collider>();
		colwall3->SetSize(Vector2(40.0f, 400.0f));
		tr = wall3->GetComponent<Transform>();
		tr->SetPosition(Vector2(1300.f, 470.0f));

		Wall* wall4 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall4 = wall4->AddComponent<Collider>();
		colwall4->SetSize(Vector2(40.0f, 400.0f));
		tr = wall4->GetComponent<Transform>();
		tr->SetPosition(Vector2(2120.f, 470.0f));
		wall4->SetRight(false);

		Wall* wall5 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall5 = wall5->AddComponent<Collider>();
		colwall5->SetSize(Vector2(40.0f, 320.0f));
		tr = wall5->GetComponent<Transform>();
		tr->SetPosition(Vector2(2400.f, 410.0f));

		Wall* wall6 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall6 = wall6->AddComponent<Collider>();
		colwall6->SetSize(Vector2(40.0f, 160.0f));
		tr = wall6->GetComponent<Transform>();
		tr->SetPosition(Vector2(2650.f, 580.0f));

		Wall* wall7 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall7 = wall7->AddComponent<Collider>();
		colwall7->SetSize(Vector2(40.0f, 550.0f));
		tr = wall7->GetComponent<Transform>();
		tr->SetPosition(Vector2(2961.f, 260.0f));
		wall7->SetRight(false);

		Wall* wall8 = object::Instantiate<Wall>(eLayerType::Wall);
		Collider* colwall8 = wall8->AddComponent<Collider>();
		colwall8->SetSize(Vector2(40.0f, 550.0f));
		tr = wall8->GetComponent<Transform>();
		tr->SetPosition(Vector2(3039.f, 260.0f));
		
		// Ladder
		Ladder* ladder1 = object::Instantiate<Ladder>(eLayerType::Ladder);
		Collider* ladercol = ladder1->AddComponent<Collider>();
		ladercol->SetNotColColor(RGB(255, 255, 50));
		ladercol->SetSize(Vector2(40.0f, 400.0f));
		tr = ladder1->GetComponent<Transform>();
		tr->SetPosition(Vector2(1424.0f, 420.0f));

		Ladder* ladder2 = object::Instantiate<Ladder>(eLayerType::Ladder);
		Collider* ladercol2 = ladder2->AddComponent<Collider>();
		ladercol2->SetNotColColor(RGB(255, 255, 50));
		ladercol2->SetSize(Vector2(40.0f, 400.0f));
		tr = ladder2->GetComponent<Transform>();
		tr->SetPosition(Vector2(1998.0f, 420.0f));

		// DownSpace
		DownSpace* DownSpace1 = object::Instantiate<DownSpace>(eLayerType::DownSpace);
		Collider* downcol1 = DownSpace1->AddComponent<Collider>();
		downcol1->SetNotColColor(RGB(184, 223, 258));
		downcol1->SetSize(Vector2(500.0f, 50.0f));
		tr = DownSpace1->GetComponent<Transform>();
		tr->SetPosition(Vector2(2700.f, 250.0f));

		// Portal
		Portal* portal2 = object::Instantiate<Portal>(eLayerType::Portal);
		Collider* colportal2 = portal2->AddComponent<Collider>();
		colportal2->SetNotColColor(RGB(50, 50, 255));
		colportal2->SetSize(Vector2(70.0f, 350.0f));
		tr = portal2->GetComponent<Transform>();
		colportal2->SetOffset(Vector2(0.f, -30.f));
		tr->SetPosition(Vector2(_mLimitRightX-25.0f , 525.0f));

		// 충돌 체크
		CollisionMgr::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Player, eLayerType::Wall, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Player, eLayerType::DownSpace, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Player, eLayerType::Ladder, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Attack, eLayerType::Monster, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Monster, eLayerType::Floor, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Monster, eLayerType::Wall, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::Monster, eLayerType::Npc, true);
		CollisionMgr::CollisionLayerCheck(eLayerType::MonsAtt, eLayerType::Player, true);
		
		//Sound
		Resources::Load<Sound>(L"tutorialSceneBgm", L"..\\Resources\\sound\\Brotherhood_Ambient.wav");

	}
	void TutorialScene::SceneEnter()
	{
		Camera::SetTarget(_mPlayer);
		Camera::SetPlayMode(true);

		Camera::SetCameraLimit_Left(_mLImitLeftX);
		Camera::SetCameraLimit_Right(_mLimitRightX);
		Resources::Find<Sound>(L"tutorialSceneBgm")->Play(true);
		Resources::Find<Sound>(L"tutorialSceneBgm")->SetVolume(10);
	}
	void TutorialScene::SceneOut()
	{
		Camera::SetTarget(nullptr);
		Camera::SetPlayMode(false);
		Resources::Find<Sound>(L"tutorialSceneBgm")->Stop(true);
	}
	void TutorialScene::Update()
	{
		Scene::Update();

		if (_mPlayer->GetGameObjState() == GameObject::eState::Pause) // 처형에니메이션후 재생
		{
			_mTime += TimeMgr::DeltaTime();
			if (_mTime >= 3.4f)
			{
				_mPlayer->Active();
			}
		}


		if (Input::GetKeyUp(eKeyCode::N))
		{
			SceneMgr::LoadScene(L"TutorialScene");
		}

		if (Input::GetKeyUp(eKeyCode::M))
		{
			SceneMgr::LoadScene(L"FirstBossScene");
		}

	}
	void TutorialScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}
