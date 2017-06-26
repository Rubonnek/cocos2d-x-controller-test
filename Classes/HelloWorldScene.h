#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void onConnected(Controller* controller, Event* event);
	void onDisconnected(Controller* controller, Event* event);
	void onKeyDown(Controller* controller, int key, Event* event);
	void onKeyUp(Controller* controller, int key, Event* event);
	void onKeyRepeat(Controller* controller, int key, Event* event);
	void onAxisEvent(Controller* controller, int key, Event* event);
};

#endif // __HELLOWORLD_SCENE_H__
