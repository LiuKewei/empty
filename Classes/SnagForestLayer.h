#ifndef __SNAGFOREST_LAYER_H__
#define __SNAGFOREST_LAYER_H__

#include "cocos2d.h"
#include "cocos-ext.h"

#include "Ball.h"

const unsigned int c_triSnags = 4;
const float c_radius = 5.0f;
const unsigned int c_heightStart = 420;

struct GameEntry;
class Box2dWorld;
class SnagForestLayer: public cocos2d::CCLayer 
{
public:
	GameEntry*     m_gameEntry;
	Box2dWorld*    m_box2dWorld;
	int            m_entryID;

public:	
	SnagForestLayer();	
	virtual ~SnagForestLayer();	
	//virtual bool init();
	CREATE_FUNC(SnagForestLayer);

	void update(float dt);
	void updateRandSpeed(float dt);
	void tick(float dt);
	void draw();//uses for debug

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	bool SnagForestLayer::initWithEntryID(int entryId);


	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	//virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
private:
	bool isCollidedWithBall(Ball* fallBall, CCSprite *snag);
	void ballLauncherMoving();
	void showCells(Ball* fallBall, unsigned int indexOfCellArr);
	void routeDetection(Ball* fallBall);

	void initMap();
	void initBallLauncher();
	void initSnags();
	void initCell();
	void initSlots();

private:
	Ball* m_ballLauncher;
	Ball* m_upBall;
	CCSize  m_winSize;

	CCArray* m_snagArr;
	CCDictionary* m_cellDic;


	float m_randSpeed;
	float m_upBallAngle;
	float m_winX;

	b2Body* m_removeb;

};
#endif // __SNAGFOREST_LAYER_H__