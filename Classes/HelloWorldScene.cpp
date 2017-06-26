#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	// Controller test:

	// Register the callbacks:
	auto onControllerEventListener = EventListenerController::create();
	onControllerEventListener->onConnected = CC_CALLBACK_2(HelloWorld::onConnected,this);
	onControllerEventListener->onDisconnected = CC_CALLBACK_2(HelloWorld::onDisconnected,this);
	onControllerEventListener->onKeyDown = CC_CALLBACK_3(HelloWorld::onKeyDown,this);
	onControllerEventListener->onKeyUp = CC_CALLBACK_3(HelloWorld::onKeyUp,this);
	onControllerEventListener->onKeyRepeat = CC_CALLBACK_3(HelloWorld::onKeyRepeat,this);
	onControllerEventListener->onAxisEvent = CC_CALLBACK_3(HelloWorld::onAxisEvent,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(onControllerEventListener, this);


	// Start discovering controllers
	Controller::startDiscoveryController();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	static bool discovery_was_started = true;

	if ( !discovery_was_started )
	{
		CCLOG("startDiscoveryController");
		Controller::startDiscoveryController();
		discovery_was_started = !discovery_was_started;
	}
	else
	{
		CCLOG("stopDiscoveryController");
		Controller::stopDiscoveryController();
		discovery_was_started = !discovery_was_started;
	}

    //Close the cocos2d-x game scene and quit the application
    //Director::getInstance()->end();

    //#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
	//#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
// Setup the game controller callbacks:
void HelloWorld::onConnected(Controller* controller, Event* event)
{
	CCLOG("Connected controller: %s, With ID: %d", controller->getDeviceName().c_str(), controller->getDeviceId());
}

void HelloWorld::onDisconnected(Controller* controller, Event* event)
{
	CCLOG("Disconnected controller: %s, With ID: %d", controller->getDeviceName().c_str(), controller->getDeviceId());
}

void HelloWorld::onKeyDown(Controller* controller, int key, Event* event)
{
	//Note: event_controller->getKeyCode() == key
	//auto event_controller = static_cast<EventController*>(event);
	CCLOG("Controller: %s, With ID: %d, Pressed key: %d", controller->getDeviceName().c_str(), controller->getDeviceId(), key );

	// Xbox Controller Mappings:
	// Button Key Codes:
	// X = 2
	// Y = 3
	// B = 1
	// A = 0
	// LB = 4
	// RB = 5
	// Dpad-UP = 13
	// Dpad-Right = 12 
	// Dpad-Left = 11
	// Dpad-Down = 14
	// Left stick button press = 9
	// Right stick button press = 10
	// Select = 6
	// Start = 7
	// XBOX button (button between start and 'back') = 8
}

void HelloWorld::onKeyUp(Controller* controller, int key, Event* event)
{
	//auto event_controller = static_cast<EventController*>(event);
	//CCLOG("onKeyUp, Key Code: %d", event_controller->getKeyCode());
}

void HelloWorld::onKeyRepeat(Controller* controller, int key, Event* event)
{
	//auto event_controller = static_cast<EventController*>(event);
	//CCLOG("onKeyRepeat, Key Code: %d", event_controller->getKeyCode());
}

void HelloWorld::onAxisEvent(Controller* controller, int key, Event* event)
{
	//auto event_controller = static_cast<EventController*>(event);
	//CCLOG("Controller: %s, With ID: %d, Axis key: %d, Value: %f", controller->getDeviceName().c_str(), controller->getDeviceId(), key, controller->getKeyStatus(event_controller->getKeyCode()).value);

	// Xbox Controller Mappings:
	// Axes Key Codes:
	// Left stick X axis : 0
	// Left stick Y axis : 1
	// Left stick X axis : 3
	// Left stick Y axis : 4
	// LT: 2
	// RT: 5
}


