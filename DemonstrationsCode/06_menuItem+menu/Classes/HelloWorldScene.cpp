#include "HelloWorldScene.h"
USING_NS_CC;

//全局变量
Sprite* sprite1;
Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	auto bgSprite=Sprite::create("bg.png");
	bgSprite->setPosition(Vec2(240,160));
	this->addChild(bgSprite,0);

	sprite1=Sprite::create("pig_3.png");
	sprite1->setPosition(Vec2(100,80));
	sprite1->setScale(.3);
	this->addChild(sprite1);

    //1.调用LabelTTF类的create（），用于显示静态标签，渲染速度慢，缺乏灵活性
	//auto label1=LabelTTF::create("LabelTTF::create()", "simheis.ttf",14);
	auto label1=LabelTTF::create();
	label1->setString("LabelTTF::create()");
	label1->setFontName("Marker Felt.ttf");
	label1->setFontSize(14);
	label1->setPosition(Vec2(90,210));
	this->addChild(label1);

	//2.调用Label类的createWithTTF（）和MenuItemLabel
	auto label2=Label::createWithTTF("Label::createWithTTF", "arial.ttf", 14);
    // auto label=Label2::createWithTTF("开关菜单项", "han1.ttf", 20);
    auto itemLabel=MenuItemLabel::create(label2, CC_CALLBACK_1(HelloWorld::callBack1, this));
    itemLabel->setPosition(Vec2(90,180));
	
	//3.测试BMFont标签类
	auto label3=LabelBMFont::create("BMFont","zgy.fnt");
    //auto label3=LabelBMFont::create("BMFont","my.fnt");
    label3->setPosition(Vec2(90,140));
	label3->setColor(ccc3(255,255,0));
	this->addChild(label3);

	//4.测试LabelAtlas
	auto AtlasLabel=LabelAtlas::create("123 test","tuffy_bold_italic-charmap.plist");
	AtlasLabel->setPosition(Vec2(90,80));
	this->addChild(AtlasLabel);

	//5.创建系统原生字体API : createWithSystemFont
	auto lableSystemFont=Label::createWithSystemFont("hello","arial",30);
	lableSystemFont->setPosition(Vec2(90,60));
    this->addChild(lableSystemFont);
	
	//6.使用FontDefinition类定义字体的属性,LabelTTF::createWithFontDefinition
    FontDefinition TextDef;
    TextDef._fontSize = 30;
    TextDef._fontName = std::string("Arial");
    TextDef._fontFillColor = Color3B::RED;
    //定义阴影
    TextDef._shadow._shadowEnabled = true;
    TextDef._shadow._shadowOffset =Size(10,10);
    TextDef._shadow._shadowOpacity = 1.0f;
    TextDef._shadow._shadowBlur = 0.5f;//模糊度
    //定义黑边
    TextDef._stroke._strokeEnabled = true;
    TextDef._stroke._strokeColor = Color3B::BLACK;
    TextDef._stroke._strokeSize = 1.5f;
    
    //label
	LabelTTF* fontShadow = LabelTTF::createWithFontDefinition("Get a First Blood!", TextDef);
    fontShadow->setPosition(Vec2 (140,30));
    this->addChild(fontShadow);
	
	//测试MenuItemImage
    auto playitem=MenuItemImage::create("btn-play-normal.png", "btn-play-selected.png", CC_CALLBACK_1(HelloWorld::callBack1, this));
    playitem->setPosition(Vec2(240,250));
    auto aboutitem=MenuItemImage::create("btn-about-normal.png", "btn-about-selected.png", CC_CALLBACK_1(HelloWorld::callBack1, this));
    aboutitem->setPosition(Vec2(240, 200));    
    auto highItem=MenuItemImage::create("btn-highscores-normal.png", "btn-highscores-selected.png", CC_CALLBACK_1(HelloWorld::callBack1, this));
    highItem->setPosition(Vec2(240,150));
   
	/*测试MenuItemFont 绑定回调函数，
	new callbacks based on C++11
	this指针调用HelloWorldcallBack（），即this->HelloWorld::callBack(Ref *sender) ，
	CC_CALLBACK_1这里的1指要绑定的回调函数的参数个数.*/
    auto itemFont=MenuItemFont::create("Get Helpping", CC_CALLBACK_1(HelloWorld::callBack1, this));
    itemFont->setPosition(Vec2(400,150));
    itemFont->setScale(.5);
    itemFont->setSkewX(30);//斜体字效果 
      
    //测试开关菜单项MenuItemImage---> MenuItemToggle--->Menu,注意NULL
    auto startItem=MenuItemImage::create("play.png","play.png");
    auto stopItem=MenuItemImage::create("pause.png", "pause.png");
    auto itemToggle=MenuItemToggle::createWithCallback(CC_CALLBACK_1(HelloWorld::callBack, this), startItem,stopItem, NULL);
    itemToggle->setPosition(Vec2(50,260));
    itemToggle->setScale(.25);
    //创建菜单Menu对象，#define NULL    0， #define NULL    ((void *)0)
    auto menu=Menu::create(playitem,aboutitem,highItem,itemFont, itemLabel, itemToggle,NULL);
    menu->setPosition(Vec2(0,0));
	// menu->setPosition(Vec2(240,160));
    //menu->setColor(Color3B(200,200,200));//设置菜单的颜色
    this->addChild(menu);
   // menu->setAnchorPoint(Vec2(0.5,0.5));
   // menu->ignoreAnchorPointForPosition(false);//false不忽略
    /*
     1. menu是不能设置背景颜色的，当setColor时只是在有菜单项的地方体现处理颜色效果。
     2. 默认情况下，menu忽略锚点(相当于以左下角为锚点)，而且初始大小为WinSize，位置position在屏幕中间，
	    即使设置锚点，也没有用处。但是可以设置位置和大小。
		此时位置一般需要设置为menu->setPosition(Vec2(0, 0))，
		这样设置各子菜单项的位置时正好项目父节点menu的位置（0，0），
		menu中的子菜单项才能按设置的位置显示到屏幕上。
     3.假如需要重设锚点，我们就需要设置menu->ignoreAnchorPointForPosition(false)
	   和menu->setAnchorPoint(Vec2(0,1))两个属性。这样就把s锚点改为（0，1）了。
     4.当我们给menu设置了menu->alignItemsVertically()和menu->alignItemsVerticallyWithPadding(20)两个属性时，
	    则menu的锚点也被自动改变成了（0.5，0.5），不管我们是否设置各个子菜单的位置，各个子菜单都会在垂直方向上对其且间隔为20像素。
		若不给menu设置位置时，各个子菜单项对齐且显示在屏幕中央。
		若设置menu位置，则必须设为menu->setPosition(Vec2(240,160))，才能使各个子菜单项对齐且显示在屏幕正中央，
		若需要显示在其他位置，则设置menu的位置就可以了。
     5.综上，我们使用时为了使内容显示在想要设置的位置，仅需要设置menu的位置为menu->setPosition(Vec2(0, 0))，各个子菜单项设置到想要的位置即可；当我们不想设置各个子菜单的位置，而想让它们显示在屏幕正中央时，就不要再人为设置锚点，而只需设置menu->ignoreAnchorPointForPosition(false)和menu->setAnchorPoint(Vec2(0,1))这两个属性就可以了,或者再把menu的位置设置在所需的地方。
    */
   
    //menu->alignItemsVertically();
    //menu->alignItemsVerticallyWithPadding(20);
    /*
     
    */
        
    /*
     
    cocos2dx 3.x中主要类的继承关系
     
     1.class CC_DLL Node : public Ref
     2.class CC_DLL Layer : public Node
     3.class HelloWorld : public Layer
     4.class CC_DLL Menu : public Layer
     5.class CC_DLL SpriteBatchNode : public Node, public TextureProtocol
     6.class CC_DLL TextureProtocol : public BlendProtocol
     7.class CC_DLL Label : public SpriteBatchNode, public LabelProtocol
     8.class CC_DLL LabelProtocol
     9.class CC_DLL MenuItemLabel : public MenuItem  //（创建时需要使用label）
     10.class CC_DLL MenuItemFont : public MenuItemLabel
     11.class CC_DLL MenuItemImage : public MenuItemSprite
     12.class CC_DLL MenuItemSprite : public MenuItem
     13.class CC_DLL MenuItemToggle : public MenuItem
     
     */
    
    return true;
}
//Ref *sender,采用自动释放池管理内存的类，
void HelloWorld::callBack(Ref *sender) // 传入一个指针对象
{
    auto toggleItem=dynamic_cast<MenuItemToggle*>(sender);
    if (toggleItem)
    {
        if (toggleItem->getSelectedIndex()==1)
        {
           //颜色布景层的用法
            log("绘制颜色布景层");
            //layercolor 默认忽略锚点，锚点是（0，0）
            auto layerColor=LayerColor::create(Color4B(200,50,0,100), 480, 320);
            
            //考虑锚点
            //layerColor->ignoreAnchorPointForPosition(false);
            layerColor->setPosition(240,160);
            this->addChild(layerColor);
        }
     else if(toggleItem->getSelectedIndex()==0)
        {
        
        }
    }
}

void HelloWorld::callBack1(Ref *sender)
{
	auto moveto=MoveBy::create(2,Vec2(20,0));
	sprite1->runAction(moveto);
}
