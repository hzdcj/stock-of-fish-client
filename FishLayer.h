#include"cocos2d.h"
#include"SceneManger.h"
#include"GameLayer.h"
#include"Fish.h"
#include"HRocker.h"
#include"Bubble.h"
#include"ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include"socket/SocketClient.h"
#include"network/SocketIO.h"
using namespace cocos2d::network;
#pragma once
using namespace CocosDenshion;
USING_NS_CC;
using namespace ui;
class Skill;

struct SharkData
{
	Vec2 position;
	float rotation;
	float scale;
};
struct BubbleData
{
	Vec2 position;
	float scale;
	float second;
};
struct LightFishData
{
	Vec2 position;
	float rotation;
	float scale;
	float sunScale;
	bool lightFishCall;
	float bloodPercent;
};
struct FishData
{
	Vec2 position;
	bool Flipx;
};
struct QipaoData
{
	Vec2 position;

};
struct GameData_recv
{
	SharkData sharkData;
	BubbleData bubbleData;
	FishData fishData[30];
	QipaoData qipaoData;
	float bloodPercent;
	int dataSize;
	int erase;
	int _timeLost;
};
struct GameData_send
{
	LightFishData lightFishData;
};
class FishLayer :public GameLayer
{
  public:
	CREATE_FUNC(FishLayer);
	virtual bool init();
	void update(float delata);
    HRocker *rocker;
	Shark *shark;
	Label *label1;
	Label *label2;
	Label *label3;
	Label *label4;
	Label *label5;
	Map<int,Fish*>fish;
	Sprite *_background1;
	Sprite *_background2;
	void lightFishMove();
	Sprite *sharkHead;
	Sprite* sharkBody;
	Sprite *lightFishBody;
    Rect getBoundingBox(Sprite *sprite)const;
	Sprite *cutShark1(Sprite*);
	Sprite* cutShark2(Sprite*);
	Sprite* cutLightFish(Sprite*);
	vector<int>lock;
	Menu *menu;
	Vector<Bubble*>bubble;
	ProgressTimer* progTime;
	int _timeLost;
	static int level;
	LoadingBar *blood;
	LoadingBar *blood_2;
	Size visibleSize;
	int testDirection(Fish*);
	void win();
	void lose();
	void restart(Ref*);
	void nextLevel(Ref*);
	void moveNode(float);
	Sprite *qipao;
	Skill *skill;
	ClippingNode *clipNode;
	LightFish *lightFish;
	static int T;
	void waterWeedsInit();
	static float speed;
	static float rotationSpeed;
	bool lightFishCall;
	void sendData();
	SocketClient *_client;
	void initClient();
	void startSendData(float);
	void onRecv(const char* data, int count);
	void onDisconnect();
	void createBubble(BubbleData bubbleData);
    bool _connected;
	void connectServer(const char *IpAddress);

	SIOClient *_sioClient;
	virtual void onConnect(cocos2d::network::SIOClient* client);
	virtual void onMessage(cocos2d::network::SIOClient* client, const std::string& data);
	virtual void onClose(cocos2d::network::SIOClient* client);
	virtual void onError(cocos2d::network::SIOClient* client, const std::string& data);
	void farDisconnect(cocos2d::network::SIOClient *client, const std::string& data);
	void callConnect(cocos2d::network::SIOClient *client, const std::string& data);
};


