#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

USING_NS_CC;

class ImageSprite : public cocos2d::CCSprite
{
private:
	CCPoint point;
public:
	void setPoint(CCPoint p);
};

#endif