#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   
    return true;
}

void HelloWorld::ondraw()
{
    Size  s=Director::getInstance()->getWinSize();
    log("%f,%f",s.width,s.height);
	 //绘制直线
    glLineWidth(5.0f);
    DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
    DrawPrimitives::drawLine(Vec2(s.width,0), Vec2(0,s.height));//其实线没完全显示出来，只看到屏幕上显示的一部分。
    DrawPrimitives::drawLine(Vec2(0,s.width), Vec2(s.height,0));
    DrawPrimitives::drawLine(Vec2(100,s.width), Vec2(s.height,100));//其实线没显示出来完
	   
    /*绘制圆,调用函数void drawCircle( const Vec2& center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY)，    圆心，半径，
     宏定义#define CC_DEGREES_TO_RADIANS(__ANGLE__) ((__ANGLE__) * 0.01745329252f) // PI / 180
     converts degrees to radians把度转换成弧度，度数将决定半径的倾斜角度
     unsigned int segments是画出的线的段数，若为3为三角形，若为5则为五边形，10为十边形，越大越接近圆
     bool drawLineToCenter 画线到圆，即是否画半径
     float scaleX, float scaleY是指绘制图形的缩放比例，大于1则放大，小于1则缩小。
     */
    
    glLineWidth(3.0f);
    DrawPrimitives::setDrawColor4B(0, 255, 255, 255);
 //   DrawPrimitives::drawCircle(Vec2(s.width/2, s.height/2), 50, CC_DEGREES_TO_RADIANS(90), 50, true,1, 1);
     DrawPrimitives::drawCircle(Vec2(s.width/2, s.height/2), 50, CC_DEGREES_TO_RADIANS(30), 10, true,2, 2);
    //绘制点 vec2是矢量的点
    Vec2 points[]={Vec2(90, 90),Vec2(110, 110),Vec2(90,110),Vec2(110, 90)};
    DrawPrimitives::setPointSize(10);
    DrawPrimitives::setDrawColor4B(0, 255, 255, 255);
    DrawPrimitives::drawPoints(points, 4);
    
     /*绘制多边形 point是结构体，具有点的属性，x和y坐标
    void drawPoly(const Vec2 *poli, unsigned int numberOfPoints, bool closePolygon)
    */
    DrawPrimitives::setDrawColor4B(255, 0, 255, 255);
    glLineWidth(2);
    Vec2  vertices[]={Point(30,130),Point(30,230),Point(50,200)};
    DrawPrimitives::drawPoly(vertices, 3, true);   //true为封闭图形
    CHECK_GL_ERROR_DEBUG();
    /*绘制贝塞尔曲线vvoid drawQuadBezier(const Vec2& origin, const Vec2& control, const Vec2& destination, unsigned int segments)*/
    DrawPrimitives::drawQuadBezier(Point(0,s.height), Point(s.width/2,s.height/2),Point(s.width,s.height), 50);
    CHECK_GL_ERROR_DEBUG();
    DrawPrimitives::drawCubicBezier(Point(s.width/2,s.height/2), Point(s.width/2+30,s.height/2+50), Point(s.width/2+60,s.height/2-50), Point(s.width,s.height/2), 50);
}
void  HelloWorld::draw(Renderer *render, const Mat4 &transform, uint32_t flags)
    
{
    command.init(_globalZOrder);
    command.func=CC_CALLBACK_0(HelloWorld::ondraw, this);
    render->addCommand(&command);
}

  
