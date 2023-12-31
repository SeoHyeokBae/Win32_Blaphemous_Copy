#pragma once
#include "skGameObject.h"

namespace sk
{
	class Animator;
	class Collider;

	class HitEffect : public GameObject
	{
	public:
		HitEffect();
		virtual ~HitEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void PlayAnimation(eDir dir,bool charge = false);
		void SetActionNum(int num) { _mActionNum = num; }
	private:
		Animator* _mAnimator;
		Collider* _mCollider;
		int _mActionNum;
	};

}


