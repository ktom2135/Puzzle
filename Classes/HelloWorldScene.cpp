#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
	
	
    CCSprite* bg = CCSprite::create("Image.png");

	bg->setPosition(ccp(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y));

	CCSize bgSize = bg->getContentSize();
	
	float scaleY =  visibleSize.height/bgSize.height;
	float scaleX = visibleSize.width/bgSize.width;

	bg->setScaleY(scaleY);
	bg->setScaleX(scaleX);
	bg->setOpacity(100);
	CC_SAFE_RETAIN(bg);
	this->addChild(bg,0);
    
	CCSprite* sprite = CCSprite::create("Image.png");

	sprite->setPosition(ccp(visibleSize.width /2 + origin.x, visibleSize.height/2 + origin.y));

	CCSize spriteSize = sprite->getContentSize();
	
	float spriteScaleY =  visibleSize.height/spriteSize .height;
	float spriteScaleX = visibleSize.width/spriteSize .width;

	sprite->setScaleY(spriteScaleY * 0.8);
	sprite->setScaleX(spriteScaleX  * 0.8);
	//this->addChild(sprite,0);
    
	m_dicSplitedImages = CCDictionary::create();
    CC_SAFE_RETAIN(m_dicSplitedImages);

	m_arraySplitedImages = CCArray::create();
	CC_SAFE_RETAIN(m_arraySplitedImages);

	CCSprite *bn = CCSprite::create("Image.png");
	int splitedWidth = bn->getContentSize().width / 4;
	int splitedHeight = bn->getContentSize().height / 4;

	for(int i=0;i< 4;i++)
	{
		for(int j=0;j<4;j++)
		{
			CCSprite * s1 = CCSprite::createWithTexture(bn->getTexture(), CCRectMake(i * splitedWidth , j* splitedHeight, splitedWidth, splitedHeight));
			s1->setPosition(ccp(i* splitedWidth + 100,j* splitedHeight+ 200));
			this->addChild(s1,0);
			//m_dicSplitedImages->setObject(s1, ccp(i* splitedWidth,i* splitedHeight));
		}
	}

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
