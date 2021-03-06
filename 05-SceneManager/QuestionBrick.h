#pragma once
#include "GameObject.h"

#define QUESTIONBRICK_TYPE_MARK		0

#define QUESTION_BRICK_NORMAL	0
#define QUESTION_BRICK_HIT	1

#define QUESTION_BRICK_ANI_NORMAL	0
#define QUESTION_BRICK_ANI_HIT	1

#define QUESTIONBRICK_SPEED		0.05f
#define QUESTIONBRICK_PUSH_MAX_HEIGHT 8

#define ITEM_COIN_QUESTION_BRICK_COIN	0
#define COIN_ANI_SET_ID 6

#define ITEM_MUSHROOM_RED 3
#define ITEM_MUSHROOM_ANI_SET_ID 37

#define ITEM_SWITCH		6
#define SWITCH_ANI_SET_ID 77

#define ITEM_CUSTOM		1

#define ITEM_LEAF	2
#define LEAF_ANI_SET_ID		36

#define ITEM_MUSHROOM_GREEN 4
#define MUSHROOM_ANI_GREEN_ID	37

class QuestionBrick :public CGameObject
{
	LPGAMEOBJECT item;
	//vector<LPGAMEOBJECT>* items;
	bool isBeingPushedUp = false;
	bool isFallingDown = false;
	int totalItems = 1;
	int tag;
	int type;
public:
	CGameObject* obj = NULL;
	QuestionBrick(int tag = ITEM_COIN_QUESTION_BRICK_COIN, int type = QUESTIONBRICK_TYPE_MARK);

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }

	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetState(int state);
	void CreateItem(int itemType = ITEM_COIN_QUESTION_BRICK_COIN);
	CGameObject* SetUpItem(int itemType);
	void startPushedUp();
	void stopPushedUp();
	LPGAMEOBJECT GetItem() {
		return item;
	}
	~QuestionBrick();
};